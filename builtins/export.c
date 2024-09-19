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

int check_valid_name(char *name)
{
    int i;

	i = 0;
    if ((!isalpha(name[0]) && name[0] != '_'))
        return (0);
    while (name[++i] && name[i] != '=')
	{
        if ((!isalnum(name[i]) && name[i] != '_'))
            return (0);
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

    i = 1;
	status = 0;
	if (argv[i] == NULL)
		print_export(*env);
    while (argv[i])
    {
        if (check_valid_name(argv[i]))
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
        else
            printf("invalid identifier\n");
        i++;
    }
	return (status);
}

