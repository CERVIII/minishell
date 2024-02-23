/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:55:21 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/02/23 15:17:06 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int execute(t_tools *tools)
{
	int pipe_fd[2];
	while(tools->parser)
	{
		if (tools->parser->next)
			pipe(pipe_fd);
		
	}
	return (EXIT_SUCCESS);
}


int exec_cmd(t_tools *tools)
{
	char	*path;
	char	*route;

	path = get_path(tools->env);
	route = get_cmd_route(path, tools->parser->str[0]);
	if (execve(route, tools->parser->str, tools->env) == -1)
	{
		perror("execve");
    	printf("Después de execve (falló)\n");
		return(127);
	}
	return (0);
}


void	execute_single(t_tools *tools)
{
	pid_t	pid;
	int	status;

	if (tools->parser->redirections > 0)
		handle_redirects(tools->parser->redirections);
	if (tools->parser->builtin)
		tools->parser->builtin(tools, tools->parser);
	else
	{	
		pid = fork();
		if (pid < 0)
		{
			perror("fork");
			return ;
		}
		if (pid == 0)
		{
			if (tools->parser->str[0][0])
				exec_cmd(tools);
		}
		if (waitpid(pid, &status, 0) == -1)
			(perror("waitpid"), exit(0));
	}
}

int	before_execution(t_tools *tools)
{
	if (tools->pipes == 0)
		execute_single(tools);
	else
	{
		tools->pid = ft_calloc(sizeof(int), tools->pipes + 2);
		if (!tools->parser)
		{
			free_tools(tools);
			return (0);
		}
		// execute(tools);
	}
	return (EXIT_SUCCESS);
}

