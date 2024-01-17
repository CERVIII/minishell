/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:25:55 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/01/16 11:17:38 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void check_tokens(t_token **lst)
{
	int double_flag;
	int single_flag;

	double_flag = 0;
	single_flag = 0;
	if (!(*lst))
		return ;
	if ((*lst)->type == 1)
	{
		ft_err("Error: Syntax error '|' ", 127);
		return ;
	}
	while (*lst)
	{
		if ((*lst)->type == DOUBLE_QUOTE)
			double_flag = !double_flag;
		else if ((*lst)->type == SINGLE_QUOTE)
			single_flag = !single_flag;
		if (double_flag == 0 && single_flag == 0)
		{			
			if (!check_redirects(lst) || !check_broken_pipes(lst))
				break ;
		}
		lst = &(*lst)->next;
	}
}

int check_redirects(t_token **lst)
{	
	if (((*lst)->type >= 2 && (*lst)->type <= 5) &&
		(!(*lst)->next || ((*lst)->next->type != 0 &&
		((*lst)->next->type != 6) && (*lst)->next->type != 7)))
	{
		ft_err("Error: Bad redirect", 127);
		return (0);
	}
	return (1);
}

int check_broken_pipes(t_token **lst)
{
	if ((*lst)->type == 1 && ((!(*lst)->next) ||
		((*lst)->next->type != 0 &&
		!((*lst)->next->type >= 2 && (*lst)->next->type <= 5))))
	{
		ft_err("Error: Syntax error '|' ", 127);
		return (0);
	}
	return (1);
}
