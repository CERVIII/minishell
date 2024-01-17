/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmd_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:43:07 by drubio-m          #+#    #+#             */
/*   Updated: 2024/01/17 13:19:04 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_is_whitespace(char c)
{
	return (c == ' ' || (c > 8 && c < 14));
}

int	ft_skip_spaces(char *str)
{
	int	j;

	j = 0;
	while (ft_is_whitespace(str[j]))
		j++;
	return (j);
}

void	p_quotes_cmd(char *s, size_t *i, int *in_quotes, char *current_quote)
{
	if (*in_quotes && *current_quote == s[*i])
		*in_quotes = 0;
	else if (!*in_quotes)
	{
		*in_quotes = 1;
		*current_quote = s[*i];
	}
	(*i)++;
}

void	process_delimiter(t_info *info, size_t *w_c, char c, int in_quotes)
{
	if (!in_quotes && info->s[*(info->i)] == c)
	{
		(*w_c)++;
		while (info->s[*(info->i)] && info->s[*(info->i)] == c)
			(*(info->i))++;
	}
	else
		(*(info->i))++;
}

t_info	initialize_string_info(char *s, size_t *i)
{
	t_info	string_info;

	string_info.s = s;
	string_info.i = i;
	return (string_info);
}
