/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:40:28 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/04/11 12:22:53 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*add_lvl(int lvl)
{
	char	*nb_char;
	char	*str;

	nb_char = ft_itoa(lvl);
	str = ft_strjoin("SHLVL=", nb_char);
	free(nb_char);
	return (str);
}

int	get_index_lvl(char *str)
{
	char	*var_name;

	var_name = ft_substr(str, 0, ft_strlen(str)
			- (ft_strlen(ft_strchr(str, '=') + 1)));
	if (ft_strcmp(var_name, "SHLVL=") == 0)
		return (free(var_name), 0);
	free(var_name);
	return (1);
}

int	get_lvl(char *str)
{
	int	lvl;

	str = ft_strtrim(str, "SHLVL=");
	lvl = ft_atoi(str);
	lvl++;
	free(str);
	return (lvl);
}

void	increment_shlvl(char **env)
{
	int		i;
	int		new_lvl;

	i = 0;
	while (env[i])
	{
		if (get_index_lvl(env[i]) == 0)
			break ;
		i++;
	}
	new_lvl = get_lvl(env[i]);
	free(env[i]);
	env[i] = add_lvl(new_lvl);
}
