/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferafano <ferafano@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:30:37 by ferafano          #+#    #+#             */
/*   Updated: 2024/10/10 09:33:11 by ferafano         ###   ########.fr       */
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

void	cond_loop(t_print_exp *exp, int *j)
{
	while (exp->temp_env[exp->temp_i][*j])
	{
		if (exp->temp_env[exp->temp_i][*j] == '"')
			printf("\\");
		printf("%c", exp->temp_env[exp->temp_i][*j]);
		(*j)++;
	}
}
