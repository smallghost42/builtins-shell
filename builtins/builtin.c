#include <ctype.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

/////////////////////////////////////////////////

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

int	ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_before(char *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		if (ft_isset(s1[i], set) == 1)
			j++;
		else
			break ;
		i++;
	}
	return (j);
}

int	ft_check_last(char *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i + 1] != '\0')
		i++;
	j = i;
	while (i > 0)
	{
		if (ft_isset(s1[i], set) == 1)
			j--;
		else
			break ;
		i--;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		len;
	int		i;
	char	*new;

	i = 0;
	start = ft_check_before((char *)s1, set);
	len = ft_check_last((char *)s1, set) - start + 1;
	if (start == (int)ft_strlen(s1))
		new = (char *) malloc(1);
	else
		new = (char *)malloc((len + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	new[0] = '\0';
	if (start == (int)ft_strlen(s1))
		return ((char *)new);
	while (len--)
	{
		new[i] = s1[start + i];
		i++;
	}
	new[i] = '\0';
	return ((char *)new);
}

//////////////////////////////////////////////////

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

char **ft_export(char *line_read)
{
	int i;
	int len;
	int len2;
	char *trimed_line;
	char **ex_split;
	char **export;

	i = 0;
	len = 0;
	trimed_line = ft_strtrim(line_read, "	");
	ex_split = ft_split(trimed_line, ' ');
	while (ex_split[len])
		len++;
	export = (char **) malloc((len + 1) * sizeof(char *));
	len = 0;
	len2 = len;
	while (ex_split[len])
	{
		i = 1;
		while (ex_split[len][i])
		{
			if (isalpha(ex_split[len][0]) || ex_split[len][0] == '_')
			{
				if (isalpha(ex_split[len][i] || isdigit(ex_split[len][i]) || ex_split[len][i] == '_'))
				{
					if (strchr(ex_split[len], '='))
					{
						export[len2] = malloc(ft_strlen(ex_split[len]) + 4);
						int x = 0;
						while (ex_split[len][x])
						{
							if (ex_split[len][x] == '=')
							{
								export[len2][x] = '=';
								export[len2][x + 1] = '"';
								x = x + 2;
							}
							else
							{
								export[len2][x] = ex_split[len][x];
								x++;
							}
						}
						export[len2][x] = '"';
						export[len2][x + 1] = '\0';
					}
					else
					{
						export[len2] = malloc(ft_strlen(ex_split[len]) + 1);
						int x = 0;
						while (ex_split[len][x])
						{
							export[len2][x] = ex_split[len][x];
							x++;
						}
						export[len2][x] = '\0';	
					}
					len2++;
				}
				else
				{
					printf("not a identifier-----------\n");
					return (NULL);
				}
			}
			else
			{
				printf("not a identifier\n");
				return (NULL);
			}
		}
		len++;
	}
	return (NULL);
}

int main(int argc, char *argv[], char *envp[])
{
	char	*line_read;
	char	**copy_env;
	char	**temp;
	char	**export;

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
		{
			temp = copy_env;
			copy_env = ft_unset(line_read + 6, temp);
		}
		else if (strncmp(line_read, "export", 5) == 0)
		{
			//if (line_read[6] == '\0')
			//	ft_dispaly_export(export, copy_env);
			//else
			//{
				export = ft_export(line_read + 6);
			//}
		}
		else if (strcmp(line_read, "exit") == 0)
            break;
		else
            printf("Command not found: %s\n", line_read);
		printf("\n");
    }
    return 0;
}
