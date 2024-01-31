/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:07:10 by pcervill          #+#    #+#             */
/*   Updated: 2024/01/31 13:52:47 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	count_pipes(t_token *lexer, t_tools *tools)
{
	t_token	*tmp;

	tmp = lexer;
	tools->pipes = 0;
	while (lexer)
	{
		if (lexer->type == PIPE)
			tools->pipes++;
		lexer = lexer->next;
	}
}

t_parser_tools	init_parser_tools(t_token *lexer, t_tools *tools)
{
	t_parser_tools	parser_tools;

	parser_tools.lexer = lexer;
	parser_tools.num_redirections = 0;
	parser_tools.redirections = NULL;
	parser_tools.tools = tools;
	return (parser_tools);
}

t_simple_cmds	*create_node_cmd(t_parser_tools *parser_tools)
{
	redirection_add(parser_tools);
}

t_simple_cmds	*new_node_cmd(t_parser_tools *parser_tools)
{
	t_simple_cmds	*node;

	node = (t_simple_cmds *)malloc(sizeof(t_simple_cmds));
	node->builtin = NULL;
	node->hd_file_name = NULL;
	node->num_redirections = parser_tools->num_redirections;
	node->redirections = parser_tools->redirections;
	node->str = NULL;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	print_parser_tools(t_parser_tools *tools)
{
	printf("\n%sParser tools%s\n", GREEN_BOLD, NORMAL);
	printf("Number of redirections: %d\n", tools->num_redirections);
	printf("Redirections:\n");
	print_tokens(tools->redirections);
	printf("Lexer:\n");
	print_tokens(tools->lexer);
}