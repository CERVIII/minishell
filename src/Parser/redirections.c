/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:01:32 by pcervill          #+#    #+#             */
/*   Updated: 2024/02/29 11:44:53 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*token_new_cmd(char *str, int token)
{
	t_token		*new;
	static int	i = 0;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->token = ft_strdup(str);
	new->type = token;
	new->i = i++;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	new_redirection(t_token *tmp, t_parser_tools *parser_tools)
{
	t_token	*node;
	int		index_1;
	int		index_2;

	node = token_new_cmd(tmp->next->token, tmp->type);
	if (!node)
		return ; // falta funcion error
	ft_add_token_last(&parser_tools->redirections, node);
	index_1 = tmp->i;
	index_2 = tmp->next->i;
	ft_lexerdelone(&parser_tools->lexer, tmp->next->i);
	ft_lexerdelone(&parser_tools->lexer, tmp->i);
	parser_tools->num_redirections++;
}

void	redirection_add(t_parser_tools *parser_tools)
{
	t_token	*tmp;

	tmp = parser_tools->lexer;
	while (tmp && tmp->type == WORD)
		tmp = tmp->next;
	if (!tmp || tmp->type == PIPE)
		return ;
	if (tmp->type >= REDIR_IN && tmp->type <= HERE_DOC)
		new_redirection(tmp, parser_tools);
	redirection_add(parser_tools);
}
