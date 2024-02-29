/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:21:22 by pcervill          #+#    #+#             */
/*   Updated: 2024/02/29 14:13:25 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

/* Comprueba la primera comilla que se mande y si hay dentro de ellas $ 
	Valores de retorno:
		0 : Hay dolar entre comillas pero es simple y no tiene que expandir
		1 : Hay dolar entre comillas dobles o sin comillas
		-1: Hay dolar entre comillas pero es siple y no tiene que expandir
*/

int	cmp_dollar(char *str, int *i, char flag)
{
	*i += 1;
	while (str[*i] && str[*i] != flag)
	{
		if (str[*i] == '$')
		{
			while (str[*i + 1] != flag)
				(*i)++;
			if (flag == '\'')
				return (-1);
			return (1);
		}
		else
			(*i)++;
	}
	return (0);
}

int	quotes_dollar(char *str)
{
	int	i;
	int	double_q;
	int	single_q;

	i = 0;
	double_q = 0;
	single_q = 0;
	while (str[i])
	{
		if (str[i] == '\"' && single_q == 0 && double_q == 0)
			double_q = cmp_dollar(str, &i, '\"');
		if (str[i] == '\'' && double_q == 0)
			single_q = cmp_dollar(str, &i, '\'');
		if (single_q == -1)
			return (0);
		i++;
	}
	return (1);
}

char	*delete_quotes(char *str)
{
	int	i;
	int	single_q;
	int	double_q;

	i = 0;
	single_q = 0;
	double_q = 0;
	while (str[i])
	{
		if (str[i] == '\"' && !single_q)
		{
			double_q = change_flag(double_q);
			ft_strlcpy(&str[i], &str[i + 1], ft_strlen(str) - i);
		}
		else if (str[i] == '\'' && !double_q)
		{
			single_q = change_flag(single_q);
			ft_strlcpy(&str[i], &str[i + 1], ft_strlen(str) - i);
		}
		else
			i++;
	}
	return (str);
}
