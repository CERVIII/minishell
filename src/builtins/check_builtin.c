/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fede <fede@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:00:50 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/01/21 12:48:12 by fede             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_builtin(t_token *tokens, t_tools *tools, t_simple_cmds *simple_cmds)
{
	if (ft_strcmp(tokens->token, "cd") == 0)
		ft_cd(tools, "../..");
	else if (ft_strcmp(tokens->token, "env") == 0)
		ft_env(tools);
	else if (ft_strcmp(tokens->token, "pwd") == 0)
		ft_pwd(tools);
	else if (ft_strcmp(tokens->token, "export") == 0)
		ft_export(tools, simple_cmds);
	else if (ft_strcmp(tokens->token, "unset") == 0)
		ft_unset(tools, simple_cmds);
	else if (ft_strcmp(tokens->token, "echo") == 0)
		ft_echo(simple_cmds);
	else if (ft_strcmp(tokens->token, "exit") == 0)
		ft_exit(tools, simple_cmds);
	else
		printf("hola\n");
	return (1);
}
