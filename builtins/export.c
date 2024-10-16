/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferafano <ferafano@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:02:32 by ferafano          #+#    #+#             */
/*   Updated: 2024/10/10 07:38:34 by ferafano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildin.h"

int	create_or_not(char *name, char **env)
{
	int	len;
	int	i;

	len = ft_strlen(name);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], name, len) == 0 && env[i][len] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	**create_new_env(char *name, char **env)
{
	int		len;
	int		i;
	char	**copy;

	len = 0;
	i = 0;
	while (env && env[len])
		len++;
	copy = malloc((len + 2) * sizeof(char *));
	if (copy == NULL)
		return (NULL);
	while (i < len)
	{
		copy[i] = ft_strdup(env[i]);
		i++;
	}
	copy[len] = ft_strdup(name);
	copy[len + 1] = NULL;
	return (copy);
}

int	check_if_exist(char *name, char **env)
{
	int		i;
	int		len;
	char	*exist_sign;

	exist_sign = ft_strchr(name, '=');
	len = ft_len(name, exist_sign);
	i = 0;
	while (env && env[i])
	{
		if (ft_strncmp(env[i], name, len) == 0 && (env[i][len] == '='
			|| env[i][len] == '\0'))
		{
			if (exist_sign)
				ft_reassign(name, &env[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_cond(int i, char ***env, char **argv, char **temp)
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

int	ft_export(char **argv, char ***env, int fd)
{
	int		i;
	int		status;
	char	**temp;
	int		check;

	i = 1;
	status = 0;
	temp = NULL;
	if (argv[i] == NULL)
		print_export(*env, fd);
	while (argv[i])
	{
		check = check_valid_name(argv[i], env);
		if (check == 1)
			ft_cond(i, env, argv, temp);
		else if (check == 0)
			;
		else
		{
			printf("invalid identifier\n");
			status = 1;
		}
		i++;
	}
	return (status);
}
