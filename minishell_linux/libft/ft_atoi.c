/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:59:20 by pcervill          #+#    #+#             */
/*   Updated: 2023/01/25 10:58:30 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	snumber(unsigned long int number, int sign)
{
	if (number > 2147483648 && sign == 1)
	{
		number = 0;
		ft_error();
	}
	else if (number > 2147483647 && sign != 1)
	{
		number = 0;
		ft_error();
	}
	return (number);
}

int	ft_atoi(const char *str)
{
	unsigned long int	number;
	int					sign;

	while ((*str == ' ') || (*str >= 7 && *str <= 13))
		str++;
	sign = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign++;
		str++;
	}
	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		number = 10 * number + (*str - 48);
		str++;
	}
	number = snumber(number, sign);
	if (sign == 1)
		return (number * -1);
	return (number);
}
