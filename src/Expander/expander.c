/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:47:51 by pcervill          #+#    #+#             */
/*   Updated: 2024/03/04 15:06:47 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*check_env(char *str, char **env, int *i)
{
	char	*var;
	char	*tmp;
	int		j;

	*i += 1;
	var = ft_calloc(ft_strlenmod(str, *i) + 2, sizeof(char));
	j = 0;
	while (str[*i] && str[*i] != ' ' && str[*i] != '\''
		&& str[*i] != '"' && str[*i] != '$')
		var[j++] = str[(*i)++];
	var[j++] = '=';
	tmp = NULL;
	j = 0;
	while (env[j])
	{
		if (!ft_strncmp(var, env[j], (ft_strlen(var))))
			tmp = ft_strdup(ft_strchr(env[j], '=') + 1);
		j++;
	}
	free(var);
	return (tmp);
}

char	*detect_dollar_sign(char *str, char **env)
{
	int		i;
	int		j;
	char	*new_str;
	char	*tmp;

	tmp = ft_strdup("");
	i = 0;
	while (str[i])
	{
		new_str = ft_calloc((ft_strlen(str) + 1), sizeof(char));
		if (str[i] == '$' && str[i + 1] == '?')
		{
			new_str = ft_itoa(g_error);
			tmp = ft_strjoin(tmp, new_str);
			free(new_str);
			i += 2;
		}
		else if (str[i] == '$' && (!str[i + 1] || str[i + 1] == ' ' || str[i + 1] == '\"'))
		{
			tmp = ft_strjoin(tmp, "$");
			i++;
		}
		else if (str[i] == '$' && str[i + 1] != '\'' && str[i + 1] != '\"'
			&& str[i + 1] != '\0')
		{
			new_str = check_env(str, env, &i);
			if (new_str)
			{
				tmp = ft_strjoin(tmp, new_str);
				free(new_str);
			}
		}
		else
		{
			if (str[i] != '$')
			{
				j = 0;
				while (str[i] != '\0' && str[i] != '$')
				{
					new_str[j++] = str[i++];
				}
				tmp = ft_strjoin(tmp, new_str);
				free(new_str);
			}
			else
				i++;
		}
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
			str[i] = ft_strdup(tmp);
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
		str = ft_strdup(tmp);
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
char    **empty_str(char **str)
{
    int     i;
    char    **tmp;
    i = 0;
    if (ft_strlen(str[0]) < 1)
    {
        while (str[i])
            i++;
        tmp = (char **)ft_calloc(i - 1, sizeof(char *));
        i = 0;
        while (str[i])
        {
            str[i] = str[i + 1];
            i++;
        }
    }
    return (str);
}