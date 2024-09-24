/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferafano <ferafano@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 08:53:20 by ferafano          #+#    #+#             */
/*   Updated: 2024/09/16 15:18:19 by ferafano         ###   ########.fr       */
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

int		ft_check_size(char *s, char c);
int		ft_check_size_array(char *s, char c, int array_indice);
char	**ft_fill_array(char **new_r, char *s, char c);
void	ft_freee(char **new_1, int i);
int		is_null(char **new_1, int i);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strtrim(char const *s1, char const *set);
void	ft_copy(char *str, char *dest);
int		check_valid_name(char *name, char ***env);
void	ft_reassign(char *name, char **to_assign);
int		create_or_not(char *name, char **exported);
char	**create_new_export(char *name, char **exported);
char	**ft_copy_env(char **envp);
void	pwd_prompt(char *path);
char	**ft_rm_env(char **copy_env, int i);
int		get_env_value(char **line_read, char **copy_env);
void	update_oldpwd(char *line_read, char *cwd, char **copy_env);
char	*search_envp(char *line_read, char **copy_env);
void	change_to_home(char *cwd, char **copy_env);
int		get_prefix_length(char *line_read);
int		is_match(char *line_read, char **copy_env);

int		change_to_oldpwd(char *cwd, char **copy_env);
int		change_to_path(char *path, char *cwd, char **copy_env);
int		buildin(char **argv, char ***copy_env);
int		ft_cd(char **argv, char **copy_env);
int		ft_pwd(char **path);
int		ft_env(char **copy_env, char **argv);
int		ft_export(char **command, char ***env);
int		check_if_exist(char *name, char **env);
int		print_export(char **copy_env);
int		ft_unset(char **argv, char ***copy_env);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
