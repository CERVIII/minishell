/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:37:35 by pcervill          #+#    #+#             */
/*   Updated: 2023/01/09 15:22:37 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int *(*f)(int *), void (*del)(int *))
{
	t_list	*new;
	t_list	*lstcp;

	if (!lst)
		return (lst);
	lstcp = NULL;
	while (lst)
	{
		new = ft_lstnew(*f(&lst->content));
		if (!(new))
		{
			ft_lstclear(&lstcp, (*del));
			return (NULL);
		}
		ft_lstadd_back(&lstcp, new);
		lst = lst -> next;
	}
	return (lstcp);
}
