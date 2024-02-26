/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:46:02 by pcervill          #+#    #+#             */
/*   Updated: 2024/02/26 12:43:48 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	leaks(void)
{
	system("leaks -q minishell");
}

int	main(int argc, char **argv, char **env)
{
	t_tools	tools;

//	atexit(leaks);
	if (argc == 1 && !argv[1])
	{
		tools.env = env;
		minishell_loop(&tools);
		return (0);
	}
	else
	{
		printf("%sError: not accept arguments%s\n", RED, NORMAL);
		exit(1);
	}
}
