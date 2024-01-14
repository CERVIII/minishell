/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_in.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fede <fede@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:34:18 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/01/14 19:48:30 by fede             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void    ft_check_exit(char **str)
{
    int code;
    
    if (!str[1])
        code = 0;
    else if (check_if_nb(str[1]))
        code = ft_atoi(str[1]);
    else
    {
        ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(str[1], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
        code = 255;
    }
    exit(code);
}
int ft_exit(t_tools *tools, t_simple_cmds *simple_cmds)
{
	if (simple_cmds->str[2])
    {
        ft_putendl_fd("exit: too many arguments\n", STDERR_FILENO);
        return (EXIT_FAILURE);
    }
    ft_check_exit(simple_cmds->str);
    return (EXIT_SUCCESS);
}