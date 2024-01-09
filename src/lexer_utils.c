/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:40:37 by pcervill          #+#    #+#             */
/*   Updated: 2024/01/08 16:23:40 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_token	*ft_token_new(char *token)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->token = ft_strdup(token);
	if (!ft_strcmp(new->token, "|"))
		new->type = PIPE;
	else if (!ft_strcmp(new->token, "<"))
		new->type = REDIR_IN;
	else if (!ft_strcmp(new->token, ">"))
		new->type = REDIR_OUT;
	else if (!ft_strcmp(new->token, ">>"))
		new->type = RREDIR;
	else if (!ft_strcmp(new->token, "<<"))
		new->type = HERE_DOC;
	else if (!ft_strcmp(new->token, "\'"))
		new->type = SINGLE_QUOTE;
	else if (!ft_strcmp(new->token, "\""))
		new->type = DOUBLE_QUOTE;
	else
		new->type = WORD;
	new->next = NULL;
	return (new);
}

void	ft_add_token_last(t_token **token, t_token *new)
{
	t_token	*current;

	if (!token || !new)
		return ;
	if (*token == NULL)
		*token = new;
	else
	{
		current = *token;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	return ;
}

void	ft_free_token(t_token **token)
{
	t_token	*tmp;
	t_token	*tmp2;

	if (!token)
		return ;
	tmp = *token;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp->token);
		free(tmp);
		tmp = tmp2;
	}
	return ;
}
