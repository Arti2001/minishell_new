/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 09:10:04 by amysiv            #+#    #+#             */
/*   Updated: 2024/08/28 11:58:43 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H
#include <stdio.h>
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <sys/types.h>
#include <readline/history.h>
#include <dirent.h>

typedef struct s_env
{
	char			*content;
	char			*name;
	char			*value;
	struct	s_env	*next;
}t_env;

typedef struct s_pars
{
	char	**commands;
} t_pars;

/*Linked list*/
t_env	*ll_last(t_env *last);
t_env	*ft_env_lstnew(char *content);
void	ll_addback(t_env **env_head, t_env *new_node);

int	check_equel(char *str);
t_env	*set_env(char **env);
int		check_new_line(char *str);
char 	*get_key(char *content);
char	*get_value(char *content);
void	ch_env_value(t_env *env, char *var_name, char *new);
int		check_var_syntax(char *str);
void	concat_new_val(t_env *node,char *new_val);
void	append_node(t_env **head_env, char *content);


/*Built_ins*/

void	ft_pwd(void);
void	ft_env(t_env *env);
void	ft_echo(char**commands);
char	*get_path(char *name, t_env *env);
void	ft_cd(t_env *env, char **commands);
void	ft_export(t_env *env, char **commands);

#endif