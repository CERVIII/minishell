/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:47:51 by pcervill          #+#    #+#             */
/*   Updated: 2024/02/26 18:30:23 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_strlenmod(char *str, int start)
{
	int	i;

	i = 0;
	while (str[start] && str[start] != '\'' && str[start] != '\"')
	{
		i++;
		start++;
	}
	printf("i: %d\n", i);
	return (i);
}

char	*check_env(char *str, char **env, int *i)
{
	char	*var;
	char	*tmp;
	int		j;
	int		k;
	int		l;

	printf("%sENTRA EN CHECK_ENV%s\n", BLUE, NORMAL);
	*i += 1;
	var = ft_calloc(ft_strlenmod(str, *i) + 2, sizeof(char));
	j = 0;
	while (str[*i] && str[*i] != ' ' && str[*i] != '\'' && str[*i] != '"' && str[*i] != '$')
		var[j++] = str[(*i)++];
	var[j++] = '=';
	printf("var: %s\n", var);
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
	printf("new_stfgdfgfr ($): %s len: %zu\n", tmp, ft_strlen(tmp));
	printf("i al salir: %d\n", *i);
	return (tmp);
}

char	*detect_dollar_sign(char *str, char **env)
{
	int		i;
	int		j;
	char	*new_str;
	char	*tmp;

	printf("%sENTRA EN DETECT_DOllAR\n%s", YELLOW, NORMAL);
	tmp = ft_strdup("");
	i = 0;
	while (str[i])
	{
		new_str = ft_calloc((ft_strlen(str) + 1), sizeof(char));
		//printf("str[%d]: %c\n", i, str[i]);
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
			tmp = ft_strjoin(tmp, new_str);
			printf("LLEGA\n");
			free(new_str);
		}
		else
		{
			if (str[i] != '\"')
			{
				j = 0;
				while (str[i] != '\0' && str[i] != '$' && str[i] != '\"')
				{
					printf("str[%d]: %c\n", i, str[i]);
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


/* char	*detect_dollar_sign(char *str, char **env)
{
	int		i;
	char	*new_str;
	char	*tmp;

	printf("%sENTRA EN DETECT_DOllAR\n%s", YELLOW, NORMAL);
	new_str = ft_strdup("");
	tmp = NULL;
	i = 0;
	while (str[i])
	{
		printf("str[%d]: %c\n", i, str[i]);
 		if (str[i] == '$' && str[i + 1] == '?')
		{
			new_str = ft_itoa(127);		// cambiar por señal de error
			printf("new_str ($?): %s\n", new_str);
			tmp = ft_strjoin(tmp, new_str);
			free(new_str);
			i += 2;
		}
		else if (str[i] == '$' && str[i + 1] == '_')
		{
			new_str = ft_strdup("env");
			tmp = ft_strjoin(tmp, new_str);
			i += 2;
		}
		else if (str[i] == '$' && (str[i + 1] != '"'
				|| str[i + 1] != '\'') && str[i + 1] != '\0')
		{
			new_str = check_env(str, env, &i);
			printf("new_str ($): %s\n", new_str);
			tmp = ft_strjoin(tmp, new_str);
			printf("tmp ($): %s\n", tmp);
		}
		else
		{
			tmp = ft_strjoin(tmp, &str[i]);
			i++;
		}
	}
	return (tmp);
} */

int	cmp_dollar(char *str, int *i, char flag)
{
	*i += 1;
	while (str[*i] && str[*i] != flag)
	{
		if (str[*i] == '$')
		{
			while (str[*i + 1] != flag)
				(*i)++;
			if (flag == '\'')
				return (-1);
			return (1);
		}
		else
			(*i)++;
	}
	return (0);
}

int	quotes_dollar(char *str)
{
	int	i;
	int	double_q;
	int	single_q;

	printf("%sENTRA EN QUOTES_DOLLAR%s\n", YELLOW, NORMAL);
	i = 0;
	double_q = 0;
	single_q = 0;
	while (str[i])
	{
		if (str[i] == '\"' && single_q == 0 && double_q == 0)
		{
			double_q = cmp_dollar(str, &i, '\"');
		}
		if (str[i] == '\'' && double_q == 0)
		{
			single_q = cmp_dollar(str, &i, '\'');
		}
		if (single_q == -1)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	dollar_sign(char *str)
{
	int	i;

	printf("%sENTRA EN DOLLAR_SIGN%s\n", YELLOW, NORMAL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (i + 1);
		i++;
	}
	return (0);
}

char	**expansor(char **str, t_tools *tools)
{
	int		i;
	char	*tmp;
	t_tools	*aux;

	i = 0;
	printf("%s\n", str[0]);
	while (str[i])
	{
		if (dollar_sign(str[i]) != 0 && quotes_dollar(str[i]))
		{
			printf("%sENTRA EN EXPANSOR%s\n", GREEN, NORMAL);
			tmp = detect_dollar_sign(str[i], tools->env);
			printf("tmp: %s\n", tmp);
//			free(str[i]);
			ft_strlcpy(str[i], tmp, ft_strlen(tmp) + 1);
//			printf("str[i]: %s\n", str[i]);
		}
		i++;
	}
	printf("%d\n", i);
	tmp = str[0];
	aux = tools;
	return (str);
}

t_simple_cmds	*check_expander(t_tools *tools, t_simple_cmds *cmd)
{
	t_token	*tmp;

	cmd->str = expansor(cmd->str, tools);
//	printf("cmd->str: %s\n", cmd->str[0]);
	tmp = cmd->redirections;
	return (cmd);
}





/* char	**expansor(char **str, char **env)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		if (dollar_sign(str[i]) != 0 && quotes_dollar(str[i]))
		{
//			printf("%sENTRA EN EXPANSOR%s\n", GREEN, NORMAL);
			tmp = detect_dollar_sign(str[i], env);
			printf("tmp: %s\n", tmp);
			free(str[i]);
			ft_strlcpy(str[i], tmp, ft_strlen(tmp) + 1);
			printf("str[i]: %s\n", str[i]);
		}
		i++;
	}
	return (str);
} */

/* int	main(int argc, char **argv, char **env)
{
	char	**input;
	int		i;

	if (argc != 1 || argv[1])
		return (0);
	while (1)
	{
		i = 0;
		input = ft_split(readline(PROMPT_MSG), ' ');
		if (!input[0] || !ft_strcmp(input[0], "exit") || !ft_strcmp(input[0], ""))
		{
			printf("HASTA LUEGO\n");
			return (0) ;
		}
		input = expansor(input, env);
		printf("HOLA\n");
		while (input[i])
			printf("Nuevo input: %s\n", input[i++]);
	}
	return (0);
} */

// /System/Volumes/Data/sgoinfre/students/pcervill/minishell

/*
	TMPDIR
	ZSH
	NVM_DIR
	SSH_AUTH_SOCK
	MAIL
	PATH
*/