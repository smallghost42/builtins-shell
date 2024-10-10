/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trazanad <trazanad@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 07:38:09 by trazanad          #+#    #+#             */
/*   Updated: 2024/08/02 11:08:18 by trazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number_depth(int n)
{
	long	nb;
	int		depth;

	nb = n;
	if (n < 0)
		nb = -n;
	depth = 1;
	if (n < 0)
		depth++;
	while (nb > 9)
	{
		nb = nb / 10;
		depth++;
	}
	return (depth);
}

static char	*ft_cpy_nb(int n)
{
	char	*str;
	int		i;
	int		depth;

	depth = ft_number_depth(n);
	str = (char *)(malloc((depth + 1) * sizeof(char)));
	if (!str)
		return (0);
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	i = depth - 1;
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	str[depth] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	else
		return (ft_cpy_nb(n));
}
