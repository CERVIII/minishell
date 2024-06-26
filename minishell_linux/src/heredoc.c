/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:33:22 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/04/24 11:21:55 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

int	handle_heredoc(t_token *heredoc, char *file, int g_error, t_tools *tools)
{
	int		fd;
	char	*line;
	char	*key_word;

	(void) g_error;
	g_signal = HEREDOC_CODE;
	key_word = delete_quotes(ft_strdup(heredoc->token), 0, 0);
	if (ft_strlen(key_word) == ft_strlen(heredoc->token))
		line = expander_str(readline("heredoc > "), tools);
	else
		line = readline("heredoc > ");
	fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	while (line && ft_strncmp(key_word, line, ft_strlen(key_word) + 2)
		&& g_signal == HEREDOC_CODE)
	{
		(write(fd, line, ft_strlen(line)), free(line), write(fd, "\n", 1));
		line = readline("heredoc > ");
		if (line && ft_strlen(key_word) == ft_strlen(heredoc->token)
			&& ft_strcmp(line, key_word) != 0)
			line = expander_str(line, tools);
	}
	if (!line)
		return ((free(line), free(key_word), EXIT_FAILURE));
	return ((free(line), free(key_word), close(fd), EXIT_SUCCESS));
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
			if (handle_heredoc(cmds->redirections, cmds->hd_file_name,
					tools->g_error, tools) != 0)
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
