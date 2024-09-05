/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:56:16 by amysiv            #+#    #+#             */
/*   Updated: 2024/09/05 08:33:02 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	access_cheker(char *arg)
{
	if (access(arg, X_OK | F_OK) == 0)
	{
		return (0);
	}
	return (1);
}


void	new_proccess(char **arg, t_env **env)
{
	char **env_array;
	pid_t	pid;
	
	env_array = back_to_array(env);
	pid = fork();
	if (pid == 0)
	{
		execve(arg[0], arg, env_array);
		exit(1);
	}
	waitpid(pid, NULL, 0);
	return ;
}



int	check_built_in(t_env **env, char **arg)
{
	if (ft_strncmp("cd", arg[0], ft_strlen(arg[0])) == 0)
		return (ft_cd(*env, arg));
	if (ft_strncmp("pwd", arg[0], ft_strlen(arg[0])) == 0)
		return (ft_pwd());
	if (ft_strncmp("env", arg[0], ft_strlen(arg[0])) == 0)
		return (ft_env(*env));
	if (ft_strncmp("echo", arg[0], ft_strlen(arg[0])) == 0)
		return (ft_echo(arg));
	if (ft_strncmp("exit", arg[0], ft_strlen(arg[0])) == 0)
		ft_exit(arg);
	if (ft_strncmp("unset", arg[0], ft_strlen(arg[0])) == 0)
		return (ft_unset(env, arg));
	if (ft_strncmp("export", arg[0], ft_strlen(arg[0])) == 0)
		return (ft_export(*env, arg));
	return (NO_BUILTIN);
}

int main(int argc, char *argv[], char *envp[])
{
	char		*input;
	t_pars		pars;
	t_env		*env;
	
	if (argc == 1  && argv[0])
	{
		env = set_env(envp);
		while (1)
		{
			input = readline("Minishell>");
			if (input == NULL)
				return 1;
			add_history(input);
			pars.commands = ft_split(input, ' ');
			free(input);
			check_built_in(&env, pars.commands);
		}
	}
	return (0);
}
