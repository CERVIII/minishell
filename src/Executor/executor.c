/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:55:21 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/03/22 17:41:28 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	handle_dup(t_simple_cmds *cmd, t_tools *tool, int pipe_fd[2], int fd_in)
{
	if (cmd->prev)
		dup2(fd_in, STDIN_FILENO);
	close(pipe_fd[0]);
	if (cmd->next)
		dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	if (cmd->prev)
		close(fd_in);
	execute_one(tool);
}

int	execute(t_tools *tools)
{
	int				pipe_fd[2];
	int				fd_in;
	t_simple_cmds	*aux;

	fd_in = STDIN_FILENO;
	aux = tools->parser;
	while (tools->parser)
	{
		if (tools->parser->next)
			pipe(pipe_fd);
		check_heredoc(tools, tools->parser);
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
	tools->parser = aux;
	pipe_wait(tools->pid, tools->pipes);
	return (EXIT_SUCCESS);
}

int	exec_cmd(t_tools *tools)
{
	char	*path;
	char	*route;
	char	**cmd;

	if (!(tools->parser->str[1]))
		cmd = ft_split(tools->parser->str[0], ' ');
	else
		cmd = tools->parser->str;
	g_error = check_cmd(cmd);
	path = get_path(tools->env);
	route = get_cmd_route(path, cmd[0]);
	if (g_error == 0)
		execve(route, cmd, tools->env);
	else
		return (g_error);
	return (ft_error_cmd(tools, cmd));
}

void	execute_single(t_tools *tools)
{
	int	pid;
	int	status;

	check_heredoc(tools, tools->parser);
	if (tools->parser->num_redirections > 0)
	{
		if (handle_redirects(tools->parser))
			return ;
	}
	if (tools->parser->builtin)
	{
		g_error = tools->parser->builtin(tools, tools->parser);
		return ;
	}
	pid = fork();
	if (pid < 0)
		perror("fork");
	if (pid == 0)
		(signal(SIGQUIT, sig_handler), handle_cmd(tools));
	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_error = WEXITSTATUS(status);
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
