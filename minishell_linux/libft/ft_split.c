/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:36:25 by pcervill          #+#    #+#             */
/*   Updated: 2023/01/25 11:06:16 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

static size_t	ft_cstring(char const *s, char c)
{
	size_t	cont;
	size_t	i;

	cont = 0;
	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			i = 0;
		else if (i == 0)
		{
			i = 1;
			cont++;
		}
		s++;
	}
	return (cont);
}

static size_t	ft_posc(char const *s, char c, size_t pos)
{
	while (s[pos] == c && s[pos])
		pos++;
	return (pos);
}

static void	ft_freestring(char **str, size_t cstr)
{
	while (cstr > 0)
	{
		free(str[cstr]);
		cstr--;
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	cont;
	size_t	start;
	size_t	pos;

	cont = 0;
	pos = 0;
	str = ft_calloc(sizeof (char *), (ft_cstring(s, c) + 1));
	if (!str)
		return (NULL);
	while (cont < ft_cstring(s, c))
	{
		pos = ft_posc(s, c, pos);
		start = pos;
		while (s[pos] != c && s[pos])
			pos++;
		str[cont] = ft_substr(s, start, pos - start);
		if (!str)
		{
			ft_freestring(str, ft_cstring(s, c));
			return (NULL);
		}
		cont++;
	}
	return (str);
}
