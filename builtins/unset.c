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

char 	**ft_unset(char *line_read, char **copy_env, char ***exported)
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
	i = 0;
	success = 0;
	while (*exported[i])
	{
		if (*(exported[i][0]) == line_read[0])
		{
			j = 1;
			while (line_read[j])
			{
				if ((*exported[i])[j] != line_read[j])
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
			temp = *exported;
			*exported = ft_rm_env(temp, i);
			break ;
		}
		i++;
	}
	return (copy_env);
}

