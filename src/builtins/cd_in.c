/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_in.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:32:48 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/03/04 14:09:44 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	update_pwd(t_tools *tools)
{
	char	*temp;

	temp = ft_strdup(tools->pwd);
	free(tools->old_pwd);
	tools->old_pwd = temp;
	free(tools->pwd);
	tools->pwd = getcwd(NULL, sizeof(NULL));
	return (1);
}

int	update_env(t_tools *tools)
{
	int		i;
	char	*temp;

	i = 0;
	while (tools->env[i])
	{
		if (ft_strncmp(tools->env[i], "PWD=", 4) == 0)
		{
			temp = ft_strjoin("PWD=", tools->pwd);
			free(tools->env[i]);
			tools->env[i] = temp;
		}
		else if (ft_strncmp(tools->env[i], "OLDPWD=", 7) == 0)
		{
			temp = ft_strjoin("OLDPWD=", tools->old_pwd);
			free(tools->env[i]);
			tools->env[i] = temp;
		}
		i++;
	}
	return (1);
}

int	ft_cd(t_tools *tools, t_simple_cmds *simple_cmds)
{
	int	res;

	res = 0;
	if (simple_cmds->str[1] && !simple_cmds->str[2])
	{
		res = chdir(simple_cmds->str[1]);
		if (res != 0)
		{
			perror("cd");
			g_error = 1;
		}
		update_pwd(tools);
		update_env(tools);
	}
	return (EXIT_SUCCESS);
}
