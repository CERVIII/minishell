/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:25:35 by pcervill          #+#    #+#             */
/*   Updated: 2024/02/07 13:33:29 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAN_H
# define CLEAN_H

# include "minishell.h"

		/* free_err.c */
int		ft_err(char *msg, int nb, t_tools *tools);
void	free_tools(t_tools *tools);
void	free_lexer(t_token *lexer);
void	free_parser(t_simple_cmds *parser);

#endif