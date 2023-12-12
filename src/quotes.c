/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotation_marks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:36:04 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/12/12 15:28:38 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void free_exit(char *str, char *input)
{
	free(str);
	free(input);
	return;
}

int	ft_err(char *error, int nb)
{
	printf("%s%s\n", RED, error);
	printf("%s", NORMAL);
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

void	check_quotes(char *str)
{
	int single_count;
	int double_count;

	double_count = 0;
	single_count = 0;
	while (*str)
	{
		if (*str == '\"')
			double_count++;
		else if (*str == '\'')
			single_count++;
		str++;
	}
	if (single_count % 2 != 0 || double_count % 2 != 0)
		ft_err("Error: Unclosed quotes", 127);

}
void read_input(char *argv)
{
	check_quotes(argv);
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