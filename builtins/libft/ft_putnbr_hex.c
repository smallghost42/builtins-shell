/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trazanad <trazanad@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:28:31 by trazanad          #+#    #+#             */
/*   Updated: 2024/08/02 11:09:34 by trazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_hex(long nb, char *str_base)
{
	long	max;

	if (nb < 0)
	{
		max = UNSIGNED_MAXS;
		nb = max + nb;
	}
	return (ft_putnbr_positve_base(nb, str_base));
}
