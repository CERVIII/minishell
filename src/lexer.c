/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:17:13 by pcervill          #+#    #+#             */
/*   Updated: 2024/01/08 13:28:03 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	create_token(char *str, t_token **token)
{
	int		i;
	int		j;
	int		k;
	char	*tokens;
	char	*input;
	t_token	*tmp;

	i = 0;
	input = ft_strtrim(str, " \t\n\r");
	while (input[i])
	{
		if (input[i] == 32)
			i++;
		if ((input[i] == '>' && input[i + 1] == '>')
			|| (input[i] == '<' && input[i + 1] == '<'))
		{
			tokens = (char *)ft_calloc(3, sizeof(char));
			tokens[0] = input[i++];
			tokens[1] = input[i++];
		}
		else if (input[i] == '|' || input[i] == '<' || input[i] == '>'
			|| input[i] == '\'' || input[i] == '\"')
		{
			tokens = (char *)ft_calloc(2, sizeof(char));
			tokens[0] = input[i++];
		}
		else if (input[i] != '|' && input[i] != '<' && input[i] != '>')
		{
			j = i;
			while (input[j] && input[j] != '|'
				&& input[j] != '<' && input[j] != '>' && input[j] != '\''
				&& input[j] != '\"')
				j++;
			tokens = ft_calloc(((j - i) + 1), sizeof(char));
			k = 0;
			while (i < j)
				tokens[k++] = input[i++];
		}
		if (tokens != NULL)
		{
			tmp = NULL;
			tmp = ft_token_new(tokens);
			ft_add_token_last(token, tmp);
			free(tokens);
		}
	}
	free(input);
	return ;
}

void	ft_strlen_token(char *str)
{
	int		i;
	int		count;
	char	*input;

	i = 0;
	count = 0;
	input = ft_strtrim(str, " \t\n\r");
	while (input[i])
	{
		if ((input[i] == '>' && input[i + 1] == '>')
			|| (input[i] == '<' && input[i + 1] == '<'))
		{
			count++;
			i += 1;
		}
		else if ((input[i] == '|' || input[i] == '<' || input[i] == '>'
				|| input[i] == '\'' || input[i] == '\"'))
			count++;
		else if ((input[i + 1] == '|' || input[i + 1] == '<'
				|| input[i + 1] == '>' || input[i + 1] == '\"'
				|| input [i + 1] == '\'' ||!input[i + 1]))
			count++;
		i++;
	}
	free(input);
	// Borrar printf de count tokens↓
	printf("Tokens: %d\n", count);
	return ;
}

int	lexer(char *input, t_token **token)
{
	ft_strlen_token(input);
	create_token(input, token);
	return (0);
}
