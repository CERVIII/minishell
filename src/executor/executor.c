/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fede <fede@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:55:21 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/02/26 18:26:42 by fede             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_simple_cmds	*ft_simple_cmdsfirst(t_simple_cmds *map)
{
	if (!map)
		return (NULL);
	while (map->prev != NULL)
		map = map->prev;
	return (map);
}

int	pipe_wait(int *pid, int amount)
{
	int	i;
	int	status;

	i = 0;
	while (i < amount)
	{
		waitpid(pid[i], &status, 0);
		i++;
	}
	waitpid(pid[i], &status, 0);
	return (EXIT_SUCCESS);
}

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
	execute_single(tools);
}

int	ft_fork(t_tools *tools, int pipe_fd[2], int fd_in, t_simple_cmds *parser)
{
	static int i = 0;
	tools->pid[i] = fork();
	if (tools->pid[i] < 0)
	{
		perror("pid_fork");
		return (EXIT_FAILURE);
	}
	if (tools->pid[i] == 0)
		handle_dup(parser, tools, pipe_fd, fd_in);
	i++;
	return (EXIT_SUCCESS);
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
	return (ft_error_cmd(tools->parser->str[0]));
}

void	execute_single(t_tools *tools)
{
	int	pid;
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
		if (!tools->pid)
		{
			free_tools(tools);
			return (0);
		}
		execute(tools);
	}
	return (EXIT_SUCCESS);
}

