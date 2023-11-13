/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:06:29 by pcervill          #+#    #+#             */
/*   Updated: 2023/11/13 14:19:52 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*prompt(void)
{
	char	*end;

	end = ft_strjoin(BLUE, "minishell/\n");
	end = ft_strjoin(end, GREEN);
	end = ft_strjoin(end, "> ");
	end = ft_strjoin(end, NORMAL);
	return (end);
}

int	main(void)
{
	char	*input;
	int		i;
	// t_token	*token;
	t_tokenList	*tokenList;

	tokenList = (t_tokenList *)malloc(sizeof(t_tokenList));
	while (1)
	{
	//	input = readline("\x1B[34mminishell\n> \x1B[0m");
		input = readline(prompt());
		if (!input)
		{
			printf("%sSaliendo de minishell...\n%s", RED, NORMAL);
			break ;
		}
	//	lexer(input, token);
		lexer(input, tokenList);
		i = 0;
		printf("Tokens: %d\n", tokenList->count);
		while (i < tokenList->count)
			printf("%s\n", tokenList->tokens[i++]);
		free(input);
	}
	return (0);
}
