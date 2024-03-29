/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_trim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:20:34 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/03/27 12:15:25 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_check_vars(char *var)
{
	int	i;

	i = 0;
	if (!check_if_nb(var))
		return (ft_error_export(var));
	else if (var[0] == '=')
		return (ft_error_export(var));
	while (var[i])
	{
		if (!ft_isalpha(var[i]) && var[i] != '_')
			return (ft_error_export(var));
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

