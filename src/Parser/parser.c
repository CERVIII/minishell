/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:02:28 by pcervill          #+#    #+#             */
/*   Updated: 2024/01/30 14:50:58 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	parser_double_token(t_tools *tools, t_token *lexer)
{
	if (lexer->type == REDIR_IN)
		ft_err("Error: Syntax error near unexpected token '<'\n",
			STDERR_FILENO, tools);
	else if (lexer->type == REDIR_OUT)
		ft_err("Error: Syntax error near unexpected token '>'\n",
			STDERR_FILENO, tools);
	else if (lexer->type == RREDIR)
		ft_err("Error: Syntax error near unexpected token '>>'\n",
			STDERR_FILENO, tools);
	else if (lexer->type == HERE_DOC)
		ft_err("Error: Syntax error near unexpected token '<<'\n",
			STDERR_FILENO, tools);
	else if (lexer->type == PIPE)
		ft_err("Error: Syntax error near unexpected token '|'\n",
			STDERR_FILENO, tools);
}

void	parser(t_tools *tools)
{
	t_token	*cpy;

	cpy = tools->lexer;
	count_pipes(tools->lexer, tools);
	if (tools->lexer->type == PIPE)
		parser_double_token(tools, tools->lexer);
	printf("\n%sNumber of pipes: %d%s\n", GREEN_BOLD, tools->pipes, NORMAL);
	while (cpy)
	{
		if (cpy && cpy->type == PIPE)
		{
			ft_lexerdelone(&tools->lexer, cpy->i);
			cpy = tools->lexer;
		}
		cpy = cpy->next;
	}
}
