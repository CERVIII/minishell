/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:33:22 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/04/15 17:12:31 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	delete_files(t_tools *tools)
{
	int		i;
	char	*name;
	char	*num;
	t_tools	*aux;

	i = 0;
	aux = tools;
	while (i <= tools->n_heredoc)
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

int	handle_heredoc(t_token *heredoc, char *file, int g_error)
{
	int		fd;
	char	*line;
	int		line_len;
	char	*key_word;

	g_signal = HEREDOC_CODE;
	key_word = delete_quotes(heredoc->token);
	line = readline("heredoc > ");
	line_len = ft_strlen(key_word) + 1;
	fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	while (line && ft_strncmp(key_word, line, line_len + 1)
		&& g_signal == HEREDOC_CODE)
	{
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
		line = readline("heredoc > ");
	}
	free(line);
	if (g_error == 1)
		return (EXIT_FAILURE);
	close(fd);
	return (EXIT_SUCCESS);
}

char	*ft_heredoc_name(t_tools *tools)
{
	static int	i = 0;
	char		*name;
	char		*num;

	num = ft_itoa(i);
	name = ft_strjoin(".tmp_heredoc_", num);
	free(num);
	tools->n_heredoc = i++;
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
			cmds->hd_file_name = ft_heredoc_name(tools);
			if (handle_heredoc(cmds->redirections, cmds->hd_file_name, tools->g_error) != 0)
			{
				g_signal = 0;
				tools->g_error = 1;
				free_tools(tools);
				return (EXIT_FAILURE);
			}
		}
		cmds->redirections = cmds->redirections->next;
	}
	cmds->redirections = aux;
	return (EXIT_SUCCESS);
}
