/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:33:36 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/01/12 17:09:26 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**ft_save_exports()
{
	
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
	char *aux;
	char **copy;
	int i;
	
	copy = dup_matrix(str);	
	while (!ft_is_sorted(copy))
	{
		i = 0;
		while (copy[i + 1])
		{
			if (ft_strcmp(copy[i], copy[i + 1]) > 0)
			{
				aux = copy[i];
				copy[i] = copy[i + 1];
				copy[i + 1] = aux;
			}
			i++;
		}
	}
	return (copy);
}

void	ft_print_export(t_tools *tools)
{
	int i;
	int j;
	char **sorted_export;

	i = 0;
	j = 0;
	sorted_export = ft_sort_export(&tools->env[i]);
	while (sorted_export[i])
	{
		printf("declare -x %s\n", sorted_export[i]);
		i++;
	}
	while (sorted_export[j])
		free(sorted_export[j++]);
}

int	ft_export(t_tools *tools, t_simple_cmds *simple_cmds)
{
	(void)simple_cmds;
	simple_cmds->str[0] = "aa";
	simple_cmds->str[1] = "bb";
	// simple_cmds->str[2] = ""
	if (!simple_cmds->str[1] || simple_cmds->str[1][0])
		ft_print_export(tools);
	else
	{
		ft_save_exports();
	}
	return (1);
}