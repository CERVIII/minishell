/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:38:41 by pcervill          #+#    #+#             */
/*   Updated: 2022/05/30 12:26:50 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	cont;
	char	*str;
	char	*cstr;

	if (!s1 || !s2)
		return (NULL);
	cont = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * cont + 1);
	if (!str)
		return (NULL);
	cstr = str;
	while (*s1)
	{
		*str = *s1;
		str++;
		s1++;
	}
	while (*s2)
	{
		*str = *s2;
		str++;
		s2++;
	}
	*str = '\0';
	return ((char *)cstr);
}
