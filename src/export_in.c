/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:33:36 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/01/12 15:02:53 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**ft_sort_export(char **str)
{
	char	*aux;
	char 	**copy;
	int		i;
	int		j;
	int 	k;
	
	i = 0;
	j = 0;
	k = 0;
	copy = dup_matrix(str);
	while (str[i])
	{
		i++;
		j++;
	}
	i = 0;
	while (copy[i])
	{
		while (k < (j - 1))
		{			
			if (ft_strcmp(copy[k], copy[k + 1]) > 0)
			{
				aux = copy[k];
				copy[k] = copy[k + 1];
				copy[k + 1] = aux;
			}
			k++;
		}
		i++;
	}
	return (copy);
}

void	ft_print_export(t_tools *tools)
{
	int		i;
	char	**sorted_export;

	i = 0;
	sorted_export = ft_sort_export(&tools->env[i]);
	while (sorted_export[i])
	{
		printf("declare -x %s\n", sorted_export[i]);
		i++;
	}
}

int	ft_export(t_tools *tools, t_simple_cmds *simple_cmds)
{
	(void) simple_cmds;
	// if (!simple_cmds->str[1] || simple_cmds->str[1][0])
		ft_print_export(tools);
	return (1);
}