/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:50:22 by pcervill          #+#    #+#             */
/*   Updated: 2024/01/17 13:19:38 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	check_tokens(t_token **lst)
{
	if (!(*lst))
		return ;
	if ((*lst)->type == 1)
	{
		ft_err("Error: Syntax error '|' ", 127);
		return ;
	}
	while (*lst)
	{
		if (!check_redirects(lst) || !check_broken_pipes(lst))
			break ;
		lst = &(*lst)->next;
	}
}

int	check_redirects(t_token **lst)
{
	if (((*lst)->type >= 2 && (*lst)->type <= 5)
		&& (!(*lst)->next || (*lst)->next->type != 0))
	{
		ft_err("Error: Bad redirect", 127);
		return (0);
	}
	return (1);
}

int	check_broken_pipes(t_token **lst)
{
	if ((*lst)->type == 1 && ((!(*lst)->next)
			|| ((*lst)->next->type != 0
				&& !((*lst)->next->type >= 2 && (*lst)->next->type <= 5))))
	{
		ft_err("Error: Syntax error '|' ", 127);
		return (0);
	}
	return (1);
}
