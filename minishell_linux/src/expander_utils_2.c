/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:10:24 by pcervill          #+#    #+#             */
/*   Updated: 2024/04/24 11:21:23 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**empty_str(char **str)
{
	int	i;

	i = 0;
	if (str[0] && ft_strlen(str[0]) < 1)
	{
		while (str[i])
			i++;
		i = 0;
		while (str[i])
		{
			str[i] = str[i + 1];
			i++;
		}
	}
	return (str);
}

char	*check_dolar(char *str, char **env, int *i, int g_error)
{
	char	*new_str;

	new_str = NULL;
	if (str[*i] == '$' && str[*i + 1] == '?')
	{
		new_str = ft_itoa(g_error);
		(*i) += 2;
	}
	else if (str[*i] == '$' && ((!str[*i + 1] || str[*i + 1] == ' ')
			|| (dollar_in_quotes(str, i, '\"') == 1 && str[*i + 1] == '\"')))
	{
		new_str = ft_strdup("$");
		(*i)++;
	}
	else if (str[*i] == '$' && str[*i + 1] != '\0'
		&& str[*i + 1] != ' ')
	{
		new_str = check_env(str, env, i);
		if (!new_str)
			new_str = ft_strdup("");
	}
	return (new_str);
}

int	dollar_in_quotes(char *str, int *i, char flag)
{
	int	j;
	int	quotes;

	j = 0;
	quotes = 0;
	while (str[j] && quotes != 2)
	{
		if (str[j] == '\"')
			quotes++;
		if (str[j] == '$' && *i == j && quotes == 1)
		{
			while (str[j + 1] != flag)
				j++;
			if (flag == '\'')
				return (-1);
			return (1);
		}
		else
			j++;
		if (quotes == 2)
			quotes = 0;
	}
	return (0);
}
