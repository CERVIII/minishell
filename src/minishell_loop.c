/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:35:25 by pcervill          #+#    #+#             */
/*   Updated: 2024/01/18 15:02:01 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	minishell_loop(t_tools *tools)
{
	tools->arg = readline(PROMPT_MSG);
	if (!tools->arg || !ft_strcmp(tools->arg, "exit"))
	{
		exit(0);
	}
	check_quotes(tools);
	lexer(tools);
//	print_tokens(tools->lexer);
	check_tokens(tools, &tools->lexer);
	add_history(tools->arg);
	parser(tools);
	ft_free_token(&tools->lexer);
	free(tools->arg);
	minishell_loop(tools);
}

