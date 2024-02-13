/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:01:49 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/02/13 19:07:24 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_join_export(char **exp)
{
	int	i;
	
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
	int		i;
	char	*aux;
	i = 0;
	printf("VAR_NAME: %s\n", var_name);
	printf("VAR: %s\n", var);
	while(exp[i])
	{
		//TODO:FALLA AQUI
		aux = ft_substr(exp[i], 0, ft_strlen(exp[i]) - ft_strlen(ft_strchr(exp[i], '=')));
		// if (ft_strcmp(aux, var_name) == 0)
		// {
		// 	free(exp[i]);
		// 	exp[i] = var;
		// 	printf("exp[i]: %s\n", exp[i]);
		// }
		// free(aux);
		i++;
	}
}

void	ft_update_var(char **exp, char **env ,char *var)
{
	int		i;
	char	*aux;
	char	*var_aux;
	int j = 0;
	while(exp[j])
		j++;

	i = 0;
	if (ft_strchr(var, '=')) 
	{
		var_aux = ft_substr(var, 0, ft_strlen(var) - ft_strlen(ft_strchr(var, '=')));
		while(env[i])
		{
			aux = ft_substr(env[i], 0, ft_strlen(env[i]) - ft_strlen(ft_strchr(env[i], '=')));
			if (ft_strcmp(aux,var_aux) == 0)
			{
				free(env[i]);
				env[i] = ft_strdup(var);
			}
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
	printf("SORT_EXPORT: %s\n", str[0]);
	return (str);
}