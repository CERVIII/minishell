/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:10:24 by pcervill          #+#    #+#             */
/*   Updated: 2024/03/06 13:50:54 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**empty_str(char **str)
{
	int	i;

	i = 0;
	if (str[0] && ft_strlen(str[0]) < 1)
	{
		while (str[i])
			i++;
		i = 0;
		while (str[i])
		{
			str[i] = str[i + 1];
			i++;
		}
	}
	return (str);
}

char	*check_dolar(char *str, char **env, int *i)
{
	char	*new_str;

	new_str = NULL;
	if (str[*i] == '$' && str[*i + 1] == '?')
	{
		new_str = ft_itoa(g_error);
		(*i) += 2;
	}
	else if (str[*i] == '$' && str[*i + 1] != '\'' && str[*i + 1] != '\0'
		&& ft_isalpha(str[*i + 2]) && str[*i + 1] != ' ')
	{
		new_str = check_env(str, env, i);
		if (!new_str)
			new_str = ft_strdup("");
	}
	else if (str[*i] == '$'
		/* && (!str[*i + 1] || str[*i + 1] == ' ' || str[*i + 1] == '\"') */)
	{
		new_str = ft_strdup("$");
		(*i)++;
	}
	return (new_str);
}
