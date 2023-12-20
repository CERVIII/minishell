/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:25:55 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/12/20 12:45:59 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void check_redirects(t_token **lst)
{
	int double_flag;
	int single_flag;

	double_flag = 0;
	single_flag = 0;
	while (*lst)
	{
		if ((*lst)->type == 6)
			double_flag = !double_flag;
		else if ((*lst)->type == 7)
			single_flag = !single_flag;
		if (double_flag == 0 && single_flag == 0)
		{			
			if (((*lst)->type >= 2 && (*lst)->type <= 5) &&
				((!(*lst)->next) || (*lst)->next->type != 0))
			{
				ft_err("Error: Bad redirect", 127);
				break ;
			}
		}
		lst = &(*lst)->next;
	}
}

void check_broken_pipes(t_token **lst)
{
	int double_flag;
	int single_flag;

	double_flag = 0;
	single_flag = 0;
	while ((*lst))
	{
		if ((*lst)->type == 6)
			double_flag = !double_flag;
		else if ((*lst)->type == 7)
			single_flag = !single_flag;
		if (double_flag == 0 && single_flag == 0)
		{
			if ((*lst)->type == 1 && ((!(*lst)->next) || ((*lst)->next->type != 0 && !((*lst)->next->type >= 2 && (*lst)->next->type <= 5))))
			{
				ft_err("Error: Syntax error '|' ", 127);
				break;
			}
		}
		lst = &(*lst)->next;
	}
}
