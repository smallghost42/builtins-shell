/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trazanad <trazanad@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:51:36 by trazanad          #+#    #+#             */
/*   Updated: 2024/08/02 11:10:25 by trazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;
	int		diff;
	size_t	count;

	i = 0;
	count = ft_strlen(s1);
	if (ft_strlen(s1) < ft_strlen(s2))
		count = ft_strlen(s2);
	if (n > count)
		n = count;
	while (n > 0)
	{
		diff = (unsigned char) s1[i] - (unsigned char) s2[i];
		if ((int) diff < 0)
			diff = diff * 1;
		if (diff != 0)
			return (diff);
		i++;
		n--;
	}
	return (0);
}
