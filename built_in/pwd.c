/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:30:47 by amysiv            #+#    #+#             */
/*   Updated: 2024/08/11 13:43:09 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(void)
{
	char *path;
	
	path = getcwd(NULL, 0);
	if (path != NULL)
		ft_putendl_fd(path, 1);
	else
		ft_putendl_fd("Error : getcwd()", 2);
}
