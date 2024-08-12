/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:16:30 by amysiv            #+#    #+#             */
/*   Updated: 2024/08/12 11:35:19 by amysiv           ###   ########.fr       */
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
void	ft_cd(t_pars *my_env)
{
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
		chdir("..");
}