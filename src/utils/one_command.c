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



//void	redirect(t_exec *give)
//{
//	if (dup2(give->fd_outfile, 1) == -1)
//	{
//		perror("dup2");
//		exit(EXIT_FAILURE);
//	}
//	close(give->fd_outfile);
//}
//void	openfile(t_exec *give, t_pars	*pars)
//{
//	if (pars->infile)
//	{
//		give->fd_infile = open(pars->infile, O_RDONLY);
//		if (give->fd_infile== -1)
//		{
//			perror("can't open the infile");
//			exit(EXIT_FAILURE);
//		}
//	}
//	else if (pars->outfile)
//	{
		
//		give->fd_outfile = open(pars->outfile, O_CREAT | O_TRUNC | O_WRONLY, 0644);
//		if (give->fd_outfile == -1)
//		{
//			perror("can't open the outfile");
//			exit(EXIT_FAILURE);
//		}
//	}
//	else
//		return;
//}
/* This function runs small child proccess and executes given command-> */
void	new_proccess(t_pars *pars, t_env *env, t_exec	*execute)
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
	{
		//if (pars->infile || pars->outfile)
		// openfile(execute, pars);
		//redirect(execute);
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

void	*one_cmd(t_pars *pars, t_env *env)
{
	t_exec holds;

	if (pars->commands == NULL)
		return (NULL);
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
	return (NULL);
}