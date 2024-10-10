/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferafano <ferafano@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:57:20 by ferafano          #+#    #+#             */
/*   Updated: 2024/10/10 09:31:17 by ferafano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildin.h"

void	exec_this(t_print_exp *exp)
{
	int	j;

	j = 0;
	printf("declare -x ");
	while (exp->temp_env[exp->temp_i][j]
		&& exp->temp_env[exp->temp_i][j] != '=')
	{
		printf("%c", exp->temp_env[exp->temp_i][j]);
		j++;
	}
	if (exp->temp_env[exp->temp_i][j] == '=' && exp->temp_env[exp->temp_i][j
		+ 1] == '\0')
		printf("=\"\"\n");
	else if (exp->temp_env[exp->temp_i][j] == '='
		&& exp->temp_env[exp->temp_i][j + 1] != '\0')
	{
		j++;
		printf("=\"");
		cond_loop(exp, &j);
		printf("\"\n");
	}
	else
		printf("\n");
}

void	sort_free(t_print_exp *exp)
{
	exp->temp_env[exp->length] = NULL;
	bubble_sort(exp->temp_env, exp->length);
	exp->temp_i = 0;
	while (exp->temp_env[exp->temp_i])
	{
		exec_this(exp);
		exp->temp_i++;
	}
	exp->i = 0;
	while (exp->temp_env[exp->i])
	{
		free(exp->temp_env[exp->i]);
		exp->i++;
	}
	free(exp->temp_env);
}

int	print_export(char **copy_env)
{
	t_print_exp	exp;

	exp.length = 0;
	while (copy_env[exp.length])
		exp.length++;
	exp.temp_env = malloc((exp.length + 1) * sizeof(char *));
	if (!exp.temp_env)
		return (1);
	exp.i = 0;
	while (exp.i < exp.length)
	{
		exp.temp_env[exp.i] = strdup(copy_env[exp.i]);
		if (!exp.temp_env[exp.i])
		{
			while (--exp.i >= 0)
				free(exp.temp_env[exp.i]);
			free(exp.temp_env);
			return (1);
		}
		exp.i++;
	}
	sort_free(&exp);
	return (0);
}
