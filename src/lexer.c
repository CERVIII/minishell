/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:26:45 by pcervill          #+#    #+#             */
/*   Updated: 2023/11/08 14:46:20 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	lexer(char *input)
{
	int	i;
	int	token_pipe;
	int	token_output;
	int	token_input;

	token_input = 0;
	token_output = 0;
	token_pipe = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == '|')
			token_pipe++;
		else if (input[i] == '<')
			token_output++;
		else if (input[i] == '>')
			token_input++;
		i++;
	}
	i = 0;
	while (input[i])
	{
		if (token_pipe != 0 && input[i] != '|')
			printf("%c", input[i]);
		else if (input[i] == '|')
			printf("\n");
		i++;
	}
	printf("\n");
	return (0);
}
