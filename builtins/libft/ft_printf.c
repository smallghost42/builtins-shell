/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trazanad <trazanad@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:42:19 by trazanad          #+#    #+#             */
/*   Updated: 2024/08/02 11:09:11 by trazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_show_msg(va_list arg, char c, int len)
{
	if (c == '%')
		len += ft_putchar_fd('%', 1);
	else if (c == 'c')
		len += ft_putchar_fd(va_arg(arg, int), 1);
	else if (c == 's')
		len += ft_putstr_fd(va_arg(arg, char *), 1);
	else if (c == 'd' || c == 'i')
		len += ft_putnbr_decimal(va_arg(arg, int));
	else if (c == 'u')
		len += ft_putnbr_unsigned(va_arg(arg, int));
	else if (c == 'x')
		len += ft_putnbr_hex(va_arg(arg, int), HEX_LOWER);
	else if (c == 'X')
		len += ft_putnbr_hex(va_arg(arg, int), HEX_UPPER);
	else if (c == 'p')
		len += ft_putptr(va_arg(arg, void *));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		len;

	va_start(arg, format);
	if (ft_is_error(format, arg))
		return (-1);
	va_start(arg, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len = ft_show_msg(arg, format[i], len);
		}
		else
			len += ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(arg);
	return (len);
}
