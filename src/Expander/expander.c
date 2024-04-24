/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:47:51 by pcervill          #+#    #+#             */
/*   Updated: 2024/04/23 16:39:53 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*check_env(char *str, char **env, int *i)
{
	char	*var;
	char	*tmp;
	int		j;
	int		k;

	*i += 1;
	var = ft_calloc(ft_strlenmod(str, *i) + 2, sizeof(char));
	j = 0;
	while (str[*i] && str[*i] != ' ' && str[*i] != '\''
		&& str[*i] != '"' && str[*i] != '$')
		var[j++] = str[(*i)++];
	var[j++] = '=';
	tmp = NULL;
	k = 0;
	while (env[k])
	{
		if (!ft_strncmp(var, env[k], (ft_strlen(var))))
		{
			tmp = ft_substr(env[k], j, ft_strlenmod(env[k], j));
			break ;
		}
		k++;
	}
	free(var);
	return (tmp);
}

char	*detect_dollar_sign(char *str, char **env, int g_error)
{
	int		i;
	int		flag;
	char	*tmp;
	char	*new_str;
	char	*cpy;

	tmp = ft_strdup("");
	i = 0;
	flag = 0;
	while (str[i])
	{
		flag = cmp_quotes(str[i], flag);
		if (str[i] == '$' && flag >= 0)
			new_str = check_dolar(str, env, &i, g_error);
		else
		{
			new_str = ft_calloc(2, sizeof(char));
			new_str[0] = str[i++];
		}
		cpy = ft_strdup(tmp);
		free(tmp);
		tmp = ft_strjoin(cpy, new_str);
		(free(cpy), free(new_str));
	}
	return (tmp);
}

char	**expander(char **str, t_tools *tools)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		if (dollar_sign(str[i]) != 0)
		{
			tmp = detect_dollar_sign(str[i], tools->env, tools->g_error);
			free(str[i]);
			str[i] = tmp;
		}
		str[i] = delete_quotes(str[i], 0, 0);
		i++;
	}
	return (str);
}

char	*expander_str(char *str, t_tools *tools)
{
	char	*tmp;
	char	*aux;

	if (str && dollar_sign(str) != 0)
	{
		tmp = detect_dollar_sign(str, tools->env, tools->g_error);
		free(str);
		str = tmp;
	}
	aux = delete_quotes(str, 0, 0);
	return (aux);
}

t_simple_cmds	*check_expander(t_tools *tools, t_simple_cmds *cmd)
{
	t_token	*tmp;

	while (cmd)
	{
		cmd->str = expander(cmd->str, tools);
		tmp = cmd->redirections;
		while (cmd->redirections)
		{
			if (cmd->redirections->type != HERE_DOC)
				cmd->redirections->token
					= expander_str(cmd->redirections->token, tools);
			cmd->redirections = cmd->redirections->next;
		}
		cmd->redirections = tmp;
		cmd->str = empty_str(cmd->str);
		cmd = cmd->next;
	}
	return (cmd);
}
