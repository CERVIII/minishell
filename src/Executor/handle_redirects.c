/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:52:57 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/04/23 12:55:03 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	check_ambiguous(t_token *token)
{
	char	**aux;
	int		i;

	i = 0;
	aux = ft_split(token->token, ' ');
	while (aux[i])
		i++;
	free_str(aux);
	if (i >= 2)
		return (1);
	return (0);
}

int	check_fd_out(t_token *redirection)
{
	int	fd;

	if (redirection->type == RREDIR)
		fd = open(redirection->token, O_CREAT | O_RDWR | O_APPEND, 0644);
	else
		fd = open(redirection->token, O_CREAT | O_RDWR | O_TRUNC, 0644);
	return (fd);
}

int	ft_infile(char *str, int g_error)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		g_error = 1;
		return (g_error);
	}
	if (dup2(fd, STDIN_FILENO) < 0)
	{
		perror("Error");
		return (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	ft_outfile(t_token *redirection, int g_error)
{
	int	fd;

	fd = check_fd_out(redirection);
	if (fd < 0)
	{
		perror("Error");
		g_error = 1;
		return (g_error);
	}
	if (fd > 0 && dup2(fd, STDOUT_FILENO) < 0)
	{
		perror("Error");
		return (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	handle_redirects(t_simple_cmds *cmds, int g_error)
{
	t_token	*aux;

	aux = cmds->redirections;
	while (aux)
	{
		if (check_ambiguous(aux) != 0)
			return (ft_redirect_error(aux->token));
		if (aux->type == REDIR_IN)
		{
			if (ft_infile(aux->token, g_error))
				return (EXIT_FAILURE);
		}
		else if (aux->type == REDIR_OUT || aux->type == RREDIR)
		{
			if (ft_outfile(aux, g_error))
				return (EXIT_FAILURE);
		}
		else if (aux->type == HERE_DOC)
		{
			if (ft_infile(cmds->hd_file_name, g_error))
				return (EXIT_FAILURE);
		}
		aux = aux->next;
	}
	return (EXIT_SUCCESS);
}
