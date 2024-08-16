/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:56:16 by amysiv            #+#    #+#             */
/*   Updated: 2024/08/16 17:58:32 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_built_in(t_env *env)
{
		t_pars	*pars;
		
		if (ft_strncmp(pars->commands[0], "pwd", 4) == 0)
			ft_pwd();
		if (ft_strncmp(pars->commands[0], "cd", 3))
			ft_cd(env);
		//if (ft_strncmp(command, "echo", 5))
		//	//todo
		//if (ft_strncmp(command, "export", 7))
		//	//todo
		//if (ft_strncmp(command, "unset", 6))
		//	//todo;
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
	int			i;

	i = 0;
	if (argc == 1  && argv[0])
	{
		env = set_env(envp);
		while (1)
		{
			input = readline("Minishell>");
			if (input == NULL)
				break;
			add_history(input);
			pars.commands = ft_split(input, ' ');
			if (argc == 3)
				check_built_in(env);
			i++;
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