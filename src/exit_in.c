/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_in.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:34:18 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/01/18 16:22:19 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int ft_all_char(char **str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if (!check_if_nb(str[i]))      
            return (0);
        i++;
    }
    return(1);
}

void ft_free_tools(t_tools *tools)
{

    int i = 0;
    while(tools->env[i])
    {
        free(tools->env[i]);
        i++;
    }
    i = 0;
    // while(tools->export[i])
    // {
    //     free(tools->export[i]);
    //     i++;
    // }
    free(tools->pwd);
    free(tools->old_pwd);
}
void    ft_check_exit(char **str)
{
    int code;
    
    if (!str[0])
        code = 0;
    else if (!check_if_nb(str[0]))
    {
        code = ft_atoi(str[0]);
        if (code < 0)
        code = 255;
    }     
    else
    {
        ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(str[0], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
        code = 255;
    }
    exit(code);
}

int ft_exit(t_tools *tools, t_simple_cmds *simple_cmds)
{
    simple_cmds = malloc(sizeof(t_simple_cmds)); 
	simple_cmds->str = malloc(1 * sizeof(char *));
	simple_cmds->str[0] = ft_strdup("10");
    
	// if (simple_cmds->str[1] && simple_cmds->str[2] && !ft_all_char(simple_cmds->str))
    // {
    //     ft_putendl_fd("exit: too many arguments\n", STDERR_FILENO);
    //     return (EXIT_FAILURE);
    // }
    (void) tools;
    // ft_free_tools(tools);
    ft_check_exit(simple_cmds->str);
    return (EXIT_SUCCESS);
}
