/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:07:51 by pcervill          #+#    #+#             */
/*   Updated: 2024/02/08 12:57:18 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
//#include "../../include/parser.h"
//#include "../../include/lexer.h"

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
