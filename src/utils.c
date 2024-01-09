/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:24:53 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/01/08 17:45:06 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


t_simple_cmds	*ft_mini_lstnew(char **content)
{
	t_simple_cmds	*new;

	new = (t_simple_cmds *)malloc(sizeof(t_simple_cmds));
	if (!new)
		return (NULL);
	new->str = content;
	new->next = NULL;
	return (new);
}

t_simple_cmds	*ft_mini_lstlast(t_simple_cmds *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

void	ft_mini_lstadd_back(t_simple_cmds **lst, t_simple_cmds *new)
{
	t_simple_cmds	*cpy;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		cpy = *lst;
		while (cpy->next)
			cpy = cpy->next;
		cpy -> next = new;
	}
	return ;
}