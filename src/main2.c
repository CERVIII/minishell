/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:46:02 by pcervill          #+#    #+#             */
/*   Updated: 2023/11/21 14:37:31 by pcervill         ###   ########.fr       */
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
	free(cwd);
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

int	main(void)
{
	char	*input;
	char	*str;
	t_token	*token;

	while (1)
	{
		atexit(leaks);
		str = prompt();
		input = readline(str);
		if (!input || !ft_strcmp(input, "exit"))
		{
			printf("%sSaliendo de minishell...%s\n", RED, NORMAL);
			free(str);
			free(input);
			break ;
		}
		token = NULL;
		lexer(input, token);
		/* while (token->next)
		{
			token = token->next;
		} */
		printf("Token:%s\nType: %d\n", token->token, token->type);
		ft_free_token(token);
		free(str);
		free(input);
	}
	return (0);
}
