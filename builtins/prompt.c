/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferafano <ferafano@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:13:08 by ferafano          #+#    #+#             */
/*   Updated: 2024/09/16 15:18:09 by ferafano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildin.h"

void	pwd_prompt(char *path)
{
	const char	*blue;
	const char	*reset;
	char		cwd[4096];
	const char	*home;
	int			home_len;

	blue = "\033[0;33m";
	home = "/home/ferafano";
	reset = "\033[0m";
	home_len = strlen(home);
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		write(1, blue, strlen(blue));
		if (strncmp(cwd, home, home_len) == 0)
		{
			write(1, "~", 1);
			write(1, cwd + home_len, strlen(cwd) - home_len);
		}
		else
			write(1, cwd, strlen(cwd));
		write(1, reset, strlen(reset));
	}
	else
		perror("getcwd");
}

int	ft_pwd(char **path)
{
	char	pwd[1024];
	int		i;

	i = 0;
	getcwd(pwd, sizeof(pwd));
	while (pwd[i])
	{
		write(1, &pwd[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
