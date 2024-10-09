/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferafano <ferafano@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:14:28 by ferafano          #+#    #+#             */
/*   Updated: 2024/09/09 11:56:35 by ferafano         ###   ########.fr       */
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
			rm.str_len = strlen(copy_env[rm.j]);
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

int	ft_unset(char **argv, char ***copy_env)
{
	int		i;
	int		l;
	int		env_name_len;
	char	**temp;
	char	*delimiter;

	l = 0;
	env_name_len = 0;
	while (argv[l])
	{
		if (strchr(argv[l], '=') != NULL || strlen(argv[l]) == 0)
		{
			l++;
			continue ;
		}
		i = 0;
		while ((*copy_env)[i])
		{
			delimiter = strchr((*copy_env)[i], '=');
			if (delimiter)
				env_name_len = (int)(delimiter - (*copy_env)[i]);
			else
				env_name_len = strlen((*copy_env)[i]);
			if (strncmp((*copy_env)[i], argv[l], env_name_len) == 0
				&& argv[l][env_name_len] == '\0')
			{
				temp = *copy_env;
				*copy_env = ft_rm_env(temp, i);
				break ;
			}
			i++;
		}
		l++;
	}
	return (0);
}
