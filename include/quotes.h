/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:25:24 by pcervill          #+#    #+#             */
/*   Updated: 2024/02/08 15:10:57 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTES_H
# define QUOTES_H

# include "minishell.h"

typedef struct s_parser_tools	t_parser_tools;
typedef struct s_string_info	t_info;
typedef enum e_token_type		t_token_type;
typedef struct s_simple_cmds	t_simple_cmds;
typedef struct s_token			t_token;
typedef struct s_tools			t_tools;

		/* quotes.c */
int		change_flag(int flag);
int		quotes(char *input, int *i, int flag, char c);
void	check_quotes(t_tools *tools);

#endif