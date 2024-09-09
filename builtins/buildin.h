/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferafano <ferafano@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 08:53:20 by ferafano          #+#    #+#             */
/*   Updated: 2024/09/09 10:37:13 by ferafano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILDIN_H
# define BUILDIN_H

# include <ctype.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <bsd/string.h>
# include <readline/readline.h>
# include <readline/history.h>

int	ft_check_size(char *s, char c);
int	ft_check_size_array(char *s, char c, int array_indice);
char	**ft_fill_array(char **new_r, char *s, char c);
void	ft_freee(char **new_1, int i);
void	ft_freee(char **new_1, int i);
int	is_null(char **new_1, int i);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strtrim(char const *s1, char const *set);
void ft_copy(char *str, char *dest);
int check_valid_name(char *name);
void ft_reassign(char *name, char **to_assign);
int create_or_not(char *name, char **exported);
char **create_new_export(char *name, char **exported);
int check_if_exist(char *name, char **env, char **exported);
void ft_export(char *command, char ***existing_export, char **env);
char **ft_copy_env(char **envp);
void pwd_prompt(char *path);
void ft_pwd(char *path);
char **ft_rm_env(char **copy_env, int i);
char 	**ft_unset(char *line_read, char **copy_env, char ***exported);

#endif
