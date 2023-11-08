/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:55:11 by pcervill          #+#    #+#             */
/*   Updated: 2022/04/07 12:47:24 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	a;
	char	*dstc;
	char	*srcc;

	dstc = (char *)dst;
	srcc = (char *)src;
	if (!src && !dst)
		return (NULL);
	a = 0;
	if (dst > src)
	{
		while (a < len)
		{
			a++;
			dstc[len - a] = srcc[len - a];
		}
	}
	else
	{
		while (len-- > 0)
			*(dstc++) = *(srcc++);
	}
	return (dst);
}
