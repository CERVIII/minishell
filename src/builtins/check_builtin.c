/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:00:50 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/02/13 14:24:51 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	(*check_builtin(char *token))(t_tools *tools, t_simple_cmds *simple_cmds)
{
	int			i;
	static void	*builtin[7][2] = {
	{"echo", ft_echo},
	{"cd", ft_cd},
	{"pwd", ft_pwd},
	{"export", ft_export},
	{"unset", ft_unset},
	{"env", ft_env},
	{"exit", ft_exit},
	};

	i = 0;
	while (i < 7)
	{
		if (ft_strcmp(token, builtin[i][0]))
			return (builtin[i][1]);
		i++;
	}
	return (NULL);
}
