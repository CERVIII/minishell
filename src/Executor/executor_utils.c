/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:31:03 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/04/23 12:13:33 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	handle_cmd(t_tools *tools)
{
	int	exit_code;

	exit_code = 0;
	if (tools->parser->str[0] && tools->parser->str[0][0])
		exit_code = exec_cmd(tools);
	exit(exit_code);
}

int	ft_fork(t_tools *tools, int pipe_fd[2], int fd_in, t_simple_cmds *parser)
{
	static int	i = 0;

	if (tools->reset == true)
	{
		i = 0;
		tools->reset = false;
	}
	tools->pid[i] = fork();
	if (tools->pid[i] < 0)
	{
		perror("pid_fork");
		return (EXIT_FAILURE);
	}
	if (tools->pid[i] == 0)
		(signal(SIGQUIT, sig_handler),
			handle_dup(parser, tools, pipe_fd, fd_in));
	tools->g_error = 130;
	i++;
	return (EXIT_SUCCESS);
}

int	pipe_wait(t_tools *tools, int amount)
{
	int	i;
	int	status;

	i = 0;
	while (i < amount)
	{
		waitpid(tools->pid[i], &status, 0);
		i++;
	}
	waitpid(tools->pid[i], &status, 0);
	if (WIFEXITED(status))
		tools->g_error = WEXITSTATUS(status);
	return (EXIT_SUCCESS);
}

void	execute_one(t_tools *tools)
{
	int	exit_code;

	exit_code = 0;
	if (tools->parser->num_redirections > 0)
	{
		if (handle_redirects(tools->parser, tools->g_error))
		{
			tools->g_error = 1;
			exit(1);
		}
	}
	if (tools->parser->builtin)
		tools->parser->builtin(tools, tools->parser);
	else if (tools->parser->str[0])
		exit_code = exec_cmd(tools);
	exit(exit_code);
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
