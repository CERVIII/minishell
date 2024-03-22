/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:04:32 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/03/22 11:57:46 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


int ft_redirect_error(char *token)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(token, STDERR_FILENO);
	ft_putendl_fd(": ambiguous redirect", STDERR_FILENO);
	return (EXIT_FAILURE);
}
int	check_cmd(char **cmd)
{
	DIR	*dir;

	if (ft_strncmp(cmd[0], "./", 2) == 0 || cmd[0][0] == '/')
	{
		dir = opendir(cmd[0]);
		if (dir != NULL)
		{
			(closedir(dir), ft_putendl_fd(" is a directory", STDERR_FILENO));
			g_error = 126;
			return (g_error);
		}
		else if ((access(cmd[0], F_OK) == 0) && (access(cmd[0], X_OK) == -1))
		{
			perror(cmd[0]);
			g_error = 126;
			return (g_error);
		}
		else if (access(cmd[0], F_OK) == -1)
		{
			perror(cmd[0]);
			g_error = 127;
			return (g_error);
		}
	}
	return (EXIT_SUCCESS);
}

int	ft_error_cmd(t_tools *tools)
{
	dup2(tools->input, STDIN_FILENO);
	dup2(tools->output, STDOUT_FILENO);
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(tools->parser->str[0], STDERR_FILENO);
	ft_putendl_fd(": command not found", STDERR_FILENO);
	g_error = 127;
	return (g_error);
}

int	ft_error_export(char *str)
{
	ft_putstr_fd("export: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putendl_fd(": not a valid identifier", STDERR_FILENO);
	g_error = 1;
	return (EXIT_FAILURE);
}
