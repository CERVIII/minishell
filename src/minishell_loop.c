/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:35:25 by pcervill          #+#    #+#             */
/*   Updated: 2024/04/23 15:12:29 by fdiaz-gu         ###   ########.fr       */
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
	tools->n_heredoc = 0;
	init_signals();
}

void	minishell_loop(t_tools *tools)
{
	char	*tmp;

	tmp = readline(PROMPT_MSG);
	if (!tmp)
		exit(0);
	tools->arg = ft_strtrim(tmp, " \t\n\r");
	if (!tools->arg || !tools->arg[0])
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
	dup2(tools->input, STDIN_FILENO);
	dup2(tools->output, STDOUT_FILENO);
	free_tools(tools);
}
