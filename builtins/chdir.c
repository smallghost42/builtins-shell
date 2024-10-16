/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferafano <ferafano@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 08:05:44 by ferafano          #+#    #+#             */
/*   Updated: 2024/10/14 10:51:07 by ferafano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildin.h"

int	this_func(t_oldpwd *var, char **copy_env, char *cwd)
{
	var->new_value = malloc((var->len + 2 + ft_strlen(cwd) + 1) * sizeof(char));
	if (var->new_value == NULL)
		return (0);
	copy_env[var->i] = ft_strjoin(copy_env[var->i], "=");
	ft_strncpy(var->new_value, copy_env[var->i], var->len + 2);
	ft_strcpy(var->new_value + var->len + 1, cwd);
	copy_env[var->i] = var->new_value;
	return (1);
}

int	that_func(t_oldpwd *var, char **copy_env, char *cwd)
{
	var->new_value = malloc((var->len + 1 + ft_strlen(cwd) + 1) * sizeof(char));
	if (var->new_value == NULL)
		return (0);
	ft_strncpy(var->new_value, copy_env[var->i], var->len + 1);
	ft_strcpy(var->new_value + var->len + 1, cwd);
	copy_env[var->i] = var->new_value;
	return (1);
}

void	update_oldpwd(char *line_read, char *cwd, char **copy_env)
{
	t_oldpwd	var;

	var.len = 0;
	while (line_read[var.len] && line_read[var.len] != '=')
		var.len++;
	var.i = 0;
	while (copy_env[var.i])
	{
		if (ft_strncmp(copy_env[var.i], line_read, var.len) == 0
			&& (copy_env[var.i][var.len] == '='
				|| copy_env[var.i][var.len] == '\0'))
		{
			if (copy_env[var.i][var.len] == '\0')
			{
				if (this_func(&var, copy_env, cwd) == 0)
					return ;
			}
			else if (that_func(&var, copy_env, cwd) == 0)
				return ;
			break ;
		}
		var.i++;
	}
}

int	change_to_path(char *path, char *cwd, char **copy_env)
{
	char	*home;

	home = get_env_value("HOME", copy_env);
	if (path[0] == '~' && (path[1] == '\0' || (path[1] == '/'
				&& path[2] == '\0')))
	{
		if (change_to_home(cwd, copy_env, home) == 1)
			return (1);
	}
	else if (path[0] == '~')
	{
		if (!chdir(home))
		{
			perror("cd");
			return (1);
		}
		if (chdir(path + 2) == 0)
			update_oldpwd("OLDPWD", cwd, copy_env);
		else
		{
			chdir(cwd);
			perror("cd");
			return (1);
		}
	}
	else if (chdir(path) == 0)
		;
	else
	{
		perror("cd");
		return (1);
	}
	return (0);
}

int	ft_cd(char **argv, char **copy_env)
{
	int		status;
	char	cwd[4096];

	status = 0;
	getcwd(cwd, sizeof(cwd));
	if (argv[1] == NULL)
		change_to_home(cwd, copy_env, home);
	else if (argv[1] != NULL && argv[2] != NULL)
	{
		status = 1;
		write(2, "too many arguments\n", 19);
	}
	else if (argv[1] && argv[1][0] == '-' && argv[1][1] == '\0')
		status = change_to_oldpwd(cwd, copy_env);
	else
	{
		status = change_to_path(argv[1], cwd, copy_env);
		update_oldpwd("OLDPWD", cwd, copy_env);
	}
	write(1, "\n", 1);
	getcwd(cwd, sizeof(cwd));
	update_oldpwd("PWD", cwd, copy_env);
	return (status);
}
