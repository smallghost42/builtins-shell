/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trazanad <trazanad@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 08:03:42 by trazanad          #+#    #+#             */
/*   Updated: 2024/08/02 12:04:44 by trazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# define DECIMALS "0123456789"

# define HEX_UPPER "0123456789ABCDEF"

# define HEX_LOWER "0123456789abcdef"

# define UNSIGNED_MAXS 4294967296

# define LONG_MAXS 9223372036854775807

int	ft_printf(const char *format, ...);
int	ft_is_error(const char *s, va_list arg);
int	ft_putnbr_positve_base(unsigned long nb, char *str_base);
int	ft_putnbr_decimal(long nb);
int	ft_putnbr_unsigned(long nb);
int	ft_putnbr_hex(long nb, char *str_base);
int	ft_putptr(void *ptr);

#endif
