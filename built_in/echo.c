/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:17:34 by amysiv            #+#    #+#             */
/*   Updated: 2024/08/24 15:48:32 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo(char **commands)
{
	int i;
	
	i = 1;
	if (commands[1] == NULL)
	{
		ft_putstr_fd("\n", 1);
		return ;
	}
	else if(check_new_line(commands[1]) == 1)
	{
		i = 2;
		while (commands[i])
		{
			ft_putstr_fd(commands[i], 1);
			if ((commands[i + 1]) != NULL)
				write(1, " ", 1);
			i++;
		}
	}
	else
		while (commands[i])
		{
			if ((commands[i + 1]) != NULL)
			{
				ft_putstr_fd(commands[i], 1);
				write(1, " ", 1);	
			}
			else
				ft_putendl_fd(commands[i], 1);
			i++;
		}
	return ;
}

int	check_new_line(char *str)
{
	if ((*(str + 0) == '-') && (*(str + 1) == 'n'))
		str++;
	while (*str)
	{
		if (*(str + 0) == 'n')
			str++;
		else
		{
			return (0);	
		}
	}
	return (1);
}
