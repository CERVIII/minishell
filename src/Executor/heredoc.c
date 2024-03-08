/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:33:22 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/03/08 16:23:38 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//TODO: COMO GESTIONAR SEÑALES?
//TODO: BORRAR archivos tmp

void delete_files(t_tools *tools)
{
	int		i;
	char	*name;
	char	*num;
	t_tools *aux;

	i = 0;
	aux = tools;
	while(i <= tools->n_heredoc)
	{
		num = ft_itoa(i);
		name = ft_strjoin(".tmp_heredoc_", num);
		free(num);
		if (!access(name, F_OK))
			unlink(name);
		free(name);
		i++;
	}
	tools = aux;
}

int	handle_heredoc(t_tools *tools, t_token *heredoc, char *file)
{
	int		fd;
	char	*line;
	int		line_len;

	(void)tools;
	line = readline("heredoc > ");
	line_len = ft_strlen(heredoc->token) + 1;
	fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	while (line && ft_strncmp(heredoc->token, line, line_len + 1))
	{
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
		line = readline("heredoc > ");
	}
	free(line);
	if (!line)
	{
		ft_putstr_fd("\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

char	*ft_heredoc_name(void)
{
	static int	i = 0;
	char		*name;
	char		*num;

	num = ft_itoa(i);
	name = ft_strjoin(".tmp_heredoc_", num);
	free(num);
	i++;
	return (name);
}

int	check_heredoc(t_tools *tools, t_simple_cmds *cmds)
{
	t_token	*aux;

	aux = cmds->redirections;
	while (cmds->redirections)
	{
		if (cmds->redirections->type == HERE_DOC)
		{
			if (cmds->hd_file_name)
				free(cmds->hd_file_name);
			cmds->hd_file_name = ft_heredoc_name();
			tools->n_heredoc += 1;
			if (handle_heredoc(tools, cmds->redirections, cmds->hd_file_name) != 0)
			{
				g_error = 1;
				free_tools(tools);
				return (EXIT_FAILURE);
			}
		}
		cmds->redirections = cmds->redirections->next;
	}
	cmds->redirections = aux;
	return (EXIT_SUCCESS);
}
