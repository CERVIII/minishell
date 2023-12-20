/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:36:04 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/12/18 16:16:29 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
/*
void free_exit(char *str, char *input)
{
	free(str);
	free(input);
	return;
}

int ft_err(char *msg, int nb)
{
	printf("%s%s%s\n", RED, msg, NORMAL);
	return (nb);
}

char *prompt(void)
{
	char *end;
	char *cwd;

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
}*/

t_token **double_quotes(t_token **lst, int double_flag)
{
	double_flag = 1;
	if ((*lst)->next)
	{
		lst = &(*lst)->next;
		while ((*lst)->next && (*lst)->type != 6)
			lst = &(*lst)->next;
		if ((*lst)->type == 6)
			double_flag = 0;
	}
	if (double_flag != 0)
		ft_err("ERROR: Unclosed quotes", 127);
	return (lst);
}

t_token **single_quotes(t_token **lst, int single_flag, int double_flag)
{
	if (double_flag == 0)
	{
		single_flag = 1;
		if ((*lst)->next)
		{
			lst = &(*lst)->next;
			while ((*lst)->next && (*lst)->type != 7)
				lst = &(*lst)->next;
			if ((*lst)->type == 7)
				single_flag = 0;
		}
	}
	if (single_flag != 0)
		ft_err("ERROR: Unclosed quotes", 127);
	return (lst);
}

// TODO:optimizar funcion
void check_quotes(t_token **lst)
{
	int single_flag;
	int double_flag;

	double_flag = 0;
	single_flag = 0;
	while ((*lst))
	{
		if ((*lst)->type == 6)
			lst = double_quotes(lst, double_flag);
		else if ((*lst)->type == 7)
			lst = single_quotes(lst, single_flag, double_flag);
		lst = &(*lst)->next;		
	}	
}

/*int main(void)
{
	char *input;
	char *str;
	t_token *token;

	// atexit(leaks);
	while (1)
	{
		token = NULL;
		str = prompt();
		input = readline(str);
		if (!input || !ft_strcmp(input, "exit"))
			break;
		read_input(input);
		free_exit(str, input);
	}
	printf("%sSaliendo de minishell...%s\n", RED, NORMAL);
	free_exit(str, input);
	return (0);
} */