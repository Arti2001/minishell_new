/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:16:30 by amysiv            #+#    #+#             */
/*   Updated: 2024/09/04 16:03:58 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


char	*get_path(char *name, t_env *env)
{
	while (env != NULL)
	{
		if (ft_strncmp(env->name, name, ft_strlen(name)) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

void	change_cwd(t_env *env, char *str)
{
	ch_env_value(env, "OLDPWD", getcwd(NULL, 0));
	chdir(str);
	ch_env_value(env, "PWD", getcwd(NULL, 0));
}

int	ft_cd(t_env *env, char **arg)
{
	DIR	*dir; 
	char *home;
	
	if (arg[1] == NULL)
	{
		home = get_path("HOME", env);
		if (home == NULL)
			return (printf("bash: cd: HOME not set\n"), 1);
		return (change_cwd(env, home), 0);
	}
	if (arg[2] != NULL)
		return (ft_putendl_fd("bash: cd: too many arguments", 2), 1);
	dir = opendir(arg[1]);
	if (access(arg[1], F_OK ) == 0 && (dir != NULL))
		return (change_cwd(env, arg[1]), 0);
	if (access(arg[1], F_OK) == -1)
		return (printf("bash: %s: %s: No such file or directory\n", arg[0], arg[1]), 1);
	if (dir == NULL)
	{
		printf("bash: %s: %s: Not a directory\n", arg[0], arg[1]);
		return (closedir(dir), 1);
	}
	closedir(dir);
	return (0);
}


