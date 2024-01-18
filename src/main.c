/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:46:02 by pcervill          #+#    #+#             */
/*   Updated: 2024/01/18 14:41:08 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	leaks(void)
{
	system("leaks -q minishell");
}

int	ft_err(char *msg, int nb, t_tools *tools)
{
	printf("%s%s%s\n", RED, msg, RESET_COLOR);
	free_err(tools);
	return (nb);
}

void	print_tokens(t_token *temp)
{
	while (temp)
	{
		printf("Token: %s	Type: %d	Indice: %d\n", temp->token, temp->type, temp->i);
		temp = temp->next;
	}
}

void	free_err(t_tools *tools)
{
	if (tools->arg)
		free(tools->arg);
	if (tools->lexer)
	{
		while (tools->lexer)
		{
			free(tools->lexer->token);
			tools->lexer = tools->lexer->next;
		}
		free(tools->lexer);
	}
}

int	main(void)
{
	t_tools	tools;

	atexit(leaks);
	minishell_loop(&tools);
}

/*  char	*prompt(void)
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
}  */

/* char	*prompt(void)
{
	char	*end;
	char	*cwd;
	char	*temp;

	end = NULL;
	cwd = NULL;
	cwd = getcwd(cwd, sizeof(cwd));
	if (!cwd)
		return (NULL);
	// end = ft_strjoin(BLUE, cwd);
	// free(cwd);
	temp = cwd;
	end = ft_strjoin(temp, "\n");
	free(temp);
	temp = ft_strjoin(end, "> ");
	free(end);
	// end = ft_strjoin(temp, "> ");
	// free(temp);
	// temp = ft_strjoin(end, NORMAL);
	// free(end);
	return (temp);
} */

/* int	main(void)
{
	char	*input;
	char	*str;
	t_tools	tools;

	atexit(leaks);
	while (1)
	{
		str = prompt();
		input = readline(PROMPT_MSG);
		if (!input || !ft_strcmp(input, "exit"))
			break ;
		tools.arg = ft_strdup(input);
		check_quotes(&tools);
		lexer(input, &tools);
		print_tokens(tools.lexer);
		check_tokens(&tools.lexer);
		add_history(input);
		parser(&tools);
		ft_free_token(&tools.lexer);
		free_exit(str, input);
		free(tools.arg);
	}
	free_exit(str, input);
	return (0);
} */
