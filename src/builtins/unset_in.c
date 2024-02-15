/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:33:53 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/02/15 11:03:31 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char **ft_update(char **env, char **new_env, char *var)
{
	int		i;
	int		j;
	char	*aux;
	
	i = 0;
	j = 0;
	while (env[i])
	{
		if (ft_strchr(env[i], '='))
			aux = ft_substr(env[i], 0, ft_strlen(env[i]) - ft_strlen(ft_strchr(env[i], '=')));
		else
			aux = env[i];
		if (ft_strcmp(var, aux) != 0)
			new_env[j++] = env[i];
		else
			free(env[i]);
		free(aux);
		i++;
	}
	return (new_env);
}

char    **ft_del(char **str, char *var)
{
    char	**cpy;
	int		i;

	i = 0;
	while (str[i])
		i++;
	cpy = ft_calloc(sizeof(char *), i);
	if (!cpy)
		return (NULL);
	cpy = ft_update(str, cpy, var);
	return (cpy);
}

int	ft_unset(t_tools *tools, t_simple_cmds *simple_cmds)
{
    int     i;
    
    i = 1;
	(void)tools;
    //TODO: Gestionar cuando no hay argumentos/caracteres validos
	while (simple_cmds->str[i])
	{
    	tools->env = ft_del(tools->env, simple_cmds->str[i]);
    	tools->exp = ft_del(tools->exp, simple_cmds->str[i]);
		i++;
	}
	return(EXIT_SUCCESS);
}
