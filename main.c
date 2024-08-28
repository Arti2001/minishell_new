/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:56:16 by amysiv            #+#    #+#             */
/*   Updated: 2024/08/24 16:10:41 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_built_in(t_env *env, char **commands)
{
		
		if (ft_strncmp(commands[0], "cd", 3) == 0)
			ft_cd(env, commands);
		if (ft_strncmp(commands[0], "pwd", 4) == 0)
			ft_pwd();
		if (ft_strncmp(commands[0], "env", 4) == 0)
			ft_env(env);
		if (ft_strncmp(commands[0], "echo", 4) == 0)
			ft_echo(commands);
		if (ft_strncmp(commands[0], "export", 6) == 0)
			ft_export(env, commands);
		//if (ft_strncmp(command, "env", 4))
		//	//todo;
		//if (ft_strncmp(command, "exit", 5))
		//	//todo;
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
			check_built_in(env, pars.commands);
		}
	}
	return (0);
}















//int main(int argc, char *argv[])
//{
//	DIR*	dir;
//	char	*cwd;

//	dir = opendir("./new");//opens the directory passed as name.Returns the pointer to it.
//	if (dir == NULL)
//		return 1;
//	struct di= rent* entity;
//	entity = readdir(dir);// entry to the directory. Contains all meta data about files in the directory 
//	while(entity != NULL)
//	{
//		if (entity->d_type == 8)
//			printf("%d\n", entity->d_type);
//		printf("%s\n", entity->d_name);
//		printf("          \n");
//		entity = readdir(dir);
//	}

//	closedir(dir);
	
//	return 0;
//}