/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:33:53 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/01/26 14:42:34 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
char **ft_update_exp(char **exp, char **new_exp, char *var)
{
	int		i;
	int		j;
	char	*aux;
	
	i = 0;
	j = 0;
	while (exp[i])
	{
		if (ft_strchr(exp[i], '='))
			aux = ft_substr(exp[i], 0, ft_strlen(exp[i]) - ft_strlen(ft_strchr(exp[i], '=')));
		else
			aux = exp[i];
		if (ft_strcmp(var, aux) != 0) 
			new_exp[j++] = exp[i];
		if (ft_strchr(exp[i], '='))
			free(aux);
		i++;
	}
	return (new_exp);
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
	if (ft_strchr(var, '='))
		ft_update_env(env, cpy, var);
	ft_update_exp(env, cpy, var);
	return (cpy);	
}

char    **ft_del_export(char **exp, char *var)
{
    char	**cpy;
	int		i;

	i = 0;
	while (exp[i])
		i++;
	cpy = ft_calloc(sizeof(char *), i + 1);
	if (!cpy)
		return (NULL);
	ft_update_exp(exp, cpy, var);
	return (cpy);	
}

int	ft_unset(t_tools *tools, t_simple_cmds *simple_cmds)
{
    int     i;
    
    i = 0;
	(void)tools;
    simple_cmds = ft_calloc(sizeof(t_simple_cmds), 1); 
	simple_cmds->str = ft_calloc(2, sizeof(char *));
	simple_cmds->str[0] = ft_strdup("LANG");
	// simple_cmds->str[1] = ft_strdup("bb");
    //TODO: Gestionar cuando no hay argumentos/caracteres validos
	while (simple_cmds->str[i])
	{
    	tools->env = ft_del(tools->env, simple_cmds->str[i]);
    	tools->export = ft_del_export(tools->export, simple_cmds->str[i]);
		i++;
	}	
	return(EXIT_SUCCESS);
}