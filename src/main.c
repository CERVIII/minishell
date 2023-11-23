/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:46:02 by pcervill          #+#    #+#             */
/*   Updated: 2023/11/23 12:53:52 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	leaks(void)
{
	system("leaks -q minishell");
}

/* char	*prompt(void)
{
	char	*end;
	char	*cwd;

	cwd = NULL;
	end = ft_strjoin(BLUE, getcwd(NULL, 0));
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
} */

void	free_exit(char *str, char *input)
{
	free(str);
	free(input);
	return ;
}

char	*prompt(void)
{
	char	*end;
	char	*cwd;
	char	*temp;

	end = NULL;
	cwd = NULL;
	cwd = getcwd(cwd, sizeof(cwd));
	if (!cwd)
		return (NULL);
	end = ft_strjoin(BLUE, cwd);
	free(cwd);
	temp = end;
	end = ft_strjoin(temp, "\n");
	free(temp);
	temp = ft_strjoin(end, GREEN);
	free(end);
	end = ft_strjoin(temp, "> ");
	free(temp);
	temp = ft_strjoin(end, NORMAL);
	free(end);
	return (temp);
}


int	main(void)
{
	char	*input;
	char	*str;
	t_token	*token;

	atexit(leaks);
	while (1)
	{
		token = NULL;
		str = prompt();
		input = readline(str);
		if (!input || !ft_strcmp(input, "exit"))
			break ;
		lexer(input, &token);
		// Borrar printf de token ↓
		t_token	*temp = token;
		while (temp)
		{
			printf("Token: %s	Type: %d\n", temp->token, temp->type);
			temp = temp->next;
		}
		ft_free_token(&token);
		free_exit(str, input);
	}
	printf("%sSaliendo de minishell...%s\n", RED, NORMAL);
	free_exit(str, input);
	return (0);
}
