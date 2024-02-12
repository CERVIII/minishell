/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:00:50 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/02/12 17:59:20 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	(*check_builtin(char *token))(t_tools *tools, t_simple_cmds *simple_cmds)
{
	(void) token;
	// if (ft_strcmp(token, "cd") == 0)
	// 	// return (1);
	// 	ft_cd(tools, "../..");
	// else if (ft_strcmp(token, "env") == 0)
	// 	// return (2);
	// 	ft_env(tools);
	// else if (ft_strcmp(token, "pwd") == 0)
	// 	// return (3);
	// 	// ft_pwd(tools);
	// else if (ft_strcmp(token, "export") == 0)
	// 	return (4);
	// 	// ft_export(tools, simple_cmds);
	// else if (ft_strcmp(token, "unset") == 0)
	// 	return (5);
	// 	// ft_unset(tools, simple_cmds);
	// else if (ft_strcmp(token, "echo") == 0)
	// 	return (6);
	// 	// ft_echo(simple_cmds);
	// else if (ft_strcmp(token, "exit") == 0)
	// 	return (7);
	// 	// ft_exit(tools, simple_cmds);
	return (NULL);
}
