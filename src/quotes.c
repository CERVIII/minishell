/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:36:04 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/12/13 12:24:22 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
}

void double_quotes(char *str, int flag)
{
	str++;
	printf("STR: %s\n", str);
	while (*str != '\"' && *str)
	{
		// else if (*str == '\'')
		//  	single_flag = 1;
		str++;
	}
	if (*str == '\"')
		// 	flag = 0;
		printf("Flaggg: %i\n", flag);
	if (flag != 0)
		printf("%sERROR: Unclosed quotes\n", RED);
}

void single_quotes(char *str, int flag)
{
	str++;
	while (*str != '\'')
	{
		if (*str == '\'')
			flag = 0;
		// else if (*str == '\"')
		//  	single_flag = 1;
		str++;
	}
	printf("Flag: %i\n", flag);
	if (flag != 0)
		printf("%sERROR: Unclosed quotes\n", RED);
}

//TODO:optimizar funcion
void read_input(char *argv)
{
	int single_flag;
	int double_flag;

	double_flag = 0;
	single_flag = 0;
	while (*argv)
	{
		if (*argv++ == '\"')
		{
			argv++;
			double_flag = 1;			
			while (*argv != '\"' && *argv)
				argv++;
			if (*argv == '\"')
				double_flag = 0;
			if (double_flag != 0)
				ft_err("ERROR: Unclosed quotes", 127);
		}
		else if (*argv == '\'')
		{
			if (double_flag == 0)
			{
				argv++;
				single_flag = 1;
				while (*argv != '\'' && *argv)
					argv++;
				if (*argv == '\'')
					single_flag = 0;
			}
			if (single_flag != 0)
				ft_err("ERROR: Unclosed quotes", 127);
		}
		argv++;
	}
}

int main(void)
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
}