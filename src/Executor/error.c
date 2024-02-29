/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:04:32 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/02/29 11:38:38 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_error_cmd(t_tools *tools)
{
	dup2(tools->input, STDIN_FILENO);
	dup2(tools->output, STDOUT_FILENO);
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(tools->parser->str[0], STDERR_FILENO);
	ft_putendl_fd(": command not found", STDERR_FILENO);
	g_error = 127;
	// printf("ERROR %d\n", g_error);
	return(127);
}

int	ft_error_export(char *str)
{
	ft_putstr_fd("export: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putendl_fd(": not a valid identifier", STDERR_FILENO);
	g_error = 1;
	return (0);
}
