/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:55:21 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/02/28 13:18:41 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	handle_dup(t_simple_cmds *cmd, t_tools *tools, int pipe_fd[2], int fd_in)
{	
	if (cmd->prev && dup2(fd_in, STDIN_FILENO) < 0)
		perror("pipe_1");
	close(pipe_fd[0]);
	if (cmd->next && dup2(pipe_fd[1], STDOUT_FILENO) < 0)
		perror("pipe_2");
	close(pipe_fd[1]);
	if (cmd->prev)
		close(fd_in);
	execute_one(tools);
}

int	check_fd_heredoc(t_tools *tools, int end[2], t_simple_cmds *cmd)
{
	int	fd_in;

	if (tools->heredoc)
	{
		close(end[0]);
		fd_in = open(cmd->hd_file_name, O_RDONLY);
	}
	else
		fd_in = end[0];
	return (fd_in);
}

int execute(t_tools *tools)
{
	int pipe_fd[2];
	int fd_in;

	fd_in = STDIN_FILENO;
	while(tools->parser)
	{
		if (tools->parser->next)
			pipe(pipe_fd);
		ft_fork(tools, pipe_fd, fd_in, tools->parser);
		close(pipe_fd[1]);
		if (tools->parser->prev)
			close(fd_in);
		fd_in = check_fd_heredoc(tools, pipe_fd, tools->parser);
		if (tools->parser->next)
			tools->parser = tools->parser->next;
		else
			break ;
	}
	pipe_wait(tools->pid, tools->pipes);
	tools->parser = ft_simple_cmdsfirst(tools->parser);
	return (EXIT_SUCCESS);
}


int exec_cmd(t_tools *tools)
{
	char	*path;
	char	*route;

	path = get_path(tools->env);
	route = get_cmd_route(path, tools->parser->str[0]);
	execve(route, tools->parser->str, tools->env);
	return (ft_error_cmd(tools));
}

void	execute_single(t_tools *tools)
{
	int	pid;
	int	status;

	if (tools->parser->redirections > 0)
		if (handle_redirects(tools->parser->redirections))
			exit(1);
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
	check_expander(tools, tools->parser);
	if (tools->pipes == 0)
		execute_single(tools);
	else
	{
		tools->pid = ft_calloc(sizeof(int), tools->pipes + 2);
		if (!tools->pid)
		{
			free_tools(tools);
			return (0);
		}
		execute(tools);
	}
	return (EXIT_SUCCESS);
}

