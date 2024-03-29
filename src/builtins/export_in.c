/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:33:36 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/03/28 13:12:46 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**ft_add(char **env, char *var)
{
	char	**new_env;
	int		i;

	i = 0;
	while (env[i])
		i++;
	new_env = ft_calloc(i + 2, sizeof(char *));
	if (!new_env)
		return (NULL);
	new_env = ft_update_export(env, new_env, var);
	i = 0;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
	return (new_env);
}

int	ft_check_if_exists(char **export, char *var)
{
	char	*var_name;
	int		i;

	i = -1;
	if (ft_strchr(var, '='))
	{
		var_name = ft_substr(var, 0, ft_strlen(var)
				- ft_strlen(ft_strchr(var, '=')));
		while (export[++i])
		{
			if (!ft_strcmp(var_name, export[i]))
				return (free(var_name), 1);
		}
		free(var_name);
	}
	else
	{
		while (export[++i])
		{
			if (!ft_strcmp(var, export[i]))
				return (1);
		}
	}
	return (0);
}

int	check_if_nb(char *str)
{
	int	i;	

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		return (0);
	return (1);
}

int	ft_split_vars(char *cmds)
{
	int		i;
	int		res;
	char	*aux;

	i = 0;
	res = 0;
	if (ft_strchr(cmds, '='))
	{
		aux = ft_substr(cmds, 0, ft_strlen(cmds)
				- ft_strlen(ft_strchr(cmds, '=')));	
		res = ft_check_vars(aux);
		free(aux);
	}
	else
		res = ft_check_vars(cmds);
	return (res);
}

int	ft_export(t_tools *tools, t_simple_cmds *simple_cmds)
{
	int	i;

	i = 0;
	if (!simple_cmds->str[1] || simple_cmds->str[1][0] == '\0')
		ft_print_export(tools->exp);
	else
	{
		while (simple_cmds->str[++i])
		{
			if (ft_split_vars(simple_cmds->str[i]) == 0)
			{
				if (ft_check_if_exists(tools->exp, simple_cmds->str[i]))
					(ft_update_var(tools->env, simple_cmds->str[i], i),
						ft_update_var(tools->exp, simple_cmds->str[i], i));
				else
				{
					if (ft_strchr(simple_cmds->str[i], '='))
						tools->env = ft_add(tools->env, simple_cmds->str[i]);
					tools->exp = ft_add(tools->exp, simple_cmds->str[i]);
				}
			}
		}
	}
	return (EXIT_SUCCESS);
}
