/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borrar.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:25:39 by pcervill          #+#    #+#             */
/*   Updated: 2024/02/08 15:10:43 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BORRAR_H
# define BORRAR_H

# include "./minishell.h"

typedef struct s_parser_tools	t_parser_tools;
typedef struct s_string_info	t_info;
typedef enum e_token_type		t_token_type;
typedef struct s_simple_cmds	t_simple_cmds;
typedef struct s_token			t_token;
typedef struct s_tools			t_tools;

		/* print_tools.c */
void	print_tokens(t_token *temp);
void	print_simple_cmd(t_simple_cmds *cmd);
void	print_parser_tools(t_parser_tools *tools);

#endif