/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:33:24 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/02/13 12:58:08 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_pwd(t_tools *tools, t_simple_cmds *simple_cmds)
{
	(void) simple_cmds;

	ft_putendl_fd(tools->pwd, STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
