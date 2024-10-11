/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferafano <ferafano@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:10:55 by ferafano          #+#    #+#             */
/*   Updated: 2024/09/16 15:05:45 by ferafano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildin.h"

void	ft_copy(char *str, char *dest)
{
	int	i;

	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
}

char	**ft_allocate_env_copy(char **envp, int *len)
{
	char	**copy;

	*len = 0;
	while (envp[*len])
		(*len)++;
	copy = (char **)malloc((*len + 1) * sizeof(char *));
	if (copy == NULL)
		return (NULL);
	return (copy);
}

char	**ft_copy_env_content(char **envp, char **copy, int len)
{
	int	j;
	int	k;
	int	str_len;

	j = 0;
	k = 0;
	while (j < len)
	{
		str_len = ft_strlen(envp[j]);
		copy[j] = (char *)malloc((str_len + 1) * sizeof(char));
		if (copy[j] == NULL)
		{
			while (k < j)
				free(copy[k++]);
			free(copy);
			return (NULL);
		}
		ft_copy(envp[j], copy[j]);
		j++;
	}
	copy[len] = NULL;
	return (copy);
}

char	**ft_copy_env(char **envp)
{
	int		len;
	char	**copy;

	copy = ft_allocate_env_copy(envp, &len);
	if (copy == NULL)
		return (NULL);
	return (ft_copy_env_content(envp, copy, len));
}
