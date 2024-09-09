/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferafano <ferafano@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 08:52:40 by ferafano          #+#    #+#             */
/*   Updated: 2024/09/09 13:33:33 by ferafano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildin.h"

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

char	**ft_fill_array(char **new_r, char *s, char c)
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
			new_r[index][j] = s[i];
			i++;
			j++;
			if (s[i] == c || s[i] == '\0')
			{
				new_r[index][j] = '\0';
				index++;
			}
		}
	}
	new_r[index] = NULL;
	return (new_r);
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
