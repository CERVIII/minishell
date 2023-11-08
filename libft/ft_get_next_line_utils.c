/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:25:22 by pcervill          #+#    #+#             */
/*   Updated: 2022/08/06 23:57:15 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen2(const char *str)
{
	size_t	cont;

	cont = 0;
	while (str[cont] != '\0')
		cont++;
	return (cont);
}

char	*ft_strchr2(const char *s, int c)
{
	int	cont;

	cont = 0;
	if (!s)
		return (NULL);
	while (s[cont])
	{
		if (s[cont] == (char)c)
			return ((char *)s + cont);
		cont++;
	}
	if (c == '\0')
		return ((char *)s + cont);
	return (NULL);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*str;
	int		cont;
	int		cont1;

	cont = -1;
	cont1 = -1;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen2(s1) + ft_strlen2(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[++cont])
		str[cont] = s1[cont];
	while (s2[++cont1])
		str[cont + cont1] = s2[cont1];
	str[cont + cont1] = '\0';
	free(s1);
	return (str);
}