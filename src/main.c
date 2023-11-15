/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:06:29 by pcervill          #+#    #+#             */
/*   Updated: 2023/11/15 12:01:27 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	leaks(void)
{
	system("leaks -q minishell");
}

char	*prompt(void)
{
	char	*end;

	end = ft_strjoin(BLUE, "minishell/\n");
	end = ft_strjoin(end, GREEN);
	end = ft_strjoin(end, "> ");
	end = ft_strjoin(end, NORMAL);
	return (end);
}

void	ft_freetoken(t_token *token)
{
	int	i;

	i = 0;
	while (token->content[i])
		free(token->content[i++]);
	free(token->content);
	i = 0;
	while (token->tokens[i])
		free(token->tokens[i++]);
	free(token->tokens);
	free(token->cpinp);
	free(token->len);
}

int	main(void)
{
	char	*input;
	int		i;
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	while (1)
	{
	//	input = readline("\x1B[34mminishell\n> \x1B[0m");
		input = readline(prompt());
		if (!input)
		{
			printf("%sSaliendo de minishell...\n%s", RED, NORMAL);
			break ;
		}
		lexer(input, token);
		i = 0;
		printf("Tokens: %d\n", token->count);
		while (i <= token->count)
		{
			if (token->content[i])
				printf("Arg: %s\n", token->content[i]);
			if (token->tokens[i])
				printf("Token: %s\n", token->tokens[i]);
			i++;
		}
		ft_freetoken(token);
		free(input);
		atexit(leaks);
	}
	return (0);
}
