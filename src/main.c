/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:46:02 by pcervill          #+#    #+#             */
/*   Updated: 2024/04/11 11:19:31 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	leaks(void)
{
	system("leaks -q minishell");
}

int	main(int argc, char **argv, char **envp)
{
	t_tools	tools;
	char	**aux;

	atexit(leaks);
	g_error = 0;
	if (argc != 1 || argv[1])
	{
		printf("This program does not accept arguments\n");
		exit(0);
	}
	aux = dup_matrix(envp);
	increment_shlvl(aux);
	tools.env = dup_matrix(aux);
	tools.exp = dup_matrix(aux);
	tools.input = dup(STDIN_FILENO);
	tools.output = dup(STDOUT_FILENO);
	save_pwd(&tools);
	init_tools(&tools);
	minishell_loop(&tools);
	return (0);
}
