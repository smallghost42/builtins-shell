/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferafano <ferafano@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:57:20 by ferafano          #+#    #+#             */
/*   Updated: 2024/09/16 15:18:16 by ferafano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildin.h"

int	ft_env(char **copy_env, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	/*if (argv[1] != NULL)
	{
		write(2, "env: too many arguments\n", 24);
		return (1);
	}*/
	while (copy_env[i])
	{
		if (strchr(copy_env[i], '='))
			printf("%s\n", copy_env[i]);
		i++;
	}
	return (0);
}
