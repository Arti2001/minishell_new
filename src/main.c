/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/08 12:56:16 by amysiv        #+#    #+#                 */
/*   Updated: 2024/10/03 13:53:08 by ydidenko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
			pars.commands = ft_split(input, ' ');
			free(input);
			ret = check_built_in(&env, pars.commands);
			//if (ret  == NO_BUILTIN)
			//	one_cmd(pars.commands, &env);
			//else
		}
				return (ret);
	}
	return (0);
}
