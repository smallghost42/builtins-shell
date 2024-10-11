/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferafano <ferafano@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 07:37:44 by ferafano          #+#    #+#             */
/*   Updated: 2024/10/10 07:40:14 by ferafano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildin.h"

char	**create_no_plus(char *name, char **env)
{
	t_crt	crt;

	crt.len = 0;
	crt.i = 0;
	while (env && env[crt.len])
		crt.len++;
	crt.copy = malloc((crt.len + 2) * sizeof(char *));
	if (crt.copy == NULL)
		return (NULL);
	while (crt.i < crt.len)
	{
		crt.copy[crt.i] = ft_strdup(env[crt.i]);
		crt.i++;
	}
	crt.name1 = malloc((ft_strlen(name)) * sizeof(char));
	crt.i = 0;
	crt.j = 0;
	crt_copy(&crt, name);
	crt.name1[crt.j] = '\0';
	crt.copy[crt.len] = ft_strdup(crt.name1);
	free(crt.name1);
	crt.copy[crt.len + 1] = NULL;
	return (crt.copy);
}

int	ft_concat(char *name, char ***env)
{
	int		status;
	char	**temp;

	status = 0;
	temp = NULL;
	if (ft_exist_status(name, *env) == 2)
		status = 0;
	else
	{
		temp = *env;
		*env = create_no_plus(name, temp);
	}
	return (status);
}

int	check_valid_name(char *name, char ***env)
{
	int	i;
	int	status;

	i = 0;
	if ((!ft_isalpha(name[0]) && name[0] != '_'))
		return (-1);
	while (name[++i] && name[i] != '=')
	{
		if (name[i + 1] && name[i] == '+' && name[i + 1] == '=')
		{
			status = ft_concat(name, env);
			return (0);
		}
		if ((!ft_isalnum(name[i]) && name[i] != '_'))
			return (-1);
	}
	return (1);
}

void	ft_reassign(char *name, char **to_assign)
{
	free(*to_assign);
	*to_assign = ft_strdup(name);
}
