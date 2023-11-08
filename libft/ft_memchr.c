/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:48:34 by pcervill          #+#    #+#             */
/*   Updated: 2022/04/07 12:48:31 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*scpy;

	scpy = (const char *)s;
	i = 0;
	while (i < n)
	{
		if (*(scpy + i) == (char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
