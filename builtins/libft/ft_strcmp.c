/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trazanad <trazanad@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:19:17 by trazanad          #+#    #+#             */
/*   Updated: 2024/08/02 11:09:56 by trazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;
	int	diff;
	int	count;

	i = 0;
	count = ft_strlen(s1);
	if (ft_strlen(s1) < ft_strlen(s2))
		count = ft_strlen(s2);
	while (count >= 0)
	{
		diff = (unsigned char) s1[i] - (unsigned char) s2[i];
		if (diff != 0)
			return (diff);
		i++;
		count--;
	}
	return (0);
}
