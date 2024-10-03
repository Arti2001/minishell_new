/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:53:53 by amysiv            #+#    #+#             */
/*   Updated: 2024/10/03 17:34:35 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	new_proccess(char *path, char **arg, t_env *env)
{
	char **env_array;
	pid_t	pid; 
	
	env_array = back_to_array(env);
	pid = fork();
	if (pid == -1)
	{
		perror("pid filed");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		execve(path, arg, env_array);
	waitpid(pid, NULL, 0);
	return ;
}

int	access_cheker(char *arg)
{
	if (access(arg, X_OK | F_OK) == 0)
	{
		return (0);
	}
	return (1);
}

char **env_split_path(t_env **env)
{
	char *path;
	
	path = get_path("PATH", *env);
	path = ft_strchr(path, '/');
	return (ft_split(path, ':'));
}

char *matching_pathes(char **all_pathes, char *check_path)
{
	int		i;
	char	*path;

	i = 0;
	
	while (all_pathes[i])
	{
		path = ft_strjoin(all_pathes[i], "/");
		path = ft_strjoin(path, check_path);
		if (access(path, X_OK | F_OK) == 0)
			return (path);
		else
		{
			i++;
			free (path);
		}
	}
	return (NULL);
}

void *one_cmd(char **arg, t_env *env)
{
	t_exec holds;
	int 	i;
	
	i = 0;
	if (arg == NULL)
		return (NULL);
	if (access_cheker(arg[i]) == 0)
	{
		new_proccess( arg[0], arg, env);
	}
	holds.all_pathes = env_split_path(&env);
	if (holds.all_pathes == NULL)
		return (NULL);
	holds.true_path = matching_pathes(holds.all_pathes, arg[i]);
	double_array_free(holds.all_pathes);
	new_proccess(holds.true_path, arg, env);
	return NULL;
}