/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:56:16 by amysiv            #+#    #+#             */
/*   Updated: 2024/08/08 14:57:51 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_built_in(char *command)
{
		if (ft_strncmp(command, "pwd", 4) == 0)
			ft_pwd();
		//if (ft_strncmp(command, "cd", 3))
		//	//todo
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

int main()
{
	char *command;

	while (1)
	{
		command = readline("Minishell>");
		if (command == NULL)
			break;
		add_history(command);
		check_built_in(command);
		
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