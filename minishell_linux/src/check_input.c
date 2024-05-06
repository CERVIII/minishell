/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:28:05 by pcervill          #+#    #+#             */
/*   Updated: 2024/04/24 11:20:59 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	add_space(char *arg, char *new, int i, int j)
{
	if ((i - 1) >= 0 && arg[i - 1] != ' '
		&& arg[i - 1] != '<' && arg[i - 1] != '>')
	{
		new[j] = ' ';
		new[j + 1] = arg[i];
		j++;
	}
	if (arg[i + 1] && arg[i + 1] != ' ' && arg[i + 1] != '<'
		&& arg[i + 1] != '>' && arg[i + 1] != '|')
	{
		new[j] = arg[i];
		new[j + 1] = ' ';
		j++;
	}
	else
		new[j] = arg[i];
	return (j);
}

void	status_quotes(int *single_q, int *double_q, char quote)
{
	if (quote == '\'' && !*double_q)
	{
		if (*single_q == 0)
			*single_q = 1;
		else
			*single_q = 0;
	}
	if (quote == '\"' && !*single_q)
	{
		if (*double_q == 0)
			*double_q = 1;
		else
			*double_q = 0;
	}
}

int	ft_strlen_spaces(char *arg, int i, int j)
{
	int	single_q;
	int	double_q;

	single_q = 0;
	double_q = 0;
	while (arg[i])
	{
		status_quotes(&single_q, &double_q, arg[i]);
		if ((!single_q && !double_q && (arg[i] == '|' || arg[i] == '<'
					|| arg[i] == '>')))
		{
			if (arg[i + 1] && arg[i + 1] != ' ' && arg[i + 1] != '<'
				&& arg[i + 1] != '>' && arg[i + 1] != '|')
				j++;
			if ((i - 1) >= 0 && arg[i - 1] && arg[i - 1] != ' '
				&& arg[i - 1] != '<' && arg[i - 1] != '>')
				j++;
		}
		j++;
		i++;
	}
	return (j);
}

void	pass_quotes(char *arg, char *new, int *i, int *j)
{
	int	flag;
	int	s;

	flag = 1;
	s = *i;
	new[*j] = arg[*i];
	(*j)++;
	(*i)++;
	while (arg[*i] && flag == 1)
	{
		if (arg[*i] == arg[s])
		{
			flag = 0;
			new[*j] = arg[*i];
			return ;
		}
		new[*j] = arg[*i];
		(*j)++;
		(*i)++;
	}
	return ;
}

char	*check_add_spaces(char *arg)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = malloc(sizeof(char) * ft_strlen_spaces(arg, i, j) + 1);
	if (!new)
		return (NULL);
	while (arg[i])
	{
		if (arg[i] == '\'' || arg[i] == '\"')
			pass_quotes(arg, new, &i, &j);
		else if ((arg[i] == '|' || arg[i] == '<' || arg[i] == '>'))
			j = add_space(arg, new, i, j);
		else
			new[j] = arg[i];
		i++;
		j++;
	}
	new[j] = '\0';
	free(arg);
	arg = NULL;
	return (new);
}
