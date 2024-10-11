/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferafano <ferafano@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:14:28 by ferafano          #+#    #+#             */
/*   Updated: 2024/10/10 08:05:53 by ferafano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildin.h"

void	assign_alloc(t_rem *rm, char **copy_env)
{
	rm->len = 0;
	rm->j = 0;
	rm->k = 0;
	rm->l = 0;
	rm->str_len = 0;
	while (copy_env[rm->len])
		rm->len++;
	rm->copy = (char **)malloc(rm->len * sizeof(char *));
}

void	ft_wfree(t_rem *rm)
{
	while (rm->k < rm->l)
	{
		free(rm->copy[rm->k]);
		rm->k++;
	}
}

char	**ft_rm_env(char **copy_env, int i)
{
	t_rem	rm;

	assign_alloc(&rm, copy_env);
	if (rm.copy == NULL)
		return (NULL);
	while (rm.j < rm.len)
	{
		if (rm.j != i)
		{
			rm.str_len = ft_strlen(copy_env[rm.j]);
			rm.copy[rm.l] = (char *)malloc((rm.str_len + 1) * sizeof(char));
			if (rm.copy[rm.l] == NULL)
			{
				ft_wfree(&rm);
				free(rm.copy);
				return (NULL);
			}
			strcpy(rm.copy[rm.l], copy_env[rm.j]);
			rm.l++;
		}
		rm.j++;
	}
	rm.copy[rm.l] = NULL;
	return (rm.copy);
}

int	un_set(t_unset *unset, char ***copy_env, char **argv)
{
	unset->delimiter = ft_strchr((*copy_env)[unset->i], '=');
	if (unset->delimiter)
		unset->env_name_len = (int)(unset->delimiter - (*copy_env)[unset->i]);
	else
		unset->env_name_len = ft_strlen((*copy_env)[unset->i]);
	if (ft_strncmp((*copy_env)[unset->i], argv[unset->l], unset->env_name_len) == 0
		&& argv[unset->l][unset->env_name_len] == '\0')
	{
		unset->temp = *copy_env;
		*copy_env = ft_rm_env(unset->temp, unset->i);
		return (0);
	}
	return (1);
}

int	ft_unset(char **argv, char ***copy_env)
{
	t_unset	unset;

	unset.l = 0;
	unset.env_name_len = 0;
	while (argv[unset.l])
	{
		if (ft_strchr(argv[unset.l], '=') != NULL || ft_strlen(argv[unset.l]) == 0)
		{
			unset.l++;
			continue ;
		}
		unset.i = 0;
		while ((*copy_env)[unset.i])
		{
			if (un_set(&unset, copy_env, argv) == 0)
				break ;
			unset.i++;
		}
		unset.l++;
	}
	return (0);
}
