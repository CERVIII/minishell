/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:35:25 by pcervill          #+#    #+#             */
/*   Updated: 2024/01/30 15:04:24 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
	tools->arg = check_add_spaces(readline(PROMPT_MSG));
	if (!tools->arg || !ft_strcmp(tools->arg, "exit"))
		exit(0);
	if (!tools->arg[0])
	{
		free(tools->arg);
		minishell_loop(tools);
	}
	add_history(tools->arg);
	check_quotes(tools);
	lexer(tools);
	printf("Input: %s\n\n", tools->arg);
	print_tokens(tools->lexer);
	check_tokens(tools, &tools->lexer);
	parser(tools);
	printf("\n%sTokens after parser:%s\n", RED_BOLD, NORMAL);
	print_tokens(tools->lexer);
	free_err(tools);
	minishell_loop(tools);
}
