/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fede <fede@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:33:53 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/01/20 14:15:12 by fede             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
//TODO: Export incluye variables sin valor
char **ft_update_env(char **env, char **new_env, char *var)
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
		if (ft_strchr(env[i], '='))
			free(aux);
		i++;
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
    int     i;
    
    i = 0;
    simple_cmds = malloc(sizeof(t_simple_cmds)); 
	simple_cmds->str = malloc(2 * sizeof(char *));
	simple_cmds->str[0] = ft_strdup("LANG");
	simple_cmds->str[1] = ft_strdup("bb");
    //TODO: Gestionar cuando no hay argumentos/caracteres invalidos
	// while (simple_cmds->str[i])
	// {
    	tools->env = ft_del(tools->env, simple_cmds->str[0]);
    	tools->export = ft_del(tools->export, simple_cmds->str[0]);
		// i++;
	// }	
	return(EXIT_SUCCESS);
}