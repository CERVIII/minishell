/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:33:36 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/02/13 18:36:54 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**ft_add_var(char **env, char *var)
{
	char	**new_env;
	int		i;

	i = 0;
	while(env[i])
		i++;
	new_env = ft_calloc(i + 2, sizeof(char *));
	if (!new_env)
		return (NULL);
	ft_update_export(env, new_env, var);
	return (new_env);
}

int	ft_check_if_exists(char **export, char *var)
{
	char	*var_name;
	int		i;

	i = 0;
	if (ft_strchr(var, '='))
	{
		var_name = ft_substr(var, 0, ft_strlen(var) - ft_strlen(ft_strchr(var, '=')));
		while (export[i])
		{
			if (ft_strncmp(var_name, export[i], ft_strlen(var_name)) == 0)
				return (1);
			i++;
		}
		free(var_name);
	}
	else
		while (export[i])
		{
			if (ft_strncmp(var, export[i], ft_strlen(var)) == 0)
				return (1);
			i++;
		}
	return (0);
}

int	check_if_nb(char *str)
{
	int	i;	

	i = 0;
	while (str[i] == 32)
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

int	ft_check_vars(char *cmds)
{
	int		i;
	char	*aux;

	i = 0;
	if (ft_strchr(cmds, '='))
	{
		aux = ft_substr(cmds, 0, ft_strlen(cmds) - ft_strlen(ft_strchr(cmds, '=')));
		ft_check_vars(aux);
		free (aux);
	}
	else
	{
		if (!check_if_nb(cmds))
			return (0);
		else if (cmds[0] == '=')
			return (0);
		while (cmds[i])
		{
			if (!ft_isalpha(cmds[i]) && cmds[i] != '_')
				return (0);
			i++;
		}
	}
	return (1);
}

int	ft_export(t_tools *tools, t_simple_cmds *simple_cmds)
{
	int i;

	i = 0;
	if (!simple_cmds->str[1] || simple_cmds->str[1][0] == '\0')
	{
		printf("QUE PASSA\n");
		ft_print_export(tools->exp);
	}
	else
	{
		while (simple_cmds->str[i])
		{
			if (ft_check_vars(simple_cmds->str[i]))
			{				
				if(ft_check_if_exists(tools->exp, simple_cmds->str[i]))
					ft_update_var(tools->exp, tools->env, simple_cmds->str[i]);
				else
				{
					if (ft_strchr(simple_cmds->str[i], '='))
						tools->env = ft_add_var(tools->env, simple_cmds->str[i]);
					tools->exp = ft_add_var(tools->exp, simple_cmds->str[i]);
				}
			}
			i++;
		}
	}
	return (1);
}
