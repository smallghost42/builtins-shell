/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferafano <ferafano@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:10:55 by ferafano          #+#    #+#             */
/*   Updated: 2024/09/09 09:12:34 by ferafano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildin.h"

void ft_copy(char *str, char *dest)
{
    int i;

	i = 0;
    while (str[i])
    {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
}

char **ft_copy_env(char **envp)
{
    int len;
	int j;
	int k;
	int str_len;
	char **copy;

	len = 0;
	j = 0;
	str_len = 0;
	k = 0;
    while (envp[len])
        len++;
    copy = (char **) malloc((len + 1) * sizeof(char *));
    if (copy == NULL)
        return NULL;
    while (j < len)
    {
        str_len = strlen(envp[j]);
        copy[j] = (char *)malloc((str_len + 1) * sizeof(char));
        if (copy[j] == NULL)
        {
            while (k < j)
			{
                free(copy[k]);
				k++;
			}
            free(copy);
            return NULL;
        }
        ft_copy(envp[j], copy[j]);
		j++;
    }
    copy[len] = NULL;
    return (copy);
}
