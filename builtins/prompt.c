/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferafano <ferafano@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:13:08 by ferafano          #+#    #+#             */
/*   Updated: 2024/09/09 13:27:34 by ferafano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildin.h"
#include <string.h>
#include <unistd.h>

void pwd_prompt(char *path)
{
    const char *blue = "\033[0;33m";
    const char *reset = "\033[0m";
    char cwd[4096];
    const char *home;
	int home_len;

	home = "/home/ferafano";
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

void ft_pwd(char *path)
{
	char	pwd[1024];
	int		i;

	if (chdir(path) != 0)
	{
 		i = 0;
        getcwd(pwd, sizeof(pwd)); 
		while (pwd[i])
		{	
			write(1, &pwd[i], 1);
			i++;
		}
    }
	else
        perror("cd");
	write (1, "\n", 1);
}
