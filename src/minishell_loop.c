/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fede <fede@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:35:25 by pcervill          #+#    #+#             */
/*   Updated: 2024/02/26 11:29:18 by fede             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
//#include "../include/lexer.h"

void	init_tools(t_tools *tools)
{
	tools->arg = NULL;
	tools->lexer = NULL;
	tools->pipes = 0;
	tools->parser = NULL;
	init_signals();
}

void	minishell_loop(t_tools *tools)
{
	init_tools(tools);
	tools->arg = readline(PROMPT_MSG);
	if (!tools->arg)
		exit(0);
	if (!tools->arg[0])
	{
		free(tools->arg);
		minishell_loop(tools);
	}
	tools->arg = check_add_spaces(tools->arg);
	add_history(tools->arg);
	check_quotes(tools);
	lexer(tools);
	check_tokens(tools, &tools->lexer);
	parser(tools);
	before_execution(tools);
	free_tools(tools);
	dup2(tools->input, STDIN_FILENO);
	dup2(tools->output, STDOUT_FILENO);
	minishell_loop(tools);
}
