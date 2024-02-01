/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:07:10 by pcervill          #+#    #+#             */
/*   Updated: 2024/02/01 15:07:37 by pcervill         ###   ########.fr       */
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

void	print_simple_cmd(t_simple_cmds *cmd)
{
	while (cmd)
	{
		int	i;
	
		printf("\n%sSimple command%s\n", GREEN_BOLD, NORMAL);
		printf("%sNumber of redirections: %d%s\n", BLUE_BOLD, cmd->num_redirections, NORMAL);
		printf("\n%sRedirections:%s\n", BLUE_BOLD, NORMAL);
		print_tokens(cmd->redirections);
		printf("\n%sArguments:%s\n", BLUE_BOLD, NORMAL);
		i = 0;
		while (cmd->str[i])
			printf("%s\n", cmd->str[i++]);
		cmd = cmd->next;
	}
}
