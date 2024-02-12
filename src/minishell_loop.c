/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:35:25 by pcervill          #+#    #+#             */
/*   Updated: 2024/02/08 13:00:12 by pcervill         ###   ########.fr       */
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
}

void	minishell_loop(t_tools *tools)
{
	init_tools(tools);
	tools->arg = readline(PROMPT_MSG);
	if (!tools->arg || !ft_strcmp(tools->arg, "exit"))
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
	free_tools(tools);
	minishell_loop(tools);
}