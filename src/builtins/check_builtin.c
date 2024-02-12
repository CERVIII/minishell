/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:00:50 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/02/12 11:55:00 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	*check_builtin(char *token, t_tools *tools, t_simple_cmds *simple_cmds)
{
	int *a;
	
	a = &tools->pipes;
	if (ft_strcmp(token, "cd") == 0)
		ft_cd(tools, "../..");
	else if (ft_strcmp(token, "env") == 0)
		ft_env(tools);
	else if (ft_strcmp(token, "pwd") == 0)
		ft_pwd(tools);
	else if (ft_strcmp(token, "export") == 0)
		ft_export(tools, simple_cmds);
	else if (ft_strcmp(token, "unset") == 0)
		ft_unset(tools, simple_cmds);
	else if (ft_strcmp(token, "echo") == 0)
		ft_echo(simple_cmds);
	else if (ft_strcmp(token, "exit") == 0)
		ft_exit(tools, simple_cmds);
	else
		printf("holadadggdsg\n");
	return (a);
}
