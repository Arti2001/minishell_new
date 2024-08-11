/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:16:30 by amysiv            #+#    #+#             */
/*   Updated: 2024/08/11 15:00:38 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_cd(char * relative, char *absolute, t_env my_env)
{
	int		i;
	char	*home_path;
	
	i = 0;
	
	while (my_env.cp_env[i])
	{
		if (ft_strncmp(my_env.cp_env[i], "HOME", 4) == 0)
		{
			home_path = ft_strchr(my_env.cp_env[i], '/');
			break;
		}
		i++;
	}
	if (relative == NULL && absolute == NULL)
		chdir(home_path);
	if (absolute != NULL)
		chdir(absolute);
	
}