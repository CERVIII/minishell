/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmd_aux_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:51:03 by pcervill          #+#    #+#             */
/*   Updated: 2024/02/26 11:32:49 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	process_char(t_info *info, size_t *word_count, char c, int *in_quotes)
{
	if (info->s[*(info->i)] == '\'' || info->s[*(info->i)] == '\"')
		p_quotes_cmd(info->s, info->i, in_quotes, &(info->current_quote));
	else
		process_delimiter(info, word_count, c, *in_quotes);
}

size_t	ft_count_words_cmd(char *s, char c)
{
	size_t	word_count;
	size_t	i;
	int		in_quotes;
	t_info	s_string_info;

	word_count = 0;
	i = 0;
	in_quotes = 0;
	s_string_info.s = s;
	s_string_info.i = &i;
	s_string_info.current_quote = '\0';
	i += ft_skip_spaces(s);
	while (s[i])
		process_char(&s_string_info, &word_count, c, &in_quotes);
	if (s[i - 1] != c && !in_quotes)
		word_count++;
	return (word_count);
}

void	process_delimiter_split(char *s, size_t *i, char c, int in_quotes)
{
	if (!in_quotes && s[*i] == c)
	{
		while (s[*i] && s[*i] == c)
			(*i)++;
	}
	else
		(*i)++;
}

void	process_word(char *s, size_t *i, int *in_quotes, char *current_quote)
{
	if (s[*i] == '\'' || s[*i] == '\"')
		p_quotes_cmd(s, i, in_quotes, current_quote);
	else
		(*i)++;
}

void	skip_delimiters(char *s, size_t *start, char c, int in_quotes)
{
	if (s[*start] != '\0')
	{
		while (s[*start] == c && !in_quotes)
			(*start)++;
	}
}
