/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:16:30 by amysiv            #+#    #+#             */
/*   Updated: 2024/08/28 11:42:25 by amysiv           ###   ########.fr       */
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
		ch_env_value(env, "OLDPWD", getcwd(NULL, 0));
		chdir(commands[1]);
		ch_env_value(env, "PWD", getcwd(NULL, 0));
		return ;
	}
	if (access(commands[1], F_OK) == -1)
	{
		printf("bash: %s: %s: No such file or directory\n", commands[0], commands[1]);
		return ;
	}
	if (dir == NULL)
	{
		printf("bash: %s: %s: Not a directory\n", commands[0], commands[1]);
		closedir(dir);
		return ;
	}
	closedir(dir);
}
