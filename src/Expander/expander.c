/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:47:51 by pcervill          #+#    #+#             */
/*   Updated: 2024/03/05 15:11:12 by pcervill         ###   ########.fr       */
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

/* char	*detect_dollar_sign(char *str, char **env)
{
	int		i;
	int		j;
	char	*new_str;
	char	*tmp;

	tmp = NULL;
	i = 0;
	while (str[i])
	{
		if (tmp)
		{
			printf("ENTTRAAA\n");
			free(tmp);
		}
		new_str = ft_calloc((ft_strlen(str) + 1), sizeof(char));
		if (str[i] == '$' && str[i + 1] == '?')
		{
			new_str = ft_itoa(g_error);
			tmp = ft_strjoin(tmp, new_str);
			free(new_str);
			i += 2;
		}
		else if (str[i] == '$'
			&& (!str[i + 1] || str[i + 1] == ' ' || str[i + 1] == '\"'))
		{
			tmp = ft_strdup("$");
			i++;
		}
		else if (str[i] == '$' && str[i + 1] != '\'' && str[i + 1] != '\"'
			&& str[i + 1] != '\0')
		{
			new_str = check_env(str, env, &i);
			tmp = ft_strjoin(tmp, new_str);
		}
		else
		{
			if (str[i] != '$')
			{
				j = 0;
				while (str[i] != '\0' && str[i] != '$')
					new_str[j++] = str[i++];
				tmp = ft_strjoin(tmp, new_str);
				free(new_str);
			}
			else
				i++;
		}
	}
	return (tmp);
} */

char	*detect_dollar_sign(char *str, char **env)
{
	int		i;
	char	*tmp;
	char	*new_str;

	tmp = (char *)ft_calloc(1, sizeof(char));
	i = 0;
	while (str[i])
	{
		new_str = ft_calloc((ft_strlen(str) + 1), sizeof(char));
		if (str[i] == '$' )
			new_str = check_dolar(str, env, &i);
		else
			new_str = ft_memcpy(new_str, &str[i++], 1);
		free(tmp);
		tmp = ft_strjoin(tmp, new_str);
		free(new_str);
	}
	return (tmp);
}

char	**expansor(char **str, t_tools *tools)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		if (dollar_sign(str[i]) != 0 && quotes_dollar(str[i]))
		{
			tmp = detect_dollar_sign(str[i], tools->env);
			free(str[i]);
			str[i] = tmp;
		}
		str[i] = delete_quotes(str[i]);
		i++;
	}
	return (str);
}

char	*expansor_str(char *str, t_tools *tools)
{
	int		i;
	char	*tmp;

	i = 0;
	if (str && dollar_sign(str) != 0 && quotes_dollar(str))
	{
		tmp = detect_dollar_sign(str, tools->env);
		free(str);
		str = tmp;
	}
	str = delete_quotes(str);
	return (str);
}

t_simple_cmds	*check_expander(t_tools *tools, t_simple_cmds *cmd)
{
	t_token	*tmp;
	int		i;

	i = 0;
	while (cmd)
	{
		cmd->str = expansor(cmd->str, tools);
		tmp = cmd->redirections;
		while (cmd->redirections)
		{
			if (cmd->redirections->type != HERE_DOC)
				cmd->redirections->token
					= expansor_str(cmd->redirections->token, tools);
			cmd->redirections = cmd->redirections->next;
		}
		cmd->redirections = tmp;
		cmd->str = empty_str(cmd->str);
		cmd = cmd->next;
	}
	return (cmd);
}
