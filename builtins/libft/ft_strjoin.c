/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trazanad <trazanad@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:40:29 by trazanad          #+#    #+#             */
/*   Updated: 2024/08/02 11:10:09 by trazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *str, char const *s, int *index)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		str[*index] = s[i];
		i++;
		*index = *index + 1;
	}
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		*index_ptr;
	int		value;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1 && !s2)
		return (0);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (0);
	value = 0;
	index_ptr = &value;
	ft_strcat(str, s1, index_ptr);
	ft_strcat(str, s2, index_ptr);
	str[*index_ptr] = '\0';
	free(s1);
	return (str);
}
