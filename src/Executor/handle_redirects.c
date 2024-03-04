/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:52:57 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/03/04 14:45:34 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int check_fd_out(t_token *redirection)
{
	int fd;

	if (redirection->type == RREDIR)
		fd = open(redirection->token, O_CREAT | O_RDWR | O_APPEND, 0644);
	else
		fd = open(redirection->token, O_CREAT | O_RDWR | O_TRUNC, 0644);
	return (fd);
}

int	ft_infile(char *str)
{
	int fd;
	
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		g_error = 1;
		return (EXIT_FAILURE);
	}
	if (dup2(fd, STDIN_FILENO) < 0)
	{
		perror("Error");
		return (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	ft_outfile(t_token *redirection)
{
	int fd;

	fd = check_fd_out(redirection);
	if (fd < 0)
	{
		perror("Error");
		g_error = 1;
		return (EXIT_FAILURE);
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
	{
		perror("Error");
		return (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	handle_redirects(t_token *redirects)
{
	t_token	*aux;

	aux = redirects;
	while (aux)
	{
		if (aux->type == REDIR_IN)
		{
			if (ft_infile(aux->token))
				return (EXIT_FAILURE);
		}
		else if (aux->type == REDIR_OUT || aux->type == RREDIR)
		{
			if (ft_outfile(aux))
				return (EXIT_FAILURE);
		}
		//TODO: <<
		// if (aux->token == RREDIR)
		aux = aux->next;
	}
	return (EXIT_SUCCESS);
}
