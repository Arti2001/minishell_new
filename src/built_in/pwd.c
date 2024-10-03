/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/07 15:30:47 by amysiv        #+#    #+#                 */
/*   Updated: 2024/10/03 13:46:16 by ydidenko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(void)
{
	char *path;

	path = getcwd(NULL, 0);
	if (path != NULL)
		ft_putendl_fd(path, 1);
	else
		ft_putendl_fd("Error : getcwd()", 2);
	return (0);
}
