/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:35:25 by pcervill          #+#    #+#             */
/*   Updated: 2024/01/22 12:46:19 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	minishell_loop(t_tools *tools)
{
		tools->arg = readline(PROMPT_MSG);
	if (!tools->arg || !ft_strcmp(tools->arg, "exit"))
		exit(0);
	add_history(tools->arg);
	check_quotes(tools);
	lexer(tools);
	print_tokens(tools->lexer);
	check_tokens(tools, &tools->lexer);
	parser(tools);
	free_err(tools);
	minishell_loop(tools);
}

/* void	minishell_loop(t_tools *tools)
{
	char *input;
	(void) tools;

	//input = NULL;
	
	printf("%p\n", &input);
	input = readline(PROMPT_MSG);
	printf("%p\n", &input);
	printf("%s\n", input);
	free(input);
	printf("%s\n%p\n", input, &input);
	return ;
} */
