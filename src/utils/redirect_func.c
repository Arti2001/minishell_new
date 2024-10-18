/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:49:20 by amysiv            #+#    #+#             */
/*   Updated: 2024/10/18 21:14:44 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	redirect_in(t_redirect redirect)
{
	int	file_fd;

	file_fd = open(redirect.filename, O_RDONLY);
	if (file_fd == -1)
	{
		perror("can't open an infile");
		exit(EXIT_FAILURE);
	}
	dup2(file_fd, STDIN_FILENO);
	close(file_fd);
}

void	redirect_out(t_redirect redirect)
{
	int	file_fd;

	file_fd = open(redirect.filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (file_fd == -1)
	{
		perror("can't open an outfile");
		exit(EXIT_FAILURE);
	}
	dup2(file_fd, STDOUT_FILENO);
	close(file_fd);
}


void	redirect_outappend(t_redirect redirect)
{
	int	file_fd;

	file_fd = open(redirect.filename, O_CREAT | O_APPEND | O_RDWR, 0644);
	if (file_fd == -1)
	{
		perror("can't open an outfile");
		exit(EXIT_FAILURE);
	}
	dup2(file_fd, STDOUT_FILENO);
	close(file_fd);
}


void	redirect_check(t_pars *pars)
{
	int		i;
	
	i = 0;
	while (pars->redirections[i].filename != NULL)
	{
		//if (pars->redirections[i].type == HEREDOC)
		//{
			
		//}
		if (pars->redirections[i].type == OUT)
		{
			redirect_out(pars->redirections[i]);
		}
		else if (pars->redirections[i].type == IN)
		{
			redirect_in(pars->redirections[i]);
		}
		else if (pars->redirections[i].type == OUT_APPEND)
		{
			redirect_outappend(pars->redirections[i]);
		}
		i++;
	}
}
