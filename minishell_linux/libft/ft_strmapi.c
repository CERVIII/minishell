/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:57:34 by pcervill          #+#    #+#             */
/*   Updated: 2022/04/06 19:42:17 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	str = ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (i < ft_strlen(s))
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	return (str);
}
