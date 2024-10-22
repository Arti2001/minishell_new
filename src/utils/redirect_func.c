/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:49:20 by amysiv            #+#    #+#             */
/*   Updated: 2024/10/22 19:32:04 by amysiv           ###   ########.fr       */
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

void	redirect_heredoc(t_redirect redirect)
{
	int		fd[2];
	char	*eof;
	char	*line;
	
	eof = redirect.filename;
	line = NULL;
	if (pipe(fd) == -1)
	{
		perror("pipe in herdoc error");
		return ;
	}
	while (1)
	{
		line = readline(">");
		if (line == NULL || ft_strncmp(line, eof, ft_strlen(eof)) == 0)
		{
			free(line);
			break;
		}
		write(fd[1], line, ft_strlen(line));
		write(fd[1], "\n", 1);
		free(line);
	}
	close(fd[1]);
	if (ft_strncmp(redirect.filename, "c", 1) == 0)
		if (dup2(fd[0], STDIN_FILENO) == -1)
		{
			perror("redirect in heredoc error!");
			return ;
		}
	close(fd[0]);
}

void	redirect_check(t_pars *pars)
{
	int		i;
	
	i = 0;
	while (pars->redirections[i].filename != NULL)
	{
		if (pars->redirections[i].type == HEREDOC)
		{
			redirect_heredoc(pars->redirections[i]);
		}
		else if(pars->redirections[i].type == OUT)
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
