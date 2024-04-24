/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_in.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:34:18 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/04/24 11:21:20 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

void	ft_check_exit(t_tools *tools, char **str, int code)
{
	if (!str[1])
		code = 0;
	else if (!check_if_nb(str[1]))
	{
		code = ft_atoi(str[1]);
		if (code < 0)
		{
			while (code < 0)
				code = code + 256;
		}
		else
			while (code > 0)
				code = code - 256;
	}
	else
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(str[1], STDERR_FILENO);
		ft_putendl_fd(": numeric argument required", STDERR_FILENO);
		code = 255;
		tools->g_error = 1;
	}
	printf("exit\n");
	exit(code);
}

int	ft_exit(t_tools *tools, t_simple_cmds *simple_cmds)
{
	int	code;

	code = 0;
	(void) tools;
	if (simple_cmds->str[1] && simple_cmds->str[2]
		&& !ft_all_char(simple_cmds->str))
	{
		ft_putstr_fd("exit: too many arguments\n", STDERR_FILENO);
		tools->g_error = 1;
		return (EXIT_FAILURE);
	}
	ft_check_exit(tools, simple_cmds->str, code);
	return (EXIT_SUCCESS);
}
