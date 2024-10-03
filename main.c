/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:56:16 by amysiv            #+#    #+#             */
/*   Updated: 2024/10/03 13:30:57 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"





/*check_built_in() checks if it is a built in, if so ,  calls the coresponding built in function*/
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

/*This is a temporary parsing. Below in the main() I read the input from the console, then  I split it with the ft_split function
and initialize the temporary struct init_temp_struct() which should contain the data for exexution (such as redirections, amount of pipes, heredoc) */
void	init_temp_struct(char *input, t_pars *pars)
{
	pars->commands = ft_split(input, ' ');
	pars->infile = NULL;
	pars->outfile = NULL;
	pars->cmd_counter = 1;
}

int main(int argc, char *argv[], char *envp[])
{
	char		*input;
	t_env		*env;
	t_pars		pars;	
	int			ret;
	
	if (argc == 1  && argv[0])
	{
		env = set_env(envp);
		while (1)
		{
			input = readline("Minishell>");
			if (input == NULL)
				return 1;
			add_history(input);
			init_temp_struct(input, &pars);
			free(input);
			if (pars.cmd_counter == 1)
			{
				ret = check_built_in(&env, pars.commands);
				if (ret == NO_BUILTIN)
					one_cmd(pars.commands, env);
			}
		}
				return (ret);
	}
	return (0);
}

/*-There is a bug in export: 
can't store the var with value containing  space, because I split the input by space in the begining.*/