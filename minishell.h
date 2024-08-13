/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:54:45 by amysiv            #+#    #+#             */
/*   Updated: 2024/08/13 17:34:31 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
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
	char **cp_env;
	char **command;
	
} t_pars;

t_env	*ft_env_lstnew(char *content);

/*Built_ins*/

void	ft_pwd(void);
void	ft_cd(t_pars *my_env);


#endif