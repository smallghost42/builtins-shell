/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferafano <ferafano@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:41:41 by ferafano          #+#    #+#             */
/*   Updated: 2024/09/11 10:52:27 by ferafano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildin.h"

void	get_envp(char *line_read, char **copy_env, char **exported)
{
	int i;
	int j;
	int success;
	int len;

	len = 0;
	while (line_read[len] && line_read[len] != '=')
		len++;
	i = 0;
	success = 0;
	while (copy_env[i])
	{
		if (copy_env[i][0] == line_read[0])
		{
			j = 1;
			while (line_read[j])
			{
				if (copy_env[i][j] != line_read[j])
				{
					success = 0;
					break ;
				}
				else
					success = 1;
				j++;
			}
		}
		if (success == 1)
		{
			printf("%s\n", copy_env[i] + len + 1);
			break ;
		}
		i++;
	}
	i = 0;
	success = 0;
	while (exported[i])
	{
		if (exported[i][0] == line_read[0])
		{
			j = 1;
			while (line_read[j])
			{
				if (exported[i][j] != line_read[j])
				{
					success = 0;
					break ;
				}
				else
					success = 1;
				j++;
			}
		}
		if (success == 1)
		{
			printf("%s\n", exported[i] + len + 1);
			break ;
		}
		i++;
	}	
}
