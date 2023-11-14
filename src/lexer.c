/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:26:45 by pcervill          #+#    #+#             */
/*   Updated: 2023/11/14 15:06:20 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* int	lexer(char *input, t_token *token)
{
	int	i;
	int	tokens;

	i = 0;
	tokens = 0;
	while (input[i])
	{
		if (input[i] == '|' || input[i] == '<' || input[i] == '>')
			tokens++;
		i++;
	}
	token->content = ft_split(input, '|');
	printf("Tokens: %d\n", tokens);
	i = 0;
	while (token->content[i])
	{
		token->content[i] = ft_strtrim(token->content[i], " ");
		printf("%s\n", token->content[i++]);
	}
	return (0);
}
 */

void	create_token(char *input, t_token *token)
{
	int	i;
	int	token_index;

	token->tokens = ft_calloc(token->count, sizeof(char *));
	i = 0;
	token_index = 0;
	while (input[i])
	{
		if ((input[i] == '>' && input[i + 1] == '>')
			|| (input[i] == '<' && input[i + 1] == '<'))
		{
			token->tokens[token_index] = (char *)malloc(3 * sizeof(char));
			token->tokens[token_index][0] = input[i];
			token->tokens[token_index][1] = input[i + 1];
			token_index++;
			i += 1;
		}
		else if (input[i] == '|' || input[i] == '<' || input[i] == '>')
		{
			token->tokens[token_index] = (char *)malloc(2 * sizeof(char));
			token->tokens[token_index][0] = input[i];
			token_index++;
		}
		i++;
	}
}

void	ft_strlen_token(char *input, t_token *token)
{
	int		i;
	int		j;
	int		k;

	token->cpyinput = ft_calloc(sizeof(char), ft_strlen(input) - token->count);
	token->len = ft_calloc((token->count + 1), sizeof(int));
	j = 0;
	i = 0;
	k = 0;
	while (input[i])
	{
		if (input[i] == '|' || input[i] == '<' || input[i] == '>')
		{
			j++;
			i++;
		}
		if (input[i] != '|' || input[i] != '<' || input[i] != '>')
		{
			token->len[j]++;
			token->cpyinput[k] = input[i];
		}
		k++;
		i++;
	}
	return ;
}

int	lexer(char *input, t_token *token)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	token->count = 0;
	while (input[i])
	{
		if ((input[i] == '>' && input[i + 1] == '>')
			|| (input[i] == '<' && input[i + 1] == '<'))
		{
			token->count++;
			i += 1;
		}
		else if (input[i] == '|' || input[i] == '<' || input[i] == '>')
			token->count++;
		i++;
	}
	ft_strlen_token(input, token);
	token->content = malloc((token->count + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (i <= (token->count))
	{
		k = 0;
		token->content[i] = ft_calloc((token->len[i] - 1), sizeof(char *));
		while (k < token->len[i])
		{
			token->content[i][k] = token->cpyinput[j];
			j++;
			k++;
		}
		i++;
	}
	create_token(input, token);
	return (0);
}
