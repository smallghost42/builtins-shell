/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_positive_base.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trazanad <trazanad@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:04:18 by trazanad          #+#    #+#             */
/*   Updated: 2024/08/02 11:09:37 by trazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_positve_base(unsigned long nb, char *str_base)
{
	unsigned int	base;
	int				len;

	base = ft_strlen(str_base);
	len = 0;
	if (nb < base)
		len += ft_putchar_fd(str_base[nb], 1);
	else
	{
		len += ft_putnbr_positve_base(nb / base, str_base);
		len += ft_putnbr_positve_base(nb % base, str_base);
	}
	return (len);
}
