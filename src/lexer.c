/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:17:13 by pcervill          #+#    #+#             */
/*   Updated: 2023/11/22 13:29:23 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	create_token(char *input, t_token **token)
{
	int		i;
	int		j;
	int		k;
	char	*tokens;
	t_token	*tmp;

	i = 0;
	while (input[i])
	{
		if ((input[i] == '>' && input[i + 1] == '>')
			|| (input[i] == '<' && input[i + 1] == '<'))
		{
			tokens = (char *)ft_calloc(3, sizeof(char));
			tokens[0] = input[i++];
			tokens[1] = input[i++];
		}
		else if (input[i] == '|' || input[i] == '<' || input[i] == '>')
		{
			tokens = (char *)ft_calloc(2, sizeof(char));
			tokens[0] = input[i++];
		}
		else if (input[i] != '|' && input[i] != '<' && input[i] != '>')
		{
			j = i;
			while (input[j] && input[j] != '|'
				&& input[j] != '<' && input[j] != '>')
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
	return ;
}

void	ft_strlen_token(char *input)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input[i])
	{
		if ((input[i] == '>' && input[i + 1] == '>')
			|| (input[i] == '<' && input[i + 1] == '<'))
		{
			count++;
			i += 1;
		}
		else if (input[i] == '|' || input[i] == '<' || input[i] == '>')
			count++;
		else if ((input[i] != '|' && input[i] != '<' && input[i] != '>')
			&& (input[i + 1] == '|' || input[i + 1] == '<'
				|| input[i + 1] == '>' || !input[i + 1]))
			count++;
		i++;
	}
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
