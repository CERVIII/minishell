/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:23:27 by pcervill          #+#    #+#             */
/*   Updated: 2022/04/01 20:09:59 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	contdst;
	size_t	contsrc;
	size_t	i;

	contdst = ft_strlen(dst);
	contsrc = ft_strlen(src);
	if (dstsize == 0)
		return (contsrc);
	else if (contdst > dstsize)
		return (contsrc + dstsize);
	else
	{
		i = 0;
		while (i < (dstsize - contdst) && src[i])
		{
			dst[contdst + i] = src[i];
			i++;
		}
		if ((contdst + i) == dstsize && contdst < dstsize)
			dst[(contdst + i) - 1] = '\0';
		else
			dst[i + contdst] = '\0';
		return (contsrc + contdst);
	}
}
