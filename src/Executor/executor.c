/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:55:21 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/03/04 14:59:20 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	handle_dup(t_simple_cmds *cmd, t_tools *tools, int pipe_fd[2], int fd_in)
{	
	if (cmd->prev)
		dup2(fd_in, STDIN_FILENO);
	close(pipe_fd[0]);
	if (cmd->next)
		dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	if (cmd->prev)
		close(fd_in);
	execute_one(tools);
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
	return (EXIT_SUCCESS);
}


int	exec_cmd(t_tools *tools)
{
	char	*path;
	char	*route;
	char	**cmd;
	DIR 	*dir;
	if (!(tools->parser->str[1]))
		cmd = ft_split(tools->parser->str[0], ' ');
	else
		cmd = tools->parser->str;
	//TODO: HACER BIEN
	if (ft_strncmp(cmd[0], "./", 2) == 0 || cmd[0][0] == '/')
	{
		dir = opendir(cmd[0]);
		if (dir != NULL) {
			closedir(dir);
			ft_putendl_fd(" is a directory", STDERR_FILENO);
			g_error = 126;
			return (126);
		}
		else if ((access(cmd[0], F_OK) == 0) && (access(cmd[0], X_OK) == -1))
		{
			perror("Error");
			g_error = 126;
			return (126);
		}
		else
		{
			perror("Error");
			g_error = 127;
			return (127);
		}
	}
	path = get_path(tools->env);
	route = get_cmd_route(path, cmd[0]);
	execve(route, cmd, tools->env);
	return (ft_error_cmd(tools));
}

void	execute_single(t_tools *tools)
{
	int	pid;
	int	status;

	if (tools->parser->redirections > 0)
		if (handle_redirects(tools->parser->redirections))
			return ;
	if (tools->parser->builtin)
	{
		tools->parser->builtin(tools, tools->parser);
		return ;
	}
	pid = fork();
	if (pid < 0)
		perror("fork");
	if (pid == 0)
		handle_cmd(tools);
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

