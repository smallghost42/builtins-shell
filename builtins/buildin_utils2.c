/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildin_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferafano <ferafano@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 08:58:09 by ferafano          #+#    #+#             */
/*   Updated: 2024/09/09 09:12:26 by ferafano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildin.h"

char	**ft_split(char const *s, char c)
{
	int		len;
	char	**new;
	int		i;
	int		array_nbr;

	i = 0;
	len = 0;
	array_nbr = ft_check_size((char *)s, c);
	if (array_nbr == 0)
		return (NULL);
	new = (char **)malloc((array_nbr + 1) * sizeof(char *));
	if (new == NULL)
		return (NULL);
	while (i < array_nbr)
	{
		len = ft_check_size_array((char *)s, c, i);
		if (len != 0)
			new[i] = (char *)malloc((len + 1) * sizeof(char));
		if (is_null(new, i) == 0)
			return (NULL);
		i++;
	}
	new = ft_fill_array(new, (char *)s, c);
	return (new);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (strchr(set, s1[start]) && start <= end)
		start++;
	if (start > end)
		return (strdup(s1 + end + 1));
	while (strchr(set, s1[end]) && end >= 0)
		end--;
	str = malloc(end - start + 2);
	if (!str)
		return (NULL);
	strlcpy(str, &s1[start], end - start + 2);
	return (str);
}

