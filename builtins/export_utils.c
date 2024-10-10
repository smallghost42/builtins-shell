/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferafano <ferafano@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 07:33:31 by ferafano          #+#    #+#             */
/*   Updated: 2024/10/10 07:34:16 by ferafano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildin.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = strlen(s1) + strlen(s2);
	new = malloc(len + 1);
	if (new == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

int	ft_len(char *name, char *exist_sign)
{
	if (exist_sign)
		return (exist_sign - name);
	else
		return (strlen(name));
}

void	exec_cond(t_ext_stat *ext, char **env)
{
	if (env[ext->i][ext->len] == '\0' && env[ext->i][ext->len - 1] != '=')
	{
		ext->temp = env[ext->i];
		env[ext->i] = ft_strjoin(ext->temp, ext->exist_sign);
	}
	else
	{
		ext->temp = env[ext->i];
		env[ext->i] = ft_strjoin(ext->temp, ext->exist_sign + 1);
	}
}

int	ft_exist_status(char *name, char **env)
{
	t_ext_stat	ext;

	ext.temp = NULL;
	ext.exist_sign = strchr(name, '=');
	ext.len = ft_len(name, ext.exist_sign);
	ext.i = 0;
	while (env && env[ext.i])
	{
		if (strncmp(env[ext.i], name, ext.len - 1) == 0 && (env[ext.i][ext.len
				- 1] == '=' || env[ext.i][ext.len] == '\0'))
		{
			if (ext.exist_sign)
			{
				exec_cond(&ext, env);
				return (2);
			}
		}
		ext.i++;
	}
	return (0);
}

void	crt_copy(t_crt *crt, char *name)
{
	while (name[crt->i])
	{
		if (name[crt->i] == '+')
			crt->i++;
		crt->name1[crt->j] = name[crt->i];
		crt->j++;
		crt->i++;
	}
}
