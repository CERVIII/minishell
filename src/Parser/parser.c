/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:02:28 by pcervill          #+#    #+#             */
/*   Updated: 2024/01/17 13:21:14 by pcervill         ###   ########.fr       */
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

void	parser(t_tools *tools)
{
	count_pipes(tools->lexer, tools);
	printf("Number of pipes: %d\n", tools->pipes);
}
