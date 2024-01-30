/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:46:02 by pcervill          #+#    #+#             */
/*   Updated: 2024/01/30 14:56:22 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	leaks(void)
{
	system("leaks -q minishell");
}

void	print_tokens(t_token *tmp)
{
	while (tmp)
	{
		printf("%sToken: %s%s	%sType: %s%d	%sIndex: %s%d%s\n", YELLOW_BOLD, YELLOW, tmp->token, BLUE_BOLD, BLUE, tmp->type, MAGENTA_BOLD, MAGENTA, tmp->i, NORMAL);
		tmp = tmp->next;
	}
}

int	ft_err(char *msg, int nb, t_tools *tools)
{
	printf("%s%s%s\n", RED, msg, NORMAL);
	free_err(tools);
	return (nb);
}

void	free_err(t_tools *tools)
{
	t_token	*tmp;
	t_token	*tmp2;

	tmp = tools->lexer;
	if (tools->arg)
	{
		free(tools->arg);
		tools->arg = NULL;
	}
	if (tools->lexer)
	{
		while (tmp)
		{
			tmp2 = tmp->next;
			free(tmp->token);
			free(tmp);
			tmp = tmp2;
		}
		tools->lexer = NULL;
	}
}

int	main(void)
{
	t_tools	tools;

	atexit(leaks);
	minishell_loop(&tools);
	return (0);
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
//	char	*str;
	t_tools	tools;

//	atexit(leaks);
	while (1)
	{
		//str = prompt();
		input = readline(PROMPT_MSG);
		if (!input || !ft_strcmp(input, "exit"))
			break ;
		tools.arg = ft_strdup(input);
		check_quotes(&tools);
		lexer(&tools);
		print_tokens(tools.lexer);
		check_tokens(&tools, &tools.lexer);
		add_history(tools.arg);
		parser(&tools);
		ft_free_token(&tools.lexer);
//		free(str);
		free(input);
		free(tools.arg);
	}
//	free(str);
	free(input);
	return (0);
} */

//hola | esto"es>>una!" >> prueba|por>si
