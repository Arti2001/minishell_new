/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:53:53 by amysiv            #+#    #+#             */
/*   Updated: 2024/09/06 13:43:07 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

//void	new_proccess(char **arg, t_env **env)
//{
//	char **env_array;
//	pid_t	pid;
	
//	env_array = back_to_array(env);
//	pid = fork();
//	if (pid == 0)
//	{
//		execve(arg[0], arg, env_array);
//		exit(1);
//	}
//	waitpid(pid, NULL, 0);
//	return ;
//}

//int	access_cheker(char *arg)
//{
//	if (access(arg, X_OK | F_OK) == 0)
//	{
//		return (0);
//	}
//	return (1);
//}

//char *find_path(t_env **env)
//{
//	char *path;
	
//	path = get_path("PATH", *env);
//	path = ft_strchr(path, '/');
//	return (ft_strdup(path));
//}

//void one_cmd(char **arg, t_env **env)
//{
//	int 	i;
//	char *path;

	
//	i = 0;
//	if (arg == NULL)
//		return (NULL);
//	if (access_cheker(arg[i]) == 0)
//		new_proccess(arg, env);
//	path = find_path(env);
	
		
	
//}