/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:34:22 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/02/12 13:17:02 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_env(t_tools *tools)
{
	int	i;

	i = 0;
	while (tools->env[i])
	{
		ft_putendl_fd(tools->env[i], STDOUT_FILENO);
		i++;
	}
	return (EXIT_SUCCESS);
}
