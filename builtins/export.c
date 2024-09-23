/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferafano <ferafano@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:02:32 by ferafano          #+#    #+#             */
/*   Updated: 2024/09/09 09:09:44 by ferafano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildin.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = strlen(s1) + strlen(s2);
	new = malloc(len + 1);
	if (new == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

int ft_exist_status(char *name, char **env)
{
    int i;
    int len;
    char *exist_sign;
	char *temp;

	temp = NULL;
	exist_sign = strchr(name, '=');
    len = exist_sign ? exist_sign - name : strlen(name);
    i = 0;
    while (env && env[i])
    {
        if (strncmp(env[i], name, len - 1) == 0 && (env[i][len - 1] == '=' || env[i][len] == '\0'))
        {
            if (exist_sign)
			{
				if (env[i][len] == '\0' && env[i][len - 1] != '=')
				{
					temp = env[i];
					env[i] = ft_strjoin(temp, exist_sign);
				}
				else
				{
					temp = env[i];
					env[i] = ft_strjoin(temp, exist_sign + 1);
				}
				return (2);
			}
        }
        i++;
    }
    return (0);
}

char **create_no_plus(char *name, char **env)
{
    int len;
    int i;
	int j;
    char **copy;
	char *name1;

    len = 0;
    i = 0;
    while (env && env[len])
        len++;
    copy = malloc((len + 2) * sizeof(char *));
    if (copy == NULL)
        return NULL;
    while (i < len)
    {
        copy[i] = strdup(env[i]);
        i++;
    }
	name1 = malloc((strlen(name)) * sizeof(char));
	i = 0;
	j = 0;
	while (name[i])
	{
		if (name[i] == '+')
			i++;
		name1[j] = name[i];
		j++;
		i++;
	}
	name1[j] = '\0';
    copy[len] = strdup(name1);
	free(name1);
    copy[len + 1] = NULL;
	return (copy);
}

int ft_concat(char *name, char ***env)
{
	int status;
	char **temp;

	status = 0;
	temp = NULL;
	if (ft_exist_status(name, *env) == 2)
		status = 0;
	else
	{
		temp = *env;
		*env = create_no_plus(name, temp);
	}
	return (status);
}

int check_valid_name(char *name, char ***env)
{
    int i;
	int status;

	i = 0;
    if ((!isalpha(name[0]) && name[0] != '_'))
        return (-1);
    while (name[++i] && name[i] != '=')
	{
		if (name[i + 1] && name[i] == '+' && name[i + 1] == '=')
		{
			status = ft_concat(name, env);
			return (0);
		}
        if ((!isalnum(name[i]) && name[i] != '_'))
            return (-1);
    }
    return (1);
}

void ft_reassign(char *name, char **to_assign)
{
    free(*to_assign);
    *to_assign = strdup(name);
}

int create_or_not(char *name, char **env)
{
    int len;
    int i;

    len = strlen(name);
    i = 0;
    while (env[i])
    {
        if (strncmp(env[i], name, len) == 0 && env[i][len] == '\0')
            return (1);
        i++;
    }
    return (0);
}

char **create_new_env(char *name, char **env)
{
    int len;
    int i;
    char **copy;

    len = 0;
    i = 0;
    while (env && env[len])
        len++;
    copy = malloc((len + 2) * sizeof(char *));
    if (copy == NULL)
        return NULL;
    while (i < len)
    {
        copy[i] = strdup(env[i]);
        i++;
    }
    copy[len] = strdup(name);
    copy[len + 1] = NULL;
	return (copy);
}

int check_if_exist(char *name, char **env)
{
    int i;
    int len;
    char *exist_sign;

	exist_sign = strchr(name, '=');
    len = exist_sign ? exist_sign - name : strlen(name);
    i = 0;
    while (env && env[i])
    {
        if (strncmp(env[i], name, len) == 0 && (env[i][len] == '=' || env[i][len] == '\0'))
        {
            if (exist_sign)
                ft_reassign(name, &env[i]);
            return (1);
        }
        i++;
    }
    return (0);
}

int ft_export(char **argv, char ***env)
{
    int		i;
	int		status;
	char	**temp;
	int		check; 

    i = 1;
	status = 0;
	if (argv[i] == NULL)
		print_export(*env);
    while (argv[i])
    {
		check = check_valid_name(argv[i], env);
		if (check == 1)
        {
            if (!check_if_exist(argv[i], *env))
            {
                if (create_or_not(argv[i], *env) == 0)
				{
					temp = *env;
                    *env = create_new_env(argv[i], temp);
				}
            }
        }
		else if (check == 0)
			return (0);
		else
            printf("invalid identifier\n");
        i++;
    }
	return (status);
}

