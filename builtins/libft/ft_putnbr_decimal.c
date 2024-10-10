/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trazanad <trazanad@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:10:38 by trazanad          #+#    #+#             */
/*   Updated: 2024/08/02 12:05:59 by trazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_decimal(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		len++;
		ft_putchar_fd('-', 1);
		len += ft_putnbr_positve_base(-nb, DECIMALS);
	}
	else
		len += ft_putnbr_positve_base(nb, DECIMALS);
	return (len);
}
