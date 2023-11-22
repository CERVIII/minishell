/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:46:02 by pcervill          #+#    #+#             */
/*   Updated: 2023/11/22 13:31:36 by pcervill         ###   ########.fr       */
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

char *prompt(void)
{
    char *end = NULL;
    char *cwd = getcwd(NULL, 0);

    if (!cwd)
        return NULL;

    end = ft_strjoin(BLUE, cwd);
    free(cwd); // Liberar la memoria asignada por getcwd()

    if (!end)
        return NULL;

    char *temp = end;

    // Realizas todas las operaciones de concatenación con una sola llamada a ft_strjoin
    end = ft_strjoin(temp, "\n");
    free(temp); // Liberar la memoria asignada a la ruta original

    if (!end)
        return NULL;

    temp = ft_strjoin(end, GREEN);
    free(end); // Liberar la memoria asignada a "\n"

    if (!temp)
        return NULL;

    end = ft_strjoin(temp, "> ");
    free(temp); // Liberar la memoria asignada a GREEN

    if (!end)
        return NULL;

    temp = ft_strjoin(end, NORMAL);
    free(end); // Liberar la memoria asignada a "> "

    return temp;
}


int	main(void)
{
	char	*input;
	char	*str;
	t_token	*token;

	token = NULL;
	atexit(leaks);
	while (1)
	{
		str = prompt();
		input = readline(str);
		if (!input || !ft_strcmp(input, "exit"))
		{
			printf("%sSaliendo de minishell...%s\n", RED, NORMAL);
			free(str);
			free(input);
			break ;
		}
		lexer(input, &token);
		// Borrar printf de token ↓
		t_token	*temp = token;
		while (temp)
		{
			printf("Token: %s	Type: %d\n", temp->token, temp->type);
			temp = temp->next;
		}
		ft_free_token(&token);
		free(str);
		free(input);
	}
	return (0);
}
