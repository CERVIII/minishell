/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:19:21 by pcervill          #+#    #+#             */
/*   Updated: 2024/04/22 13:12:06 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	size_len;

	size_len = ft_strlen(s1);
	ptr = (char *)ft_calloc(sizeof(char), size_len + 1);
	if (ptr == NULL)
		return (NULL);
	memcpy(ptr, s1, size_len);
	return (ptr);
}

/* char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(s1);
	s2 = (char *)ft_calloc(size + 1, sizeof(char));
	if (!s2)
		return (0);
	while (i < size)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
} */

/* char	*ft_strdup(const char *s)
{
	char	*str;
	char	*cstr;
	size_t	count;

	if (!s)
		return (0);
	count = ft_strlen(s);
	str = (char *)ft_calloc(sizeof(char), count + 1);
	if (!str)
		return (0);
	cstr = str;
	while (*s)
	{
		*str = *s;
		s++;
		str++;
	}
	*str = '\0';
	return ((char *)cstr);
} */

/* char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(s1);
	s2 = (char *)malloc((size * sizeof(char)) + 1);
	if (!s2)
		return (0);
	while (i < size)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
} */
