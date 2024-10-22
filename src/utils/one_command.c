/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_command->c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student->42->fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:53:53 by amysiv            #+#    #+#             */
/*   Updated: 2024/10/05 15:37:52 by amysiv           ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* This function runs small child proccess and executes given command-> */
void	new_proccess(t_pars *pars, t_env *env, t_exec	*execute)
{
	char	**env_array;
	pid_t	pid;
	
	env_array = back_to_array(env);
	pid = fork();
	if (pid == -1)
	{
		perror("pid filed");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		execve(execute->true_path, pars->commands, env_array);
		ft_putstr_fd(pars->commands[0], 2);
		ft_putendl_fd(": command not found", 2);
		double_array_free(pars->commands);
		free(execute->true_path);
		exit(127);
	}
	waitpid(pid, NULL, 0);
	
}

char	**env_split_path(t_env **env)
{
	char *path;
	
	path = get_path("PATH", *env);
	path = ft_strchr(path, '/');
	return (ft_split(path, ':'));
}

void matching_pathes(t_exec *holds, char *check_path)
{
	int		i;

	i = 0;
	while (holds->all_pathes[i])
	{
		holds->temp_path = ft_strjoin(holds->all_pathes[i], "/");
		holds->true_path = ft_strjoin(holds->temp_path, check_path);
		if (access(holds->true_path, X_OK | F_OK) == 0)
		{
			free(holds->temp_path);
			return ;
		}
			i++;
			free (holds->temp_path);
	}
}

void	*run_command(t_pars *pars, t_env *env)
{
	t_exec holds;

	if (pars->commands == NULL)
		return (NULL);
	if(pars->redirections != NULL)
		redirect_check(pars);
	if (access(pars->commands[0], X_OK | F_OK) == 0)
	{
		holds.true_path = pars->commands[0];
		new_proccess(pars, env, &holds);
		return (NULL);
	}
	holds.all_pathes = env_split_path(&env);
	if (holds.all_pathes == NULL)
		return (NULL);
	matching_pathes(&holds, pars->commands[0]);
	double_array_free(holds.all_pathes);
	new_proccess(pars, env,  &holds);
	dup2(pars->orig_in, STDIN_FILENO);
	close(pars->orig_in);
	dup2(pars->orig_out, STDOUT_FILENO);
	close(pars->orig_out);
	return (NULL);
}
