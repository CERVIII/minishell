/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:25:35 by pcervill          #+#    #+#             */
/*   Updated: 2024/02/08 15:10:46 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAN_H
# define CLEAN_H

# include "minishell.h"

typedef struct s_parser_tools	t_parser_tools;
typedef struct s_string_info	t_info;
typedef enum e_token_type		t_token_type;
typedef struct s_simple_cmds	t_simple_cmds;
typedef struct s_token			t_token;
typedef struct s_tools			t_tools;

		/* free_err.c */
int		ft_err(char *msg, int nb, t_tools *tools);
void	free_tools(t_tools *tools);
void	free_lexer(t_token *lexer);
void	free_parser(t_simple_cmds *parser);

#endif