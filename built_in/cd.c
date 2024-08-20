/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:16:30 by amysiv            #+#    #+#             */
/*   Updated: 2024/08/20 19:38:54 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *get_path(char *name, t_env *env)
{
	while (env != NULL)
	{
		if (ft_strncmp(env->name, name, ft_strlen(name)) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

//void	ft_cd(t_env *env, char **commands)
//{
//	DIR	*dir;

//	if (commands[2] != NULL)
//	{
//		ft_putendl_fd("bash: cd: too many arguments", 2);
//		return ;
//	}
//	if (commands[1] == NULL)
//	{
//		chdir(get_path("HOME", env));
//		return ;
//	}
//	if (ft_strncmp(commands[1], ".", 2) == 0)
//	{
//		chdir(".");
//		return ;
//	}
//	if (ft_strncmp(commands[1], "..", 3) == 0)
//	{
//		chdir("..");
//		return ;
//	}
//	dir = opendir(commands[1]);
//	if (dir == NULL)
//	{
//		ft_putstr_fd("bash: ", 2);
//		ft_putstr_fd(commands[0], 2);
//		ft_putstr_fd(": ", 2);
//		ft_putstr_fd(commands[1], 2);
//		ft_putstr_fd(": ", 2);
//		ft_putendl_fd(" Not a directory", 2);
//		return ;
//	}
//	else
//		closedir(dir);
//	if (access(commands[1], F_OK) == 0)
//	{
//		chdir(commands[1]);
//		return ;
//	}
//	else
//	{	
//		ft_putstr_fd("bash: ", 2);
//		ft_putstr_fd(commands[0], 2);
//		ft_putstr_fd(": ", 2);
//		ft_putstr_fd(commands[1], 2);
//		ft_putstr_fd(": ", 2);
//		ft_putendl_fd(" No such file or directory", 2);
//		return ;
//	}
//}



void ft_cd(t_env *env, char **commands)
{
	
	DIR	*dir;
	
	if (commands[1] == NULL)
	{
		chdir(get_path("HOME", env));
		return ;
	}
	if (commands[2] != NULL)
	{
		ft_putendl_fd("bash: cd: too many arguments", 2);
		return ;
	}
	dir = opendir(commands[1]);
	if (access(commands[1], F_OK ) == 0 && (dir != NULL))
	{
		chdir(commands[1]);
		return ;
	}
	if (access(commands[1], F_OK ) != 0)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(commands[0], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(commands[1], 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(" No such file or directory", 2);
		return ;
	}
	if (dir == NULL)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(commands[0], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(commands[1], 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(" Not a directory", 2);
		closedir(dir);
		return ;
	}
	else
		closedir(dir);
}
