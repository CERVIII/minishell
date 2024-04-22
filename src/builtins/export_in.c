/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:33:36 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/04/22 16:07:05 by fdiaz-gu         ###   ########.fr       */
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
	char	*exp_name;
	int		i;

	i = -1;
	if (ft_strchr(var, '='))
		return (ft_cmpvar(export, var));
	else
	{
		while (export[++i])
		{
			if (ft_strchr(export[i], '='))
			{
				exp_name = ft_substr(export[i], 0, ft_strlen(export[i])
						- ft_strlen(ft_strchr(export[i], '=')));
				if (!ft_strcmp(var, exp_name))
					return (free(exp_name), 1);
				free(exp_name);
			}
			else
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

int	ft_split_vars(char *cmds, t_tools *tools)
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
		res = ft_check_vars(aux, tools);
		free(aux);
	}
	else
		res = ft_check_vars(cmds, tools);
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
			if (ft_split_vars(simple_cmds->str[i], tools) == 0)
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
	return (tools->g_error);
}
