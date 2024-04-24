/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 22:58:49 by pcervill          #+#    #+#             */
/*   Updated: 2022/03/28 20:45:35 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			cont;
	unsigned char	*sc1;
	unsigned char	*sc2;

	sc1 = (unsigned char *)s1;
	sc2 = (unsigned char *)s2;
	cont = 0;
	while ((cont < n) && (sc1[cont] || sc2[cont]))
	{
		if (sc1[cont] == sc2[cont])
			cont++;
		else
			return (sc1[cont] - sc2[cont]);
	}
	return (0);
}
