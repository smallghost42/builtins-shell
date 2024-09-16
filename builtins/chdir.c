/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferafano <ferafano@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 08:05:44 by ferafano          #+#    #+#             */
/*   Updated: 2024/09/13 08:58:13 by ferafano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildin.h"

int	is_match(char *line_read, char **copy_env)
{
	int	i;
	int	j;
	int	success;

	success = 0;
	i = 0;
	while (copy_env[i])
	{
		if (copy_env[i][0] == line_read[0])
		{
			j = 1;
			success = 1;
			while (line_read[j])
			{
				if (copy_env[i][j] != line_read[j])
					break ;
				j++;
			}
			if (success)
				return (i);
		}
		i++;
	}
	return (-1);
}

void	update_oldpwd(char *line_read, char *cwd, char **copy_env)
{
	int		i;
	int		j;
	int		len;
	char	*new_value;

	len = 0;
	while (line_read[len] && line_read[len] != '=')
		len++;
	i = 0;
	while (copy_env[i])
	{
		if (strncmp(copy_env[i], line_read, len) == 0
			&& copy_env[i][len] == '=')
		{
			new_value = malloc((len + 1 + strlen(cwd) + 1) * sizeof(char));
			if (new_value == NULL)
				return ;
			strncpy(new_value, copy_env[i], len + 1);
			strcpy(new_value + len + 1, cwd);
			copy_env[i] = new_value;
			break ;
		}
		i++;
	}
}

int	change_to_path(char *path, char *cwd, char **copy_env)
{
	int status;

	status = 0;
	if (path[0] == '~' && path[1] == '\0')
		change_to_home(cwd, copy_env);
	else if (path[0] == '~')
	{
		chdir("/home/ferafano/");
		if (chdir(path + 2) == 0)
			update_oldpwd("OLDPWD", cwd, copy_env);
		else
		{
			chdir(cwd);
			perror("cd1");
			status = 1;
		}
	}
	else if (chdir(path) == 0)
		;
	else
	{
		perror("cd");
		status = 1;
	}
	return (status);
}

int	ft_cd(char **argv, char **copy_env)
{
	int		status;
	char	cwd[4096];

	status = 0;
	getcwd(cwd, sizeof(cwd));
	if (argv[1] == NULL)
		change_to_home(cwd, copy_env);
	else if (argv[1] == NULL && argv[2] == NULL)
	{
		status = 1;
		write (2, "too many arguments\n", 19);
	}
	else if (argv[1] && argv[1][0] == '-' && argv[1][1] == '\0')
		status = change_to_oldpwd(cwd, copy_env);
	else
		status = change_to_path(argv[1], cwd, copy_env);
	write(1, "\n", 1);
	return (status);
}
