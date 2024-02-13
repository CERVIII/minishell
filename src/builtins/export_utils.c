/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:01:49 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/02/13 16:48:40 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_join_export(char **exp)
{
	char	*var_name;
	char	*join;
	char	*join_2;
	char	*aux;
	int		i;

	i = -1;
	while (exp[++i])
	{
		if (ft_strchr(exp[i], '='))
		{
			var_name = ft_substr(exp[i], 0, ft_strlen(exp[i]) - ft_strlen(ft_strchr(exp[i], '=')));
			aux = ft_strjoin(var_name, "=\"");
			join = ft_strjoin(aux, ft_strchr(exp[i], '=') + 1);
			join_2 = ft_strjoin(join, "\"");
			free(exp[i]);
			exp[i] = join_2;
			free(var_name);
			free(aux);
			free(join);
		}
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