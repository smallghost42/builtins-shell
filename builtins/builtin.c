#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>
#include <readline/readline.h>
#include <readline/history.h>

/////////////////

int	ft_check_size(char *s, char c)
{
	int	i;
	int	array_nbr;
	int	get;

	i = 0;
	array_nbr = 0;
	get = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			get = 1;
		}
		if (get == 1)
			array_nbr++;
		get = 0;
	}
	return (array_nbr);
}

int	ft_check_size_array(char *s, char c, int array_indice)
{
	int	i;
	int	len;
	int	get;

	i = 0;
	len = 0;
	get = -1;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			len++;
			i++;
		}
		get++;
		if (get == array_indice)
			return (len);
		len = 0;
	}
	return (len);
}

char	**ft_fill_array(char **new, char *s, char c)
{
	int	i;
	int	index;
	int	j;

	i = 0;
	index = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			new[index][j] = s[i];
			i++;
			j++;
			if (s[i] == c || s[i] == '\0')
			{
				new[index][j] = '\0';
				index++;
			}
		}
	}
	new[index] = NULL;
	return (new);
}

void	ft_freee(char **new_1, int i)
{
	while (i >= 0)
	{
		free(new_1[i]);
		i--;
	}
	free(new_1);
}

int	is_null(char **new_1, int i)
{
	if (new_1[i] == NULL)
	{
		ft_freee(new_1, i);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		len;
	char	**new;
	int		i;
	int		array_nbr;

	i = 0;
	len = 0;
	array_nbr = ft_check_size((char *)s, c);
	if (array_nbr == 0)
		return (NULL);
	new = (char **)malloc((array_nbr + 1) * sizeof(char *));
	if (new == NULL)
		return (NULL);
	while (i < array_nbr)
	{
		len = ft_check_size_array((char *)s, c, i);
		if (len != 0)
			new[i] = (char *)malloc((len + 1) * sizeof(char));
		if (is_null(new, i) == 0)
			return (NULL);
		i++;
	}
	new = ft_fill_array(new, (char *)s, c);
	return (new);
}


/////////////////////////////////////////////////

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (strchr(set, s1[start]) && start <= end)
		start++;
	if (start > end)
		return (strdup(s1 + end + 1));
	while (strchr(set, s1[end]) && end >= 0)
		end--;
	str = malloc(end - start + 2);
	if (!str)
		return (NULL);
	strlcpy(str, &s1[start], end - start + 2);
	return (str);
}

//////////////////////////////////////////////////

void pwd_prompt(char *path)
{
	const char *blue = "\033[0;33m";
    const char *reset = "\033[0m";
	char	cwd[4096];
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
		;//getcwd(cwd, sizeof(cwd));
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

char **ft_rm_env(char **copy_env, int i)
{
    int len;
	int j;
	int l;
	int k;
	int str_len;
	char **copy;

	len = 0;
	j = 0;
	str_len = 0;
	k = 0;
    while (copy_env[len])
        len++;
    copy = (char **) malloc((len) * sizeof(char *));
	if (copy == NULL)
		return (NULL);
	l = j;
	while (j < len)
    {
		if (j != i)
		{
			str_len = strlen(copy_env[j]);
			copy[l] = (char *)malloc((str_len + 1) * sizeof(char));
			if (copy[l] == NULL)
			{
				while (k < l)
				{
					free(copy[k]);
					k++;
				}
				free(copy);
				return (NULL);
			}
			ft_copy(copy_env[j], copy[l]);
			l++;
		}
		j++;
    }
    copy[l] = NULL;
    return (copy);
}

char 	**ft_unset(char *line_read, char **copy_env)
{
	int i;
	int j;
	int success;
	char **temp;

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
			temp = copy_env;
			copy_env = ft_rm_env(temp, i);
			break ;
		}
		i++;
	}
	return (copy_env);
}

/////////////////////////////////////////////////////

int check_valid_name(char *name)
{
	int i;

	i = 1;
	while (name[i] && name[i] != '=')
	{
		if ((!isalpha(name[0]) && name[0] != '_') || (!isalnum(name[i]) && name[i] != '_'))
			return (0);
		i++;
	}
	return (1);
}

int check_if_exist(char *name, char **env, char **export)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	len = 0;
	if (strchr(name, '='))
	{
		while (name[len] != '=')
			len++;
	}
	else
		return (1);
	while (name[i] && name[i] != '=')
	{
		if (strncmp(export[i], name, len) && export[i][len] == '=')
			return (2);
		if (strncmp(env[i], name, len) && env[i][len] == '=')
			return (3);
		i++;
	}
	return (0);
}

char **ft_export(char *command, char **existing_export, char **env)
{
	int i;
	char **export;
	char **copy_env;
	char **to_export;

	i = 0;
	to_export = ft_split(command, ' ');
	while (to_export[i])
	{
		if (check_valid_name(to_export[i]))
		{
			if (check_if_exist(to_export[i], env, existing_export) == 1)
			{
				if (create_or_not(to_export[i], env, existing_export))
					export = create_new_env(to_export[i], existing_export);
			}
			else if (check_if_exist(to_export[i], env, existing_export) == 2)
				export = reassign(to_export[i], existing_export);
			else if (check_if_exist(to_export[i], env, existing_export) == 3)
			{
				copy_env = env;
				env = reassign(to_export[i], copy_env);
			}
		}
		else
			printf("invalid identifier\n");
		i++;
	}
}

///////////////////////////////////////////////


int main(int argc, char *argv[], char *envp[])
{
	char	*line_read;
	char	**copy_env;
	char	**temp;
	char	**export;

	(void)argc;
	(void)argv;
	line_read = NULL;
	export = NULL;
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
		{
			temp = copy_env;
			copy_env = ft_unset(line_read + 6, temp);
		}
		else if (strncmp(line_read, "export", 6) == 0)
		{
			if (line_read[7] == '\0')
			{
				if (export)
				{
                	for (int i = 0; export[i]; i++)
					{
                    	printf("%s\n", export[i]);
					}
            	}
			}
			else
				export = ft_export(line_read + 7, export, copy_env);
		}
		else if (strcmp(line_read, "exit") == 0)
            break;
		else
            printf("Command not found: %s\n", line_read);
		printf("\n");
    }
    return 0;
}
