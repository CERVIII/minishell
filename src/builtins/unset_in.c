/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:33:53 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/02/28 18:51:03 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int ft_check_unset_exists(char **exp, char *var)
{
	int		i;
	char	*var_name;
	
	i = 0;
	while (exp[i])
	{
		if (ft_strchr(exp[i], '='))
		{
			var_name = ft_substr(exp[i], 0, ft_strlen(exp[i])
				- ft_strlen(ft_strchr(exp[i], '=')));
			if (!ft_strncmp(var_name, var, ft_strlen(var_name)))
				return (free(var_name),1);			
		}
		else
		{
			if (!ft_strcmp(var, exp[i]))
				return (1);
		}
		i++;
	}
	return (0);
}

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
			aux = ft_substr(env[i], 0,
					ft_strlen(env[i]) - ft_strlen(ft_strchr(env[i], '=')));
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
/* 	i = 0;
	while (cpy[i])
	{
		printf("-> %s\n", cpy[i]);
		i++;
	} */
	free(str);
	return (cpy);
}

int	ft_unset(t_tools *tools, t_simple_cmds *simple_cmds)
{
    int     i;
    
    i = 1;
	while (simple_cmds->str[i])
	{
		if(ft_check_unset_exists(tools->exp, simple_cmds->str[i]))
		{
			printf("EXITE\n");
    		tools->exp = ft_del(tools->exp, simple_cmds->str[i]);
    		tools->env = ft_del(tools->env, simple_cmds->str[i]);
		}
		i++;
	}
	return(EXIT_SUCCESS);
}
