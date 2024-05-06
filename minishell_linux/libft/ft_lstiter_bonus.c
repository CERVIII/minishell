/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:19:05 by pcervill          #+#    #+#             */
/*   Updated: 2023/01/09 15:16:46 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int *))
{
	t_list	*cp;

	if (!lst)
		return ;
	while (lst)
	{
		cp = lst -> next;
		f(&lst->content);
		lst = cp;
	}
}
