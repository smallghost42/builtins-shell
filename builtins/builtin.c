/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferafano <ferafano@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 08:53:49 by ferafano          #+#    #+#             */
/*   Updated: 2024/09/09 13:05:55 by ferafano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildin.h"

void ft_echo(char *message)
{
	int i;

	i = 0;
    while (message[i])
	{
		write(1, &message[i], 1);
		i++;
	}
	printf("\n");
}

void	ft_cd(char *path)
{
	if (chdir(path) == 0)
		;
	else if (path[0] == '~' && path[1] == '\0')
		chdir("/home/ferafano/");
	else
        perror("cd");
	write (1, "\n", 1);
}

int main(int argc, char *argv[], char *envp[])
{
    char *line_read;
    char **copy_env;
    char **export;
	int yes;

	yes = 0;
    (void)argc;
    (void)argv;
    line_read = NULL;
    export = malloc(sizeof(char *));
    export[0] = NULL;
    copy_env = ft_copy_env(envp);

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
        if (strncmp(line_read, "pwd", 3) == 0)
            ft_pwd(line_read + 3);
        else if (strncmp(line_read, "echo ", 5) == 0)
            ft_echo(line_read + 5);
        else if (strncmp(line_read, "cd ", 3) == 0)
            ft_cd(line_read + 3);
        else if (strncmp(line_read, "env", 3) == 0)
        {
            for (int a = 0; copy_env[a]; a++)
                printf("%s\n", copy_env[a]);
			int yes;
			yes = 0;
			for (int i = 0; export[i]; i++)
			{
				if (strchr(export[i], '='))
				{
					for (int a = 0; export[i][a]; a++)
					{	
						printf("%c", export[i][a]);
						if (export[i][a] == '=')
						{
							yes = 1;
							printf("\"");
						}
					}
					if (yes == 1)
						printf("\"");
					printf("\n");
					yes = 0;
				}
            }
        }
        else if (strncmp(line_read, "unset ", 6) == 0)
        {
            char **temp = copy_env;
            copy_env = ft_unset(line_read + 6, temp, &export);
        }
        else if (strncmp(line_read, "export", 6) == 0)
        {
            if (line_read[7] == '\0')
			{
				for (int a = 0; copy_env[a]; a++)
				{
					printf("declare -x ");
					printf("%s\n", copy_env[a]);	
				}
                for (int i = 0; export[i]; i++)
				{
					printf("declare -x ");
					for (int a = 0; export[i][a]; a++)
					{
						printf("%c", export[i][a]);
						if (export[i][a] == '=')
						{
							yes = 1;
							printf("\"");
						}
					}
					if (yes == 1)
						printf("\"");
					printf("\n");
					yes = 0;
                }
            } else {
                ft_export(line_read + 7, &export, copy_env);
            }
        }
        else if (strcmp(line_read, "exit") == 0)
            break;
        else
            printf("Command not found: %s\n", line_read);
        printf("\n");
    }
    for (int i = 0; export[i]; i++) free(export[i]);
	free(export);
    for (int i = 0; copy_env[i]; i++) free(copy_env[i]);
	free(copy_env);
    return (0);
}

