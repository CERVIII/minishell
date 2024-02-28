/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:04:32 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/02/28 13:22:09 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_error_cmd(t_tools *tools)
{
	dup2(tools->input, STDIN_FILENO);
	dup2(tools->output, STDOUT_FILENO);
	printf("minishell: %s: command not found\n", tools->parser->str[0]);
	return(127);
}
