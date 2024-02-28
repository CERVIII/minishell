/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_in.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:34:18 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/02/28 11:22:07 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_all_char(char **str)
{
	int	i;

    i = 1;
    if (str[i])
    {
        while(str[i])
        {
            if (!check_if_nb(str[i]))      
                return (0);
            i++;
        }
    }
    return(1);
}

void	ft_free_tools(t_tools *tools)
{
	int	i;

    int i = 0;
    while(tools->env[i])
    {
        free(tools->env[i]);
        i++;
    }
    i = 0;
    // while(tools->exp[i])
    // {
    //     free(tools->exp[i]);
    //     i++;
    // }
    // free(tools->env);
    free(tools->pwd);
    free(tools->old_pwd);
}
void	ft_check_exit(char **str)
{
    int code;
    
    if (!str[1])
        code = 0;
    else if (!check_if_nb(str[1]))
    {
        code = ft_atoi(str[1]);
        if (code < 0)
        code = 255;
    }     
    else
    {
        printf("minishell: exit: %s: numeric argument required\n", str[1]);
        code = 255;
    }
    exit(code);
}

int ft_exit(t_tools *tools, t_simple_cmds *simple_cmds)
{    
    (void) tools;
	if (simple_cmds->str[1] && simple_cmds->str[2] && !ft_all_char(simple_cmds->str))
    {
        printf("exit: too many arguments\n");
        return (EXIT_FAILURE);
    }
    ft_free_tools(tools);
    ft_check_exit(simple_cmds->str);
    return (EXIT_SUCCESS);
}
