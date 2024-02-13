/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:01:49 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/02/13 17:31:35 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//TODO: Revisar las 6 variables
void	ft_join_export(char **exp)
{
	int		i;

	i = 0;
	while (exp[i])
	{
		if (ft_strchr(exp[i], '='))
			exp[i] = ft_joinvar(exp[i]);
		i++;
	}
}

void	ft_replace_var(char **exp, char *var_name, char *var)
{
	int	i;

	i = 0;
	while(exp[i])
	{
		if (ft_strcmp(var_name, var) == 0)
		{
			free(exp[i]);
			exp[i] = var;	
		}
		i++;
	}
}

void	ft_update_var(char **exp, char **env ,char *var)
{
	int		i;
	char	*aux;
	char	*var_aux;

	i = 0;
	if (ft_strchr(var, '=')) 
	{
		var_aux = ft_substr(var, 0, ft_strlen(var) - ft_strlen(ft_strchr(var, '=')));
		while(env[i])
		{
			aux = ft_substr(env[i], 0, ft_strlen(env[i]) - ft_strlen(ft_strchr(env[i], '=')));
			if (ft_strcmp(aux,var_aux) == 0)
				env[i] = var;
			free(aux);
			i++;
		}
		ft_replace_var(exp, var_aux, var);
		free(var_aux);
	}
}

int	ft_is_sorted(char **str)
{
	int i;

	i = 0;
	while (str[i + 1])
	{
		if (ft_strcmp(str[i], str[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}


char	**ft_sort_export(char **str)
{
	char	*aux;
	int		i;
	
	while (!ft_is_sorted(str))
	{
		i = 0;
		while (str[i + 1])
		{
			if (ft_strcmp(str[i], str[i + 1]) > 0)
			{
				aux = str[i];
				str[i] = str[i + 1];
				str[i + 1] = aux;
			}
			i++;
		}
	}
	return (str);
}