/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:21:22 by pcervill          #+#    #+#             */
/*   Updated: 2024/04/24 11:21:25 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_strlenmod(char *str, int start)
{
	int	i;

	i = 0;
	while (str[start] && str[start] != '\'' && str[start] != '\"')
	{
		i++;
		start++;
	}
	return (i);
}

int	dollar_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (i + 1);
		i++;
	}
	return (0);
}

int	cmp_quotes(char str, int flag)
{
	if (str == '\"' && flag == 0)
		flag = 1;
	else if (str == '\"' && flag == 1)
		flag = 0;
	if (str == '\'' && flag == 0)
		flag = -1;
	else if (str == '\'' && flag == -1)
		flag = 0;
	return (flag);
}

char	*delete_quotes(char *str, int single_q, int double_q)
{
	int		i;
	char	*cpy;

	if (!str)
		return (NULL);
	cpy = ft_strdup(str);
	i = 0;
	while (cpy[i])
	{
		if (cpy[i] == '\"' && !single_q)
		{
			double_q = change_flag(double_q);
			ft_strlcpy(&cpy[i], &cpy[i + 1], ft_strlen(cpy) - i);
		}
		else if (cpy[i] == '\'' && !double_q)
		{
			single_q = change_flag(single_q);
			ft_strlcpy(&cpy[i], &cpy[i + 1], ft_strlen(cpy) - i);
		}
		else
			i++;
	}
	return (free(str), cpy);
}
