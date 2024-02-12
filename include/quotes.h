/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:25:24 by pcervill          #+#    #+#             */
/*   Updated: 2024/02/12 09:26:31 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTES_H
# define QUOTES_H

# include "minishell.h"

typedef struct s_parser_tools	t_parser_tools;
typedef struct s_simple_cmds	t_simple_cmds;

		/* quotes.c */
int		change_flag(int flag);
int		quotes(char *input, int *i, int flag, char c);
void	check_quotes(t_tools *tools);

#endif