/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:34:22 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/03/16 13:21:39 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_env(t_tools *tools, t_simple_cmds *simple_cmds)
{
	int	i;

	i = 0;
	if (!simple_cmds->str[1])
	{
		while (tools->env[i])
		{
			printf("%s\n", tools->env[i]);
			i++;
		}
	}
	else
	{
		ft_putstr_fd("env: ", STDERR_FILENO);
		ft_putstr_fd(simple_cmds->str[1], STDERR_FILENO);
		ft_putendl_fd(": No such file or directory", STDERR_FILENO);
		g_error = 127;
		return (g_error);
	}
	return (EXIT_SUCCESS);
}
