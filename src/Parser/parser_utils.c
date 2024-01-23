/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:07:10 by pcervill          #+#    #+#             */
/*   Updated: 2024/01/23 12:18:53 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	count_pipes(t_token *lexer, t_tools *tools)
{
	t_token	*tmp;

	tmp = lexer;
	tools->pipes = 0;
	while (lexer)
	{
		if (lexer->type == PIPE)
			tools->pipes++;
		lexer = lexer->next;
	}
}
