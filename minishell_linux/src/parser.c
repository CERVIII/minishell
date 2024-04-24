/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:02:28 by pcervill          #+#    #+#             */
/*   Updated: 2024/04/24 11:22:10 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	parser_double_token(t_tools *tools, t_token *lexer)
{
	tools->g_error = 258;
	if (lexer->type == REDIR_IN)
		ft_err("Syntax error near unexpected token '<'\n",
			STDERR_FILENO, tools);
	else if (lexer->type == REDIR_OUT)
		ft_err("Syntax error near unexpected token '>'\n",
			STDERR_FILENO, tools);
	else if (lexer->type == RREDIR)
		ft_err("Syntax error near unexpected token '>>'\n",
			STDERR_FILENO, tools);
	else if (lexer->type == HERE_DOC)
		ft_err("Syntax error near unexpected token '<<'\n",
			STDERR_FILENO, tools);
	else if (lexer->type == PIPE)
	{
		ft_err("Syntax error near unexpected token '|'\n",
			STDERR_FILENO, tools);
	}
}

void	parser(t_tools *tools)
{
	t_simple_cmds	*node;
	t_parser_tools	parser_tools;

	count_pipes(tools->lexer, tools);
	if (tools->lexer->type == PIPE)
		parser_double_token(tools, tools->lexer);
	while (tools->lexer)
	{
		if (tools->lexer && tools->lexer->type == PIPE)
			ft_lexerdelone(&tools->lexer, tools->lexer->i);
		parser_tools = init_parser_tools(tools->lexer, tools);
		node = create_node_cmd(&parser_tools);
		if (!node)
			return ;
		if (!tools->parser)
			tools->parser = node;
		else
			add_back_cmd(&tools->parser, node);
		tools->lexer = parser_tools.lexer;
	}
}
