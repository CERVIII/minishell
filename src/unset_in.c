/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fede <fede@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:33:53 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/01/13 21:50:49 by fede             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char **ft_update_env(char **env, char **new_env, char *var)
{
	int		i;
	int		j;
	char	*aux_equal;
	char	*aux;
	
	i = 0;
	j = 0;
	while (env[i])
	{
		aux_equal = ft_strchr(env[i], 61);
		if (aux_equal)
			aux = ft_substr(env[i], 0, ft_strlen(env[i]) - ft_strlen(aux_equal));
		else
			aux = ft_strdup(env[i]);
		if (ft_strcmp(var, aux) != 0)
			new_env[j++] = env[i];
		else
			free(env[i]);
		i++;
		free(aux);
	}
	return (new_env);
}

char    **ft_del(char **env, char *var)
{
    char	**cpy;
	int		i;

	i = 0;
	while (env[i])
		i++;
	cpy = ft_calloc(sizeof(char *), i + 1);
	if (!cpy)
		return (NULL);
	ft_update_env(env, cpy, var);
	return (cpy);	
}

int	ft_unset(t_tools *tools, t_simple_cmds *simple_cmds)
{
	char    **env_cpy;
    int     i;
    
    i = 0;
    simple_cmds = malloc(sizeof(t_simple_cmds)); 
	simple_cmds->str = malloc(2 * sizeof(char *));
	simple_cmds->str[0] = ft_strdup("LANG");
	simple_cmds->str[1] = ft_strdup("LESS");
    //TODO: Gestionar cuando no hay argumentos/caracteres invalidos
	// while (simple_cmds->str[i])
	// {
    	env_cpy = ft_del(tools->env, simple_cmds->str[0]);
		free(tools->env);
		tools->env = env_cpy;
    	env_cpy = ft_del(tools->env, simple_cmds->str[1]);
		free(tools->env);
		tools->env = env_cpy;
		// i++;
	// }	
	free(simple_cmds->str[0]);
	free(simple_cmds->str[1]);
	free(simple_cmds);
	return(EXIT_SUCCESS);
}