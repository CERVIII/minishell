/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_in.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:34:18 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/03/20 18:41:17 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_all_char(char **str)
{
	int	i;

	i = 1;
	if (str[i])
	{
		while (str[i])
		{
			if (!check_if_nb(str[i]))
				return (0);
			i++;
		}
	}
	return (1);
}

void	ft_free_tools(t_tools *tools)
{
	int	i;

	i = 0;
	while (tools->env[i])
	{
		free(tools->env[i]);
		i++;
	}
	i = 0;
	if (tools->env[0])
	(free(tools->pwd), free(tools->old_pwd));
}

void	ft_check_exit(char **str)
{
	int	code;

	if (!str[1])
		code = 0;
	else if (!check_if_nb(str[1]))
	{
		code = ft_atoi(str[1]);
		if (code < 0)
			code = 256 + code;
	}
	else
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(str[1], STDERR_FILENO);
		ft_putendl_fd(": numeric argument required", STDERR_FILENO);
		code = 255;
		g_error = 1;
	}
	printf("exit\n");
	exit(code);
}

int	ft_exit(t_tools *tools, t_simple_cmds *simple_cmds)
{
	(void) tools;
	if (simple_cmds->str[1] && simple_cmds->str[2]
		&& !ft_all_char(simple_cmds->str))
	{
		ft_putstr_fd("exit: too many arguments\n", STDERR_FILENO);
		g_error = 1;
		return (EXIT_FAILURE);
	}
	ft_free_tools(tools);
	ft_check_exit(simple_cmds->str);
	return (EXIT_SUCCESS);
}
