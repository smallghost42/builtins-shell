/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trazanad <trazanad@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:11:53 by trazanad          #+#    #+#             */
/*   Updated: 2024/08/02 11:07:47 by trazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkin(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static	int	ft_overflow_error(va_list arg, char c)
{
	long int	value;

	if (ft_checkin("diuxX", c))
	{
		value = (long) va_arg(arg, int);
		if (value < -2147483648 || value > 2147483647)
			return (1);
	}
	return (0);
}

int	ft_is_error(const char *s, va_list arg)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (!(ft_checkin("xXpdiucs", s[i]) || s[i] == '%'))
				return (1);
			else
			{
				if (ft_overflow_error(arg, s[i]))
					return (1);
			}
		}
		i++;
	}
	va_end(arg);
	return (0);
}
