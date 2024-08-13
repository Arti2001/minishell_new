/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:16:30 by amysiv            #+#    #+#             */
/*   Updated: 2024/08/13 13:40:01 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *env_path(char *name, t_pars *my_env)
{
	int		i;
	char	*path;

	i = 0;
	while (my_env->cp_env[i])
	{
		if (ft_strncmp(my_env->cp_env[i], name, ft_strlen(name)) == 0)
		{
			path = ft_strchr(my_env->cp_env[i], '/');
			break;
		}
		i++;
	}
	return (path);
}
//int	t_len(char **array)
//{
//	int i;

//	i = 0;

//	while(array[i])
//	{
//		i++;
//	}
//	return (i);
//}
void	ft_cd(t_pars *my_env)
{
	if (my_env->command[2] != NULL)
		ft_putendl_fd("bash: cd: too many arguments", 2);
	if (my_env->command[0][2] != '\0')
	{
		ft_putstr_fd("Command '", 2);
		ft_putstr_fd(my_env->command[0], 2);
		ft_putendl_fd("' not found", 2);
	}
	if (my_env->command[1]== NULL)
	{
		chdir(env_path("HOME", my_env));
		return ;
	}
	if (ft_strncmp(my_env->command[1], ".", 1) == 0)	
		chdir(".");
	if (ft_strncmp(my_env->command[1], "..", 2) == 0)
	{
		chdir("..");
		return ;
	}
	if (access(my_env->command[1], F_OK) == 0)
		chdir(my_env->command[1]);
}
