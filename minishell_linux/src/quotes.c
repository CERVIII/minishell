/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:05:56 by pcervill          #+#    #+#             */
/*   Updated: 2024/04/24 11:22:17 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	change_flag(int flag)
{
	if (flag == 0)
		return (1);
	else
		return (0);
}

/* int	quotes(char *input, int *i, int flag, char c)
{
	if (input[*i] == c)
	{
		flag = change_flag(flag);
		(*i)++;
		while (input[*i] && input[*i] != c)
			(*i)++;
		if (input[*i] == c)
			flag = change_flag(flag);
	}
	return (flag);
} */

int	quotes(char *input, int *i, int flag, char c)
{
	if (input[*i] == c)
	{
		flag = change_flag(flag);
		(*i)++;
		while (input[*i] && input[*i] != c)
			(*i)++;
		if (input[*i] == c)
		{
			flag = change_flag(flag);
			(*i)++;
		}
	}
	return (flag);
}

void	check_quotes(t_tools *tools)
{
	int	single_flag;
	int	double_flag;
	int	i;
	int	j;

	double_flag = 0;
	single_flag = 0;
	i = 0;
	while (tools->arg[i] && i < (int)ft_strlen(tools->arg))
	{
		j = i;
		double_flag = quotes(tools->arg, &i, double_flag, '\"');
		single_flag = quotes(tools->arg, &i, single_flag, '\'');
		if (i == j)
			i++;
	}
	if (double_flag || single_flag)
	{
		ft_err("ERROR: Unclosed quotes", 127, tools);
		minishell_loop(tools);
	}
}
