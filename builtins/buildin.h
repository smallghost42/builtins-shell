/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferafano <ferafano@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 08:53:20 by ferafano          #+#    #+#             */
/*   Updated: 2024/10/10 09:32:06 by ferafano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILDIN_H
# define BUILDIN_H
# include "./libft/libft.h"
# include <ctype.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <bsd/string.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_oldpwd
{
	int		i;
	int		j;
	int		len;
	char	*new_value;
}			t_oldpwd;

typedef struct s_print_exp
{
	int		i;
	int		j;
	int		length;
	int		temp_i;
	char	**temp_env;
}			t_print_exp;

typedef struct s_ext_stat
{
	int		i;
	int		len;
	char	*exist_sign;
	char	*temp;
}			t_ext_stat;

typedef struct s_crt
{
	int		len;
	int		i;
	int		j;
	char	**copy;
	char	*name1;
}			t_crt;

typedef struct s_rem
{
	int		len;
	int		j;
	int		l;
	int		k;
	int		str_len;
	char	**copy;
}			t_rem;

typedef struct s_unset
{
	int		i;
	int		l;
	int		env_name_len;
	char	**temp;
	char	*delimiter;
}			t_unset;

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
void	pwd_prompt(void);
char	**ft_rm_env(char **copy_env, int i);
char	*get_env_value(char **line_read, char **copy_env);
void	update_oldpwd(char *line_read, char *cwd, char **copy_env);
char	*search_envp(char *line_read, char **copy_env);
void	change_to_home(char *cwd, char **copy_env);
int		get_prefix_length(char *line_read);
int		is_match(char *line_read, char **copy_env);
int		change_to_oldpwd(char *cwd, char **copy_env);
int		change_to_path(char *path, char *cwd, char **copy_env);
int		ft_cd(char **argv, char **copy_env);
int		ft_pwd(int fd);
int		ft_env(char **copy_env, char **argv, int fd);
int		ft_export(char **command, char ***env, int fd);
int		check_if_exist(char *name, char **env);
int		print_export(char **copy_env, int fd);
int		ft_unset(char **argv, char ***copy_env);
int		ft_len(char *name, char *exist_sign);
void	exec_cond(t_ext_stat *ext, char **env);
int		ft_exist_status(char *name, char **env);
void	crt_copy(t_crt *crt, char *name);
void	cond_loop(t_print_exp *exp, int *j, int fd);
void	bubble_sort(char **array, int length);
int		ft_strcmp4(const char *str1, const char *str2);
char	*ft_strcpy(char *dest, const char *src);

/////////////////////////////////////////////////////////

int		buildin(char **argv, char ***copy_env, int fd);

#endif
