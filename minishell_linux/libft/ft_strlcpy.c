/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:29:06 by pcervill          #+#    #+#             */
/*   Updated: 2022/03/28 18:45:14 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	contstr;
	size_t	a;

	contstr = 0;
	while (src[contstr])
		contstr++;
	a = 0;
	if (dstsize < 1)
		return (contstr);
	while (a < dstsize - 1 && src[a])
	{
		dst[a] = src[a];
		a++;
	}
	dst[a] = '\0';
	return (contstr);
}
