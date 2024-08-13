/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:56:16 by amysiv            #+#    #+#             */
/*   Updated: 2024/08/13 17:38:20 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_built_in(t_pars *my_env)
{

		if (ft_strncmp(my_env->command[0], "pwd", 3) == 0)
			ft_pwd();
		if (ft_strncmp(my_env->command[0], "cd", 2) == 0)
			ft_cd(my_env);
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

void 	set_env(char **envp)
{
	int	i;

	i = 0;
	while(envp[i])
	{
		ft_env_lstnew(envp[i]);
		i++
	}
	
}

int main(int argc, char *argv[], char *envp[])
{
	char *command;
	//t_pars	my_env;
	
	
	if (argc == 1  && argv[0])
	{
		set_env(envp);
		//my_env.cp_env = envp;
		//while (1)
		//{
		//	command = readline("Minishell>");
		//	if (command == NULL)
		//		break;
		//	add_history(command);
		//	my_env.command = ft_split(command, ' ');
		//	check_built_in(&my_env);
			
		//}
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
//	struct dirent* entity;
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