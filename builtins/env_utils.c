/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferafano <ferafano@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:57:20 by ferafano          #+#    #+#             */
/*   Updated: 2024/09/16 15:18:16 by ferafano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildin.h"

int	ft_env(char **copy_env, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argv[1] != NULL)
	{
		write(2, "env: too many arguments\n", 24);
		return (1);
	}
	while (copy_env[i])
	{
		if (strchr(copy_env[i], '='))
			printf("%s\n", copy_env[i]);
		i++;
	}
	return (0);
}

void	swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	bubble_sort(char **array, int length)
{
	int	i;
	int	j;
	int	swapped;

	i = 0;
	while (i < length - 1)
	{
		swapped = 0;
		j = 0;
		while (j < length - i - 1)
		{
			if (strcmp(array[j], array[j + 1]) > 0)
			{
				swap(&array[j], &array[j + 1]);
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
			break ;
		i++;
	}
}

int	print_export(char **copy_env)
{
	int		i;
	int		j;
	int		length;
	int		temp_i;
	char	**temp_env;

	length = 0;
	while (copy_env[length])
		length++;
	temp_env = malloc((length + 1) * sizeof(char *));
	if (!temp_env)
	{
		perror("malloc");
		return (1);
	}
	i = 0;
	while (i < length)
	{
		temp_env[i] = strdup(copy_env[i]);
		if (!temp_env[i])
		{
			perror("dup error");
			while (--i >= 0)
				free(temp_env[i]);
			free(temp_env);
			return (1);
		}
		i++;
	}
	temp_env[length] = NULL;
	bubble_sort(temp_env, length);
	temp_i = 0;
	while (temp_env[temp_i])
	{
		j = 0;
		printf("declare -x ");
		while (temp_env[temp_i][j] && temp_env[temp_i][j] != '=')
		{
			printf("%c", temp_env[temp_i][j]);
			j++;
		}
		if (temp_env[temp_i][j] == '=' && temp_env[temp_i][j + 1] == '\0')
			printf("=\"\"\n");
		else if (temp_env[temp_i][j] == '=' && temp_env[temp_i][j + 1] != '\0')
		{
			j++;
			printf("=\"");
			while (temp_env[temp_i][j])
			{
				printf("%c", temp_env[temp_i][j]);
				j++;
			}
			printf("\"\n");
		}
		else
			printf("\n");
		temp_i++;
	}
	i = 0;
	while (temp_env[i])
	{
		free(temp_env[i]);
		i++;
	}
	free(temp_env);
	return (0);
}
