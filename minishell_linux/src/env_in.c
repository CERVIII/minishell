/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:34:22 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/04/24 11:21:11 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
		tools->g_error = 127;
		return (tools->g_error);
	}
	return (EXIT_SUCCESS);
}
