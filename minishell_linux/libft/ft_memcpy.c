/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:04:52 by pcervill          #+#    #+#             */
/*   Updated: 2022/04/07 12:47:36 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	a;

	if (!src && !dst)
		return (NULL);
	a = 0;
	while (a < n)
	{
		((unsigned char *)dst)[a] = ((unsigned char *)src)[a];
		a++;
	}
	return (dst);
}
