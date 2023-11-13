/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:26:45 by pcervill          #+#    #+#             */
/*   Updated: 2023/11/13 15:02:37 by pcervill         ###   ########.fr       */
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


int	lexer(char *input, t_tokenList *tokenList)
{
	int	i;
	int	j;
	int	token_index;

	i = 0;
	tokenList->count = 0;
	while (input[i])
	{
		if ((input[i] == '>' && input[i + 1] == '>')
			|| (input[i] == '<' && input[i + 1] == '<'))
		{
			tokenList->count++;
			i += 1;
		}
		else if (input[i] == '|' || input[i] == '<' || input[i] == '>')
			tokenList->count++;
		i++;
	}
	tokenList->tokens = malloc(tokenList->count * sizeof(char *));
	tokenList->content = malloc((tokenList->count + 1) * sizeof(char *));
	i = 0;
	token_index = 0;
	while (input[i])
	{
		j = i;
		if ((input[i] == '>' && input[i + 1] == '>')
			|| (input[i] == '<' && input[i + 1] == '<'))
		{
			tokenList->tokens[token_index] = (char *)malloc(3 * sizeof(char));
			tokenList->tokens[token_index][0] = input[i];
			tokenList->tokens[token_index][1] = input[i + 1];
			tokenList->tokens[token_index][2] = '\0';
			token_index++;
			i += 1;
		}
		else if (input[i] == '|' || input[i] == '<' || input[i] == '>')
		{
			tokenList->tokens[token_index] = (char *)malloc(2 * sizeof(char));
			tokenList->tokens[token_index][0] = input[i];
			tokenList->tokens[token_index][1] = '\0';
			token_index++;
		}
		else if (input[i] != '|' && input[i] != '<' && input[i] != '>')
		{
			printf("hola: %c\nindex: %d\ni: %d\n", input[i], token_index, i);
			tokenList->content[token_index][j] = input[i];
		}
		i++;
	}
	return (0);
}
