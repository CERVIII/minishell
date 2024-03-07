/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:35:25 by pcervill          #+#    #+#             */
/*   Updated: 2024/03/07 12:37:10 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	init_tools(t_tools *tools)
{
	tools->arg = NULL;
	tools->lexer = NULL;
	tools->pipes = 0;
	tools->parser = NULL;
	tools->heredoc = false;
	tools->reset = false;
	init_signals();
}

void	minishell_loop(t_tools *tools)
{
	char	*tmp;

	tmp = readline(PROMPT_MSG);
	tools->arg = ft_strtrim(tmp, " \t\n\r");
	if (!tools->arg)
		exit(0);
	if (!tools->arg[0])
	{
		free(tmp);
		free(tools->arg);
		minishell_loop(tools);
	}
	add_history(tools->arg);
	check_quotes(tools);
	tools->arg = check_add_spaces(tools->arg);
	lexer(tools);
	check_tokens(tools, &tools->lexer);
	parser(tools);
	before_execution(tools);
	free_tools(tools);
	dup2(tools->input, STDIN_FILENO);
	dup2(tools->output, STDOUT_FILENO);
	minishell_loop(tools);
}
