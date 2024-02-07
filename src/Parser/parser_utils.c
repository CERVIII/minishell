/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:07:10 by pcervill          #+#    #+#             */
/*   Updated: 2024/02/07 12:57:27 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	count_pipes(t_token *lexer, t_tools *tools)
{
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

int	count_arg(t_token *lexer)
{
	int	i;

	i = 0;
	while (lexer && lexer->type != PIPE)
	{
		if (lexer->type == WORD)
			i++;
		lexer = lexer->next;
	}
	return (i);
}

void	print_parser_tools(t_parser_tools *tools)
{
	printf("\n%sParser tools%s\n", GREEN_BOLD, NORMAL);
	printf("%sNumber of redirections: %d%s\n", BLUE_BOLD, tools->num_redirections, NORMAL);
	printf("\n%sRedirections:%s\n", BLUE_BOLD, NORMAL);
	print_tokens(tools->redirections);
	printf("%s\nLexer:%s\n", RED_BOLD, NORMAL);
	print_tokens(tools->lexer);
}
