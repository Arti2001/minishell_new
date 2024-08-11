/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:54:45 by amysiv            #+#    #+#             */
/*   Updated: 2024/08/11 14:32:14 by amysiv           ###   ########.fr       */
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
	char **cp_env;
	
} t_env;
/*Built_ins*/

void	ft_pwd(void);
void	ft_cd(char * relative, char *absolute, t_env my_env);


#endif