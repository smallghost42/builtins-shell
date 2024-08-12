#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

void pwd_prompt(char *path)
{
	const char *blue = "\033[0;33m";
    const char *reset = "\033[0m";
	char	cwd[1024];
	int		i;
	int		count;

	if (chdir(path) != 0)
	{
 		i = 0;
		count = 0;
        getcwd(cwd, sizeof(cwd)); 
		while (count < 3)
		{
			if (cwd[i] == '/')
				count++;
			i++;
		}
		write(1, blue, strlen(blue));
		write(1, "~/", 2);
		while (cwd[i])
		{	
			write(1, &cwd[i], 1);
			i++;
		}
		write(1, reset, strlen(reset));
    }
	else
        perror("cd");
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
	char cwd[1024];

	if (chdir(path) == 0)
	{
		getcwd(cwd, sizeof(cwd));
	}
	else
        perror("cd");
	write (1, "\n", 1);
}

void ft_copy(char *str, char *dest)
{
    int i;

	i = 0;
    while (str[i])
    {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
}

char **ft_copy_env(char **envp)
{
    int len;
	int j;
	int k;
	int str_len;
	char **copy;

	len = 0;
	j = 0;
	str_len = 0;
	k = 0;
    while (envp[len])
        len++;
    copy = (char **) malloc((len + 1) * sizeof(char *));
    if (copy == NULL)
        return NULL;
    while (j < len)
    {
        str_len = strlen(envp[j]);
        copy[j] = (char *)malloc((str_len + 1) * sizeof(char));
        if (copy[j] == NULL)
        {
            while (k < j)
			{
                free(copy[k]);
				k++;
			}
            free(copy);
            return NULL;
        }
        ft_copy(envp[j], copy[j]);
		j++;
    }
    copy[len] = NULL;
    return (copy);
}

void	ft_unset(char *line_read, char **copy_env)
{
	int i;
	int j;
	int success;

	i = 0;
	success = 0;
	while (copy_env[i])
	{
		if (copy_env[i][0] == line_read[0])
		{
			j = 1;
			while (line_read[j])
			{
				if (copy_env[i][j] != line_read[j])
				{
					success = 0;
					break ;
				}
				else
					success = 1;
				j++;
			}
		}
		if (success == 1)
		{
			printf("ok\n");
			break ;
		}
		i++;
	}
	if (success == 0)
		printf("no such env\n");
}

int main(int argc, char *argv[], char *envp[])
{
	char	*line_read;
	char	**copy_env;

	(void)argc;
	(void)argv;
	line_read = NULL;
	copy_env = ft_copy_env(envp);
	int a = 0;
    while (1)
	{
		a = 0;
		if (line_read)
		{
			free (line_read);
			line_read = NULL;
		}
		pwd_prompt("pwd");
		line_read = readline ("\n\033[0;35m❯ \033[0m");
		add_history (line_read);
		if (strncmp(line_read, "pwd", 3) == 0)
            ft_pwd(line_read + 3);
		else if (strncmp(line_read, "echo ", 5) == 0)
            ft_echo(line_read + 5);
		else if (strncmp(line_read, "cd ", 3) == 0)
			ft_cd(line_read + 3);
		else if (strncmp(line_read, "env", 3) == 0)
		{
			while (copy_env[a] != NULL)
			{
				printf("%s\n",copy_env[a]);
				a++;
			}
		}
		else if (strncmp(line_read, "unset ", 6) == 0)
			ft_unset(line_read + 6, copy_env);
		else if (strcmp(line_read, "exit") == 0)
            break;
		else
            printf("Command not found: %s\n", line_read);
		printf("\n");
    }
    return 0;
}
