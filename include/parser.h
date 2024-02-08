/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:25:27 by pcervill          #+#    #+#             */
/*   Updated: 2024/02/08 15:10:53 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

typedef struct s_parser_tools	t_parser_tools;
typedef struct s_string_info	t_info;
typedef enum e_token_type		t_token_type;
typedef struct s_simple_cmds	t_simple_cmds;
typedef struct s_token			t_token;
typedef struct s_tools			t_tools;

		/* check_token.c */
int				check_redirects(t_token **lst, t_tools *tools);
int				check_broken_pipes(t_token **lst, t_tools *tools);
void			check_tokens(t_tools *tools, t_token **lst);

		/* clean_lexer.c */
t_token			*ft_lexerclear_one(t_token **tmp);
void			ft_lexerdel_first(t_token **lexer);
void			ft_lexerdelone(t_token **lexer, int key);

		/* cmd_utils.c */
t_simple_cmds	*create_node_cmd(t_parser_tools *parser_tools);
t_simple_cmds	*new_node_cmd(char **str, t_parser_tools *parser_tools);
void			add_back_cmd(t_simple_cmds **cmd, t_simple_cmds *node);

		/* parser_utils.c */
void			count_pipes(t_token *lexer, t_tools *tools);
int				count_arg(t_token *lexer);
t_parser_tools	init_parser_tools(t_token *lexer, t_tools *tools);

		/* parser.c */
void			parser(t_tools *tools);

		/* redirections.c */
t_token			*token_new_cmd(char *str, int token, int i);
void			new_redirection(t_token *tmp, t_parser_tools *parser_tools);
void			redirection_add(t_parser_tools *parser_tools);

#endif