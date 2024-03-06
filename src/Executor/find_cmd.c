/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:41:01 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/03/06 11:29:49 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_cmd_route(char *path, char	*cmd)
{
	char	**possible_path;
	char	*cmd_route;
	char	*aux_route;
	char	*aux;
	int		i;

	i = 0;
	aux = ft_strtrim(path, "PATH=");
	possible_path = ft_split(aux, ':');
	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	while (possible_path[++i])
	{
		aux_route = ft_strjoin(possible_path[i], "/");
		cmd_route = ft_strjoin(aux_route, cmd);
		if (access(cmd_route, F_OK | X_OK) != -1)
			break ;
		else
			(free(aux_route), free(cmd_route));
	}
	free (aux);
	return (cmd_route);
}

char	*get_path(char **env)
{
	int		i;
	char	*envp_path;

	i = 0;
	envp_path = NULL;
	while (env[i])
	{
		if (ft_strncmp("PATH", env[i], 4) == 0)
		{
			envp_path = env[i];
			return (envp_path);
		}
		i++;
	}
	return (NULL);
}
