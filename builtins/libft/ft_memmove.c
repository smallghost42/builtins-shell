/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trazanad <trazanad@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:22:45 by trazanad          #+#    #+#             */
/*   Updated: 2024/08/02 11:08:59 by trazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;

	if (!src && !dest)
		return (0);
	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	if (dest <= src)
	{
		while (n--)
			*tmp_dest++ = *tmp_src++;
	}
	else if (dest > src)
	{
		tmp_dest += n - 1;
		tmp_src += n - 1;
		while (n--)
			*tmp_dest-- = *tmp_src--;
	}
	return (dest);
}
