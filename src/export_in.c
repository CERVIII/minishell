/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:33:36 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/01/19 17:27:50 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
//*: Revisar que no haya variables con valores incorrectos
//*: Revisar si la variable existe o no
//TODO: Revisar si tiene valor o no
	//TODO: Si existe y no tiene valor, se reemplaza
	//TODO: Si existe y las dos tienen valor, se reemplaza
	//TODO: Si la nueva no tiene valor y la antigua sí, no se reemplaza
//TODO: Reordenar funciones.

/* char	*join_chars(char *var)
{
	char	*aux;
	char	*aux_value;
	char	*temp;
	aux = ft_strchr(var, "=");
	temp = ft_strjoin(aux, "=");
	
}

int	ft_export_error(char *var)
{
	ft_putendl_fd("export: '", STDOUT_FILENO);
	ft_putendl_fd(var, STDOUT_FILENO);
	ft_putendl_fd("' Not a valid identifier ", STDOUT_FILENO);
	return (EXIT_FAILURE);
}

void	ft_update_var(char **exp, char **env ,char *var)
{
	int	i;

	i = 0;
	if (ft_strchr(var, '='))
	{
		while(env[i])
		{
			if (ft_strcmp(env[i], ft_strchr(var, '=')) == 0)
			{
				free(env[i]);
				env[i] = var;
				free(exp[i]);
				exp[i] = var;
			}
			else
			{
				free(exp[i]);
				exp[i] = var;
			}
			i++;
		}
	}	
}

int	ft_check_if_exists(char **exp, char *var)
{
	int		i;
	char	*aux;
	char	*var_aux;

	i = 0;
	while(exp[i])
	{
		if (ft_strchr(exp[i], '='))
		{
			aux = ft_strchr(exp[i], '=');
			var_aux = ft_strchr(exp[i], '=');			
			if (ft_strcmp(aux, var_aux) == 0)
				return (1);
		}
		else
			if (ft_strcmp(exp[i], var) == 0)
				return (1);
		i++;
	}
	return (0);
}

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



char	**ft_check_exports(t_simple_cmds *simple_cmds, char *var, char **exp, char **env)
{
	char	**new_env;
	
	if (!ft_check_vars(var))
		ft_export_error(var);
	else
		if (ft_check_if_exists(exp, var))
			ft_update_var(exp, env, var);
		else
			new_env = ft_add_var(exp, var);
	return (new_env);
}
*/

void	ft_join_export(char **exp)
{
	char	*var_name;
	char	*var_value;
	char	*var_join;
	char	*aux_join;
	int		i;

	i = 0;
	while (exp[i])
	{
		var_name = ft_substr(exp[i], 0, (ft_strlen(exp[i]) - ft_strlen(ft_strchr(exp[i], '='))));
		var_value = ft_strchr(exp[i], '=');
		var_value++;
		aux_join = ft_strjoin(var_name, "=\"");
		var_join = aux_join;
		free(aux_join);
		aux_join = ft_strjoin(var_join, var_value);
		var_join = aux_join;
		free(aux_join);
		aux_join = ft_strjoin(var_join, "\"");
		var_join = aux_join;
		free(aux_join);
		exp[i] = ft_strdup(var_join);
		printf("EXP: %s", exp[i]);
		free(var_name);
		i++;
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

void	ft_print_export(char **copy)
{
	int		i;
	char	**sorted_export;
	// char	**joined_export;

	i = 0;
	ft_join_export(copy);
	sorted_export = ft_sort_export(copy);
	while (sorted_export[i])
	{
		printf("declare -x %s\n", copy[i]);
		i++;
	}
	// while (sorted_export[j])
	// 	free(sorted_export[j++]);
} 
char	**ft_update_export(char **exp, char **new_exp, char *var)
{
	int		i;

	i = 0;
	while (exp[i])
	{
		new_exp[i] = exp[i];
		i++;
	}
	new_exp[i] = var;
	return (new_exp);
}


char	**ft_add_var(char **env, char *var)
{
	char	**new_env;
	int		i;

	i = 0;
	while(env[i])
		i++;
	new_env = ft_calloc(i + 2, sizeof(char *));
	if (!new_env)
		return (NULL);
	ft_update_export(env, new_env, var);
	return (new_env);
}

int	ft_check_if_exists(char **export, char *var)
{
	char	*var_name;
	int		i;

	i = 0;
	if (ft_strchr(var, '='))
	{
		var_name = ft_substr(var, 0, ft_strlen(var) - ft_strlen(ft_strchr(var, '=')));
		while (export[i])
		{
			if (ft_strncmp(var_name, export[i], ft_strlen(var_name)) == 0)
				return (1);							
			i++;
		}
		free(var_name);
	}
	else
		while (export[i])
		{
			if (ft_strncmp(var, export[i], ft_strlen(var)) == 0)
				return (1);
			i++;
		}
	return (0);
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


/*
	TODO: Gestionar los aa=bb para que se guarde como aa="bb"
*/
int	ft_export(t_tools *tools, t_simple_cmds *simple_cmds)
{
	simple_cmds = malloc(sizeof(t_simple_cmds)); 
	simple_cmds->str = ft_calloc(3, sizeof(char *));
	simple_cmds->str[0] = ft_strdup("USER=pepe");
	simple_cmds->str[1] = ft_strdup("bb");
	simple_cmds->str[2] = ft_strdup("Za1");
	// simple_cmds->str[2] = ""
	// if (!simple_cmds->str[1] || simple_cmds->str[0][0])
	// 	ft_print_export(env_copy);
	// else
	// {
	int i = 0;
		while (simple_cmds->str[i])
		{
			if (ft_check_vars(simple_cmds->str[i]))
			{				
				if(ft_check_if_exists(tools->export, simple_cmds->str[i]))
					ft_update_var(tools->export, tools->env, simple_cmds->str[i]);
				else
				{
					if (ft_strchr(simple_cmds->str[i], '='))
						tools->env = ft_add_var(tools->env, simple_cmds->str[i]);
					tools->export = ft_add_var(tools->export, simple_cmds->str[i]);
				}
			}
			i++;
		}
	// }
	ft_print_export(tools->export);
	return (1);
}
