/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:34:22 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/01/11 11:42:25 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int ft_env(t_tools *tools)
{
	int	i;

	i = 0;
	while(tools->env[i])
	{
		ft_putendl_fd(tools->env[i], STDOUT_FILENO);
		i++;
	}
	return (EXIT_SUCCESS);
}