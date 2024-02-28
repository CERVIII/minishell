/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:34:22 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/02/28 11:21:59 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int ft_env(t_tools *tools, t_simple_cmds *simple_cmds)
{
	int	i;
	(void) simple_cmds;

	i = 0;
	while (tools->env[i])
	{
		printf("%s\n", tools->env[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
