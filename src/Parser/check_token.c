/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:50:22 by pcervill          #+#    #+#             */
/*   Updated: 2024/04/22 15:34:44 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_redirects(t_token **lst, t_tools *tools)
{
	if (((*lst)->type >= 2 && (*lst)->type <= 5)
		&& (!(*lst)->next || (*lst)->next->type != 0))
	{
		tools->g_error = 258;
		ft_err("Error: Syntax error near unexpected token 'newline'",
			258, tools);
		return (0);
	}
	return (1);
}

int	check_broken_pipes(t_token **lst, t_tools *tools)
{
	if ((*lst)->type == 1 && ((!(*lst)->next)
			|| ((*lst)->next->type != 0
				&& !((*lst)->next->type >= 2 && (*lst)->next->type <= 5))))
	{
		tools->g_error = 258;
		ft_err("Syntax error near unexpected token '|'\n", 127, tools);
		return (0);
	}
	return (1);
}

void	check_tokens(t_tools *tools, t_token **lst)
{
	if (!(*lst))
		return ;
	if ((*lst)->type == 1)
	{
		tools->g_error = 258;
		ft_err("Syntax error near unexpected token '|'", 127, tools);
		minishell_loop(tools);
	}
	while (*lst)
	{
		if (!check_redirects(lst, tools) || !check_broken_pipes(lst, tools))
			minishell_loop(tools);
		lst = &(*lst)->next;
	}
}
