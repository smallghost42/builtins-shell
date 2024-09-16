/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferafano <ferafano@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 08:53:49 by ferafano          #+#    #+#             */
/*   Updated: 2024/09/16 15:18:23 by ferafano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildin.h"

void	ft_echo(char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		write(1, &message[i], 1);
		i++;
	}
	printf("\n");
}

int buildin(char **argv, char **copy_env)
{
	int status;

	status = 0;
	//printf(" %s | %s | %s\n", argv[0], argv[1], argv[2]);
	if (strcmp(argv[0], "cd") == 0)
		status = ft_cd(argv, copy_env);
	else if (strcmp(argv[0], "pwd") == 0)
		status = ft_pwd(argv);
	else if (strcmp(argv[0], "env") == 0)
		status = ft_env(copy_env, argv);
	/*else if (strcmp(argv[0], "unset"))
		status = ft_unset();
	else if (strcmp(argv[0], "export"))
		status = ft_export();
	else if (strcmp(argv[0], "echo"))
		status = ft_echo();
	else if (strcmp(argv[0], "exit"))
		exit(1);*/
	else
	{
		printf("not a building | cmd : %s | args : %s\n", argv[0], argv[1]);
		status = 1;
	}
	printf("status : %d \n", status);
	return (status);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*line_read;
	char	**copy_env;
	char	**args;

	(void)argc;
	(void)argv;
	line_read = NULL;
	copy_env = ft_copy_env(envp);
	args = malloc(sizeof(char *));
	while (1)
	{
		if (line_read)
		{
			free(line_read);
			line_read = NULL;
		}
		pwd_prompt("pwd");
		line_read = readline("\n\033[0;35m❯ \033[0m");
		add_history(line_read);
		args = ft_split(line_read, ' ');
		buildin(args, copy_env);
	}
	for (int i = 0; copy_env[i]; i++)
		free(copy_env[i]);
	free(copy_env);
	return (0);
}
