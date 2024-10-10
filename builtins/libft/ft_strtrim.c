/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trazanad <trazanad@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:12:48 by trazanad          #+#    #+#             */
/*   Updated: 2024/08/02 11:10:36 by trazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*create_str(char const *s1, int start, int end)
{
	char	*str;
	int		i;

	str = (char *)malloc((end - start + 2) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (start <= end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	if (!s1 && !set)
		return (0);
	if (*s1 == '\0')
		return (ft_strdup(""));
	start = 0;
	end = (int)ft_strlen(s1) - 1;
	while (ft_strchr(set, *(s1 + start)) && start < (int)ft_strlen(s1))
		start++;
	while (ft_strchr(set, *(s1 + end)) && end > 0)
		end--;
	if (end == 0)
		return (ft_strdup(""));
	return (create_str(s1, start, end));
}
