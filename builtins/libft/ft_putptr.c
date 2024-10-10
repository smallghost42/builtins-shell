/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trazanad <trazanad@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:33:07 by trazanad          #+#    #+#             */
/*   Updated: 2024/08/02 11:09:43 by trazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putptr_neg(long nb, char *str_base)
{
	long	max;

	if (nb < 0)
	{
		max = LONG_MAXS;
		nb += max + max + 2;
	}
	return (ft_putnbr_positve_base(nb, str_base));
}

int	ft_putptr(void *ptr)
{
	long	ptr_value;

	if (!ptr)
		return (ft_putstr_fd("(nil)", 1));
	ptr_value = (long) ptr;
	if (ptr_value == 0)
		return (ft_putchar_fd('0', 1));
	ft_putstr_fd("0x", 1);
	if (ptr_value > 0)
		return (2 + ft_putnbr_positve_base(ptr_value, HEX_LOWER));
	return (2 + ft_putptr_neg(ptr_value, HEX_LOWER));
}
