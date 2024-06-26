/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:09:52 by pcervill          #+#    #+#             */
/*   Updated: 2024/04/24 11:21:42 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_err(char *msg, int nb, t_tools *tools)
{
	printf("%s%s%s\n", RED, msg, NORMAL);
	free_tools(tools);
	return (nb);
}

void	free_tools(t_tools *tools)
{
	if (tools->arg)
		free(tools->arg);
	if (tools->lexer)
		free_lexer(tools->lexer);
	if (tools->parser)
		free_parser(tools->parser);
	if (tools->n_heredoc + 1 > 0)
		delete_files(tools);
	if (tools->pipes > 0)
		free(tools->pid);
	init_tools(tools);
	tools->reset = true;
	minishell_loop(tools);
}

void	free_lexer(t_token *lexer)
{
	t_token	*tmp;
	t_token	*tmp2;

	tmp = lexer;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp->token);
		free(tmp);
		tmp = tmp2;
	}
	lexer = NULL;
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	str = NULL;
}

void	free_parser(t_simple_cmds *parser)
{
	t_simple_cmds	*tmp;
	t_simple_cmds	*tmp2;

	tmp = parser;
	while (tmp)
	{
		tmp2 = tmp->next;
		if (tmp->str)
			free_str(tmp->str);
		if (tmp->redirections)
		{
			free_lexer(tmp->redirections);
			tmp->redirections = NULL;
		}
		free(tmp->hd_file_name);
		tmp->hd_file_name = NULL;
		free(tmp);
		tmp = tmp2;
	}
	parser = NULL;
}
