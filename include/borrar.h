/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borrar.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:25:39 by pcervill          #+#    #+#             */
/*   Updated: 2024/02/12 09:22:47 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BORRAR_H
# define BORRAR_H

# include "./minishell.h"

		/* print_tools.c */
void	print_tokens(t_token *temp);
void	print_simple_cmd(t_simple_cmds *cmd);
void	print_parser_tools(t_parser_tools *tools);

#endif