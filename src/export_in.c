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

char	**ft_update_export(char **exp, char **new_exp, char *var)
{
	int	i;

	i = 0;
	while (exp[i])
	{
		new_exp[i] = (exp[i]);
		i++;
	}
	i--;
	while (new_exp[i])
	{
		i++;
		new_exp[i] = ft_strdup(var);
		i++;
	}
	return (new_exp);
}

char	**ft_add_var(char **exp, char *var)
{
	char	**new_exp;
	int		i;

	i = 0;
	while(exp[i])
		i++;
	new_exp = ft_calloc(i + 2, sizeof(char *));
	if (!new_exp)
		return (NULL);
	ft_update_export(exp, new_exp, var);
	return (new_exp);
}

int	check_if_nb(char *str)
{
	int	i;	

	i = 0;
	while (str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		return (0);
	return (1);
}

int	ft_check_vars(char *cmds)
{
	int	i;

	i = 0;
	if (!check_if_nb(cmds))
		return (0);
	else if (cmds[0] == '=')
		return (0);
	return (1);
}

char	**ft_save_exports(t_simple_cmds *simple_cmds, char *var, char **exp)
{
	(void) simple_cmds;
	if (!ft_check_vars(var))
		ft_err("Not a valid identifier", EXIT_FAILURE);
	else
		exp = ft_add_var(exp, var);
	return (exp);
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
	int i;
	
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

void	ft_print_export(char **copy)
{
	int i;
	int j;
	char **sorted_export;

	i = 0;
	j = 0;
	sorted_export = ft_sort_export(copy);
	while (sorted_export[i])
	{
		printf("declare -x %s\n", sorted_export[i]);
		i++;
	}
	while (sorted_export[j])
		free(sorted_export[j++]);
}

/*
	TODO: Verificar que existan las variables
	TODO: Gestionar los aa=bb para que se guarde como aa="bb"
*/
int	ft_export(t_tools *tools, t_simple_cmds *simple_cmds)
{
	//(void)simple_cmds;
	char	**copy;

	copy = dup_matrix(tools->env);	
	simple_cmds = malloc(sizeof(t_simple_cmds)); 
	simple_cmds->str = malloc(3 * sizeof(char *));
	simple_cmds->str[0] = ft_strdup("aa==b");
	simple_cmds->str[1] = ft_strdup("bb");
	simple_cmds->str[2] = ft_strdup("Za1");
	// simple_cmds->str[2] = ""
	// if (!simple_cmds->str[1] || simple_cmds->str[0][0])
		// ft_print_export(copy);
	// else
	// {
	int i = 0;
		while (simple_cmds->str[i])
		{
			copy = ft_save_exports(simple_cmds, simple_cmds->str[i], copy);
			i++;
		}
	ft_print_export(copy);
	free(simple_cmds->str[0]);
	free(simple_cmds->str[1]);
	free(simple_cmds->str[2]);
	free(simple_cmds);
	// int i = 0;
	// while(copy[i])
	// {
	// 	free(copy[i]);
	// 	i++;
	// }
	return (1);
}