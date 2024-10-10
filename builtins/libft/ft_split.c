/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trazanad <trazanad@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:45:57 by trazanad          #+#    #+#             */
/*   Updated: 2024/08/02 11:09:50 by trazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_tab_size(char const *s, char c)
{
	int	word_count;	
	int	i;

	word_count = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') && s[i] != c)
			word_count++;
		i++;
	}
	return (word_count);
}

static char	*ft_str_sep_cpy(char const *s, char c)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	j = 0;
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	len = i;
	i = 0;
	str = (char *)malloc((len + 1) * sizeof(char));
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

static char	**ft_create_tab(char **tab, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*(s + i) != '\0')
	{
		while (*(s + i) != '\0' && *(s + i) == c)
			i++;
		if (*(s + i) != '\0')
		{
			tab[j] = ft_str_sep_cpy(s + i, c);
			j++;
			while (*(s + i) != c && *(s + i) != '\0')
				i++;
		}
	}
	tab[j] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		len;

	if (!s)
		return (0);
	len = ft_tab_size(s, c);
	tab = (char **)malloc((len + 1) * sizeof(char *));
	if (!tab)
		return (0);
	return (ft_create_tab(tab, s, c));
}
