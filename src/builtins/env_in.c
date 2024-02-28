/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:34:22 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/02/28 17:52:45 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int ft_env(t_tools *tools, t_simple_cmds *simple_cmds)
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
		ft_putendl_fd("Error: Too many arguments", STDERR_FILENO);
	return (EXIT_SUCCESS);
}
