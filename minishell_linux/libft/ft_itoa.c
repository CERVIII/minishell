/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:58:22 by pcervill          #+#    #+#             */
/*   Updated: 2022/04/07 12:46:17 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_contm(int n)
{
	int	contm;

	contm = 0;
	if (n == -2147483647 -1)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		contm++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		contm++;
	}
	return (contm);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		contm;
	long	num;

	contm = ft_contm(n);
	num = n;
	str = ft_calloc(sizeof(char), contm + 1);
	if (!str)
		return (0);
	if (n < 0)
		num *= -1;
	while (contm-- > 0)
	{
		str[contm] = num % 10 + 48;
		num /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
