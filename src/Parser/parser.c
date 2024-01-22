/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:02:28 by pcervill          #+#    #+#             */
/*   Updated: 2024/01/22 18:12:04 by pcervill         ###   ########.fr       */
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

t_token	*ft_lexerclear_one(t_token **tmp)
{
	if ((*tmp)->token)
	{
		free((*tmp)->token);
		(*tmp)->token = NULL;
	}
	free((*tmp));
	*tmp = NULL;
	return (NULL);
}

void	ft_lexerdel_first(t_token **lexer)
{
	t_token	*tmp;

	tmp = *lexer;
	*lexer = tmp->next;
	ft_lexerclear_one(&tmp);
	if (*lexer)
		(*lexer)->prev = NULL;
}

void	ft_lexerdelone(t_token **lexer, int key)
{
	t_token	*tmp;
	t_token	*start;
	t_token	*prev;

	start = *lexer;
	tmp = start;
	if ((*lexer)->i == key)
	{
		ft_lexerdel_first(lexer);
		return ;
	}
	while (tmp && tmp->i != key)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp)
		prev->next = tmp->next;
	else
		prev->next = NULL;
	if (prev->next)
		prev->next->prev = prev;
	ft_lexerclear_one(&tmp);
	*lexer = start;
}

void	parser(t_tools *tools)
{
	count_pipes(tools->lexer, tools);
	printf("Number of pipes: %d\n", tools->pipes);
	while (tools->lexer)
	{
		if (tools->lexer && tools->lexer->type == PIPE)
			ft_lexerdelone(&tools->lexer, tools->lexer->i);
		tools->lexer = tools->lexer->next;
	}
}
