/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trazanad <trazanad@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:18:59 by trazanad          #+#    #+#             */
/*   Updated: 2024/08/02 11:09:40 by trazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_unsigned(long nb)
{
	long	max;

	if (nb < 0)
	{
		max = UNSIGNED_MAXS;
		nb = max + nb;
	}
	return (ft_putnbr_decimal(nb));
}
