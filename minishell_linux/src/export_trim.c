/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_trim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:20:34 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/04/24 11:21:33 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_check_vars(char *var, t_tools *tools)
{
	int	i;

	i = 0;
	if (!check_if_nb(var))
		return (ft_error_export(var, tools));
	else if (var[0] == '=')
		return (ft_error_export(var, tools));
	while (var[i])
	{
		if (!ft_isalpha(var[i]) && var[i] != '_')
			return (ft_error_export(var, tools));
		i++;
	}
	return (0);
}

char	*ft_joinvar(char *str)
{
	char	*var_name;
	char	*join;
	char	*join_2;
	char	*aux;
	char	*aux2;

	var_name = ft_substr(str, 0,
			ft_strlen(str) - ft_strlen(ft_strchr(str, '=')));
	aux = ft_strjoin(var_name, "=\"");
	aux2 = ft_trim_quotes(ft_strchr(str, '=') + 1);
	join = ft_strjoin(aux, aux2);
	join_2 = ft_strjoin(join, "\"");
	free(str);
	str = join_2;
	free(var_name);
	free(aux);
	free(aux2);
	free(join);
	return (str);
}

char	*ft_trim_quotes(char *str)
{
	char	*res;

	res = ft_strtrim(str, "\"");
	return (res);
}

int	ft_cmpvar(char **export, char *var)
{
	char	*var_name;
	char	*exp_name;
	int		i;

	i = -1;
	while (export[++i])
	{
		var_name = ft_substr(var, 0, ft_strlen(var)
				- ft_strlen(ft_strchr(var, '=')));
		if (ft_strchr(export[i], '='))
		{
			exp_name = ft_substr(export[i], 0, ft_strlen(export[i])
					- ft_strlen(ft_strchr(export[i], '=')));
			if (!ft_strcmp(var_name, exp_name))
				return (free(exp_name), free(var_name), 1);
			free(exp_name);
		}
		else
		{
			if (!ft_strcmp(var_name, export[i]))
				return (free(var_name), 1);
		}
		free(var_name);
	}
	return (0);
}
