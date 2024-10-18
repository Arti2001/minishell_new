/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 09:10:04 by amysiv            #+#    #+#             */
/*   Updated: 2024/10/18 19:45:35 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <readline/history.h>
#include <readline/readline.h>
#include "../libft/libft.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef enum s_redirect_type
{
	HEREDOC,
	IN,
	OUT,
	OUT_APPEND
}	t_redirect_type;

typedef enum s_builtin
{
	NO_BUILTIN = 10
	
} t_builtin;

typedef struct s_env
{
	char			*content;
	char			*name;
	char			*value;
	struct	s_env	*next;
}	t_env;

typedef struct s_redirect
{
	char				*filename;
	t_redirect_type		type;
}	t_redirect;


typedef struct s_pars
{
	char			**commands;
	t_redirect		*redirections;
	struct s_pars	*next_process;
} t_pars;

/*For extractin the path from the env*/
typedef struct s_exec
{
	char	**all_pathes;
	char	*temp_path;
	char	*true_path;
}t_exec;


/*Linked list*/
t_env	*ll_last(t_env *last);
int		ft_lst_size(t_env *lst);
t_env	*ft_env_lstnew(char *content);
void	ll_addback(t_env **env_head, t_env *new_node);
void	append_node(t_env **head_env, char *content);

/*Built_ins*/
int		ft_pwd(void);
int		ft_env(t_env *env);
void	ft_exit(char **arg);
int		ft_echo(char**commands);
int		ft_unset(t_env **env, char **arg);
int		ft_cd(t_env *env, char **commands);
int		ft_export(t_env *env, char **commands);

/*ENVIRONMENT*/
t_env	*set_env(char **env);
char 	*get_key(char *content);
char	*get_value(char *content);
int		check_var_syntax(char *str);
char	**back_to_array(t_env *env);
int		is_exist(t_env *env, char *name);
char	*get_path(char *name, t_env *env);
void	ch_env_value(t_env *env, char *var_name, char *new);

/*STRING UTILITI*/
int		check_equel(char *str);
int		check_new_line(char *str);

/*PROCCESSES*/
void 	*run_command(t_pars *pars, t_env *env);

/*FREE*/
void	free_list(t_env *head);
void	double_array_free(char **to_free);

/*REDIRECTS*/
void	redirect_check(t_pars *pars);

#endif

