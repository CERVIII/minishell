/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:25:55 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/12/18 11:52:51 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	check_redirects(t_token **lst)
{
	while (*lst)
	{

		if (((*lst)->type >= 2 && (*lst)->type <= 5) &&
			((!(*lst)->next) || (*lst)->next->type != 0
				|| (*lst)->next->type != 6 || (*lst)->next->type != 7))
		{
			ft_err("Error: Bad redirect", 127);
			break ;
		}
		lst = &(*lst)->next;
	}
}

void	check_broken_pipes(t_token **lst)
{
	while ((*lst))
	{
		if ((*lst)->type == 1 && (!(*lst)->next))
		{
			ft_err("Error: Syntax error '|' ", 127);
			break ;
		}
		lst = &(*lst)->next;
	}		
}