/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:46:18 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/02/14 12:57:18 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_print_export(char **copy)
{
	int		i;
	char	**sorted_export;

	i = 0;
	ft_join_export(copy);
	// printf("AAAAA\n");
	// printf("COPY: %s\n",copy[0]);
	sorted_export = ft_sort_export(copy);
	// printf("SE: %s\n",sorted_export[0]);	
	while (copy[i])
	{
		printf("declare -x %s\n", copy[i]);
		i++;
	}
	printf("FIN\n");
} 
char	**ft_update_export(char **exp, char **new_exp, char *var)
{
	int		i;

	i = 0;
	while (exp[i])
	{
		new_exp[i] = ft_strdup(exp[i]);
		i++;
	}
	new_exp[i] = ft_strdup(var);
	return (new_exp);
}