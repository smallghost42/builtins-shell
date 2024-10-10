/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retire_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trazanad <trazanad@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:46:26 by trazanad          #+#    #+#             */
/*   Updated: 2024/08/02 12:06:41 by trazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_retire_space(char *str)
{
	int		i;
	int		len;
	char	*new_str;

	if (!str)
		return (NULL);
	i = 0;
	len = ft_strlen(str) - 1;
	if (len < 0)
		return (str);
	while (ft_isspace(str[i]))
		i++;
	while (ft_isspace(str[len]))
		len--;
	new_str = ft_substr(str, i, len - i + 1);
	return (new_str);
}
