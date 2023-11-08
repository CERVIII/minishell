/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:19:22 by pcervill          #+#    #+#             */
/*   Updated: 2022/04/07 12:51:14 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_exit(char s1, char const *set)
{
	size_t	num;

	num = 0;
	while (set[num])
	{
		if (s1 == set[num])
			return (1);
		num++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*cstr;
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	j = ft_strlen(s1);
	i = 0;
	while (ft_exit(s1[i], set) && s1[i])
		i++;
	while (ft_exit(s1[j - 1], set) && j > i)
		j--;
	str = ft_calloc(sizeof (char), ((j - i) + 1));
	if (!str)
		return (NULL);
	cstr = str;
	while (i < j)
	{
		*str = s1[i];
		str++;
		i++;
	}
	return (cstr);
}
