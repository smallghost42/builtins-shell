/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferafano <ferafano@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:32:11 by ferafano          #+#    #+#             */
/*   Updated: 2024/10/17 13:57:43 by ferafano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildin.h"

long	ft_atol(char *nptr)
{
	int		paire;
	long	nb;

	nb = 0;
	paire = nb;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	while (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			paire++;
		nptr++;
		if (*nptr == '+' || *nptr == '-')
			return (0);
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		nb *= 10;
		nb += *nptr - 48;
		nptr++;
	}
	if (!(paire % 2))
		return (nb);
	return (-nb);
}

int	valid_exit(char *str)
{
	int		i;
	long	tmp;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (i == 0 && str[1] != '\0' && (str[i] == '-' || str[i] == '+'))
			i++;
		else if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
			return (0);
	}
	if ((str[1] == '-' && ft_strlen(str) > 21) || (ft_strlen(str) > 20)
		|| !ft_strcmp4(str, "-9223372036854775809") || !ft_strcmp4(str,
			"9223372036854775808") || !ft_strcmp4(str, "9223372036854775809"))
		return (0);
	tmp = ft_atol(str);
	if (tmp >= -9223372036854775807 - 1 && tmp <= 9223372036854775807)
		return (1);
	else
		return (0);
}

void	ft_exit_free(char **copy_env)
{
	int	i;

	i = 0;
	while (copy_env[i])
	{
		free(copy_env[i]);
		i++;
	}
	free(copy_env);
}

int	ft_exit(char **argv, char ***copy_env)
{
	if (argv[1] && argv[2] && valid_exit(argv[1]) == 1)
	{
		write(2, "exit: too many arguments\n", 25);
		return (1);
	}
	else if (argv[1] && valid_exit(argv[1]) == 1)
	{
		ft_exit_free(*copy_env);
		exit(ft_atol(argv[1]));
	}
	else if (!argv[1])
	{
		ft_exit_free(*copy_env);
		exit(0);
	}
	else
	{
		ft_exit_free(*copy_env);
		write(2, "numeric argument required\n", 26);
		exit(2);
	}
}
