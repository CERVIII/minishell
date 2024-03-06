/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_in.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:32:52 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/03/04 15:34:27 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	printf_args(int i, char **str)
{
	while (str[i])
	{
		ft_putstr_fd(str[i++], STDOUT_FILENO);
		if (str[i])
			ft_putchar_fd(' ', STDOUT_FILENO);
	}
}

int	ft_echo(t_tools *tools, t_simple_cmds *simple_cmds)
{
	int		i;
	int		j;
	bool	flag;

	i = 1;
	(void) tools;
	flag = false;
	while (simple_cmds->str[i] && simple_cmds->str[i][0] == '-'
		&& simple_cmds->str[i][1] == 'n')
	{
		j = 1;
		while (simple_cmds->str[i][j] == 'n')
			j++;
		if (simple_cmds->str[i][j] == '\0')
			flag = true;
		else
			break ;
		i++;
	}
	printf_args(i, simple_cmds->str);
	if (flag == false)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
