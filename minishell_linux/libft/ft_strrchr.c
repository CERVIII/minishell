/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 22:29:57 by pcervill          #+#    #+#             */
/*   Updated: 2022/04/06 11:54:09 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int	cont;

	cont = 0;
	while (s[cont])
		cont++;
	if (c == '\0')
		return ((char *)s + cont);
	while (cont >= 0)
	{
		if (s[cont] == (char)c)
			return ((char *)s + cont);
		cont--;
	}
	return (NULL);
}
