/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:16:30 by amysiv            #+#    #+#             */
/*   Updated: 2024/08/16 17:46:44 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *get_path(char *name, t_env *env)
{
	char	*path;
	
	while (env != NULL)
	{
		if (ft_strncmp(env->name, name, ft_strlen(name)) == 0)
		{
			path = ft_strchr(env->name, '/');
			break;
		}
		env = env->next;
	}
	return (path);
}

void	ft_cd(t_env *env)
{
	t_pars	*pars;
	
	if (pars->commands[2] != NULL)
		ft_putendl_fd("bash: cd: too many arguments", 2);
	if (pars->commands[0][2] != '\0')
	{
		ft_putstr_fd("commands '", 2);
		ft_putstr_fd(pars->commands[0], 2);
		ft_putendl_fd("' not found", 2);
	}
	if (pars->commands[1]== NULL)
	{
		chdir(get_path("HOME", env));
		return ;
	}
	if (ft_strncmp(pars->commands[1], ".", 1) == 0)	
		chdir(".");
	if (ft_strncmp(pars->commands[1], "..", 2) == 0)
	{
		chdir("..");
		return ;
	}
	if (access(pars->commands[1], F_OK) == 0)
		chdir(pars->commands[1]);
}
