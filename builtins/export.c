/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferafano <ferafano@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:02:32 by ferafano          #+#    #+#             */
/*   Updated: 2024/09/09 09:09:44 by ferafano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildin.h"

int check_valid_name(char *name)
{
    int i;

	i = 0;
    if ((!isalpha(name[0]) && name[0] != '_'))
        return (0);
    while (name[++i] && name[i] != '=')
	{
        if ((!isalnum(name[i]) && name[i] != '_'))
            return (0);
    }
    return (1);
}

void ft_reassign(char *name, char **to_assign)
{
    free(*to_assign);
    *to_assign = strdup(name);
}

int create_or_not(char *name, char **exported)
{
    int len;
    int i;

    len = strlen(name);
    i = 0;
    while (exported[i])
    {
        if (strncmp(exported[i], name, len) == 0 && exported[i][len] == '\0')
            return (1);
        i++;
    }
    return (0);
}

char **create_new_export(char *name, char **exported)
{
    int len;
    int i;
    char **copy;

    len = 0;
    i = 0;
    while (exported[len])
        len++;
    copy = malloc((len + 2) * sizeof(char *));
    if (copy == NULL)
        return NULL;
    while (i < len)
    {
        copy[i] = strdup(exported[i]);
        i++;
    }
    copy[len] = strdup(name);
    copy[len + 1] = NULL;
    if (exported)
    {
        i = 0;
        while (i < len)
        {
            free(exported[i]);
            i++;
        }
        free(exported);
    }
    return (copy);
}

int check_if_exist(char *name, char **env, char **exported)
{
    int i;
    int len;
    char *equal_sign = strchr(name, '=');

    len = equal_sign ? equal_sign - name : strlen(name);

    i = 0;
    while (exported[i])
    {
        if (strncmp(exported[i], name, len) == 0 && (exported[i][len] == '=' || exported[i][len] == '\0'))
        {
            if (equal_sign)
                ft_reassign(name, &exported[i]);
            return (1);
        }
        i++;
    }
    i = 0;
    while (env[i])
    {
        if (strncmp(env[i], name, len) == 0 && (env[i][len] == '=' || env[i][len] == '\0'))
        {
            if (equal_sign)
                ft_reassign(name, &env[i]);
            return (1);
        }
        i++;
    }
    return (0);
}

void ft_export(char *command, char ***existing_export, char **env)
{
    int i;
    char **to_export;

    i = 0;
    to_export = ft_split(command, ' ');
    while (to_export[i])
    {
        if (check_valid_name(to_export[i]))
        {
            if (!check_if_exist(to_export[i], env, *existing_export))
            {
                if (create_or_not(to_export[i], *existing_export) == 0)
                    *existing_export = create_new_export(to_export[i], *existing_export);
            }
        }
        else
            printf("invalid identifier\n");
        i++;
    }
    //ft_free_split(to_export);
}

