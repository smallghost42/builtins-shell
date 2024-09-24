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

char	**ft_rm_env(char **copy_env, int i)
{
	int		len;
	int		j;
	int		l;
	int		k;
	int		str_len;
	char	**copy;

	len = 0;
	j = 0;
	k = 0;
	l = 0;
	str_len = 0;
	while (copy_env[len])
		len++;
	copy = (char **)malloc(len * sizeof(char *));
	if (copy == NULL)
		return (NULL);
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
			strcpy(copy[l], copy_env[j]);
			l++;
		}
		j++;
	}
	copy[l] = NULL;
	return (copy);
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
