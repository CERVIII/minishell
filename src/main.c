/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:46:02 by pcervill          #+#    #+#             */
/*   Updated: 2024/01/19 14:21:04 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	leaks(void)
{
	system("leaks -q minishell");
}

int	ft_err(char *msg, int nb)
{
	printf("%s%s%s\n", RED, msg, NORMAL);
	return (nb);
}

void print_tokens(t_token **temp)
{
	while (*temp)
	{
		printf("Token: %s	Type: %d\n", (*temp)->token, (*temp)->type);
		temp = &(*temp)->next;
	}
}

void print_cmds(t_simple_cmds *temp)
{
	t_simple_cmds	*aux;
	
	aux = temp;
	while (aux)
	{		
		int i = 0;
		while ((aux)->str[i])
		{
			printf("Token: %s	\n", (aux)->str[i]);
			i++;
		}
		printf("---------------------------\n");
		aux = (aux)->next;
	}
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
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	char	*str;
	t_token	*token;
	t_token	*temp;
	t_simple_cmds *simple_cmds;
	t_tools	tools;
	simple_cmds = NULL;

	atexit(leaks);
	if (argc != 1 || argv[1])
	{
		printf("This program does not accept arguments\n");
		exit(0);
	}
	tools.env = envp;
	tools.export = envp;
	// int i = 0;
	// while (tools.env[i])
	// {
	// 	printf("%i: %s\n", i + 1, tools.env[i]);
	// 	i++;
	// }
	save_pwd(&tools);
	while (1)
	{
		token = NULL;
		str = prompt();
		input = readline(str);
		lexer(input, &token);
		temp = token;
		add_history(input);
		check_quotes(&temp);
		check_tokens(&temp);
		check_builtin(temp, &tools, simple_cmds);
		// print_tokens(&temp);
		split_pipes(&temp);
		ft_free_token(&token);
		free_exit(str, input);
	}
	//TODO: meter en una función para liberar todo lo que haya en tools
	free(tools.pwd);
	free(tools.old_pwd);
	free_exit(str, input);
	return (0);
}

/* int	main(void)
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
		check_redirects(&temp);
		check_broken_pipes(&temp);
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
} */
