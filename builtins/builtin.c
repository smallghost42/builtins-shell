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

int ft_echo(char **argv, int fd)
{
    int i;
    int nl;

	i = 1;
	nl = 1;
    while (argv[i] && argv[i][0] == '-' && argv[i][1] == 'n' && argv[i][2] == '\0')
    {
        nl = 0;
        i++;
    }
    while (argv[i])
    {
		ft_putstr_fd(argv[i], fd);
        if (argv[i + 1])
            ft_putchar_fd(' ', fd);
        i++;
    }
    if (nl)
        ft_putchar_fd('\n', fd);
    return 0;
}

int	ft_exit(char **argv)
{
	if (argv[1] && argv[2] != NULL)
	{
		write(2, "exit: too many arguments\n", 24);
		return (1);
	}
	else
		exit(0);
	return (0);
}

int	buildin(char **argv, char ***copy_env, int fd)
{
	int	status;

	status = 0;
	if (strcmp(argv[0], "cd") == 0)
		status = ft_cd(argv, *copy_env);
	else if (strcmp(argv[0], "pwd") == 0)
		status = ft_pwd(argv, fd);
	else if (strcmp(argv[0], "env") == 0)
		status = ft_env(*copy_env, argv, fd);
	else if (strcmp(argv[0], "unset") == 0)
		status = ft_unset(argv, &*copy_env);
	else if (strcmp(argv[0], "export") == 0)
		status = ft_export(argv, &*copy_env, fd);
	else if (strcmp(argv[0], "echo") == 0)
		status = ft_echo(argv, fd);
	else if (strcmp(argv[0], "get_env") == 0)
		status = get_env_value(argv, *copy_env);
	else if (strcmp(argv[0], "exit") == 0)
		status = ft_exit(argv);
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
		int fd = open("test", O_RDWR | O_TRUNC);
		buildin(args, &copy_env, fd);
	}
	for (int i = 0; copy_env[i]; i++)
		free(copy_env[i]);
	free(copy_env);
	return (0);
}
