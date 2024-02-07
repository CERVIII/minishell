/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:25:32 by pcervill          #+#    #+#             */
/*   Updated: 2024/02/07 13:31:47 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

		/* check_input.c */
int		add_space(char *arg, char *new, int i, int j);
void	status_quotes(int *single_q, int *double_q, char quote);
int		ft_strlen_spaces(char *arg, int i, int j);
void	pass_quotes(char *arg, char *new, int *i, int *j);
char	*check_add_spaces(char *arg);

		/* split */
char	**ft_split_cmd(char *s, char c);
size_t	ft_count_words_cmd(char *s, char c);
char	*get_next_word(char *s, size_t *start, char c);
void	skip_delimiters(char *s, size_t *start, char c, int in_quotes);
void	process_word(char *s, size_t *i, int *in_quotes, char *current_quote);
void	process_delimiter_split(char *s, size_t *i, char c, int in_quotes);
void	process_char(t_info *info, size_t *word_count, char c, int *in_quotes);
t_info	initialize_string_info(char *s, size_t *i);
void	process_delimiter(t_info *info, size_t *w_c, char c, int in_quotes);
void	p_quotes_cmd(char *s, size_t *i, int *in_quotes, char *current_quote);
int		ft_is_whitespace(char c);
int		ft_skip_spaces(char *str);

		/* lexer_utils.c */
t_token	*ft_token_new(char *token, int i);
void	ft_add_token_last(t_token **list, t_token *new);
void	ft_free_token(t_token **token);

		/* lexer.c */
void	create_token(t_tools *tools, t_token **token);
void	ft_strlen_token(char *str);
int		lexer(t_tools *tools);

#endif