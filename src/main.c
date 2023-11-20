/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:06:29 by pcervill          #+#    #+#             */
/*   Updated: 2023/11/20 17:55:05 by pcervill         ###   ########.fr       */
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
	char	*cwd;

	cwd = NULL;
	end = ft_strjoin(BLUE, getcwd(cwd, sizeof(cwd)));
	free(end);
	end = ft_strjoin(end, "\n");
	free(end);
	end = ft_strjoin(end, GREEN);
	free(end);
	end = ft_strjoin(end, "> ");
	free(end);
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
}

int	main(void)
{
	char	*input;
	char	*str;
	int		i;
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	while (1)
	{
		atexit(leaks);
//		input = readline("\x1B[34mminishell\n> \x1B[0m");
		str = prompt();
		input = readline(str);
		if (!input || !ft_strcmp(input, "exit"))
		{
			printf("%sSaliendo de minishell...%s\n", RED, NORMAL);
			free(str);
			free(input);
			break ;
		}
		lexer(input, token);
		i = 0;
		printf("Tokens: %d\n", token->count);
		while (token->tokens[i])
			printf("Token: %s\n", token->tokens[i++]);
//		ft_freetoken(token);
		free(str);
		free(input);
	}
	return (0);
}
