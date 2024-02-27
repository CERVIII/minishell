/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:47:51 by pcervill          #+#    #+#             */
/*   Updated: 2024/02/27 14:57:30 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*check_env(char *str, char **env, int *i)
{
	char	*var;
	char	*tmp;
	int		j;
	int		k;
	int		l;

	printf("%s		ENTRA EN CHECK_ENV%s\n", BLUE, NORMAL);
	*i += 1;
	var = ft_calloc(ft_strlenmod(str, *i) + 2, sizeof(char));
	j = 0;
	while (str[*i] && str[*i] != ' ' && str[*i] != '\''
		&& str[*i] != '"' && str[*i] != '$')
		var[j++] = str[(*i)++];
	var[j++] = '=';
	printf("		var: %s\n", var);
	tmp = ft_calloc(1024, sizeof(char));
	j = 0;
	while (env[j])
	{
		if (!ft_strncmp(var, env[j], (ft_strlen(var))))
		{
			l = ft_strlen(var);
			k = 0;
			while (env[j][l])
				tmp[k++] = env[j][l++];
			tmp[k] = '\0';
		}
		j++;
	}
	printf("		valor variable($): %s len: %zu\n", tmp, ft_strlen(tmp));
	return (tmp);
}

char	*detect_dollar_sign(char *str, char **env)
{
	int		i;
	int		j;
	char	*new_str;
	char	*tmp;

	printf("%s	ENTRA EN DETECT_DOllAR\n%s", YELLOW, NORMAL);
	tmp = ft_strdup("");
	i = 0;
	while (str[i])
	{
		new_str = ft_calloc((ft_strlen(str) + 1), sizeof(char));
		printf("	str[%d]: %c\n", i, str[i]);
 		if (str[i] == '$' && str[i + 1] == '?')
		{
			new_str = ft_itoa(127);		// cambiar por señal de error
			tmp = ft_strjoin(tmp, new_str);
			free(new_str);
			i += 2;
		}
		else if (str[i] == '$' && str[i + 1] != '\'' && str[i + 1] != '\"'
			&& str[i + 1] != '\0')
		{
			new_str = check_env(str, env, &i);
			if (new_str)
			{
				printf("	LLEGA\n");
				tmp = ft_strjoin(tmp, new_str);
				free(new_str);
			}
		}
		else
		{
			if (str[i] != '\"' && str[i] != '$')
			{
				j = 0;
				while (str[i] != '\0' && str[i] != '$' && str[i] != '\"')
				{
					new_str[j++] = str[i++];
				}
				tmp = ft_strjoin(tmp, new_str);
				printf("	tmp: %s\n", tmp);
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
			printf("%sENTRA EN EXPANSOR%s\n", GREEN, NORMAL);
			tmp = detect_dollar_sign(str[i], tools->env);
			printf("tmp: %s\n", tmp);
			str[i] = ft_strdup(tmp);
		}
		i++;
	}
	return (str);
}

t_simple_cmds	*check_expander(t_tools *tools, t_simple_cmds *cmd)
{
	t_token	*tmp;
	int		i;

	printf("\n%sENTRA EN CHECK_EXPANDER%s\n", RED, NORMAL);
	i = 0;
	cmd->str = expansor(cmd->str, tools);
	while (cmd->str[i])
	{
		printf("cmd->str[%d]: %s\n", i, cmd->str[i]);
		i++;
	}
	tmp = cmd->redirections;
	return (cmd);
}
