/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:02:28 by pcervill          #+#    #+#             */
/*   Updated: 2024/01/09 12:27:11 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_simple_cmds	*ft_new_parser_node(t_token *lexer)
{
	t_simple_cmds	*new;

	new = (t_simple_cmds *)malloc(sizeof(t_simple_cmds));
	if (!new)
		return (NULL);
	while (lexer->type != PIPE)
	{
		if (lexer->type == WORD)
			new->str = ft_split(lexer->token, " ");
		else if (lexer->type == REDIR_IN)
			new->str = ft_split(lexer->token, "<");
		else if (lexer->type == REDIR_OUT)
			new->str = ft_split(lexer->token, ">");
		else if (lexer->type == RREDIR)
			new->str = ft_split(lexer->token, ">>");
		else if (lexer->type == HERE_DOC)
			new->str = ft_split(lexer->token, "<<");
		else if (lexer->type == SINGLE_QUOTE)
			new->str = ft_split(lexer->token, "\'");
		else if (lexer->type == DOUBLE_QUOTE)
			new->str = ft_split(lexer->token, "\"");
	}
}

char	**ft_redirection(t_token *lexer)
{
	
}


void	create_parser(t_token *lexer, t_simple_cmds **parser)
{
	t_simple_cmds	*new;

	new = NULL;
	while (lexer->next != NULL)
	{
		if (lexer->type == PIPE)
			new = ft_new_parser_node(lexer);
			ft_add_node_last(parser, new);
			free(new);

	}
}
