/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:46:30 by pcervill          #+#    #+#             */
/*   Updated: 2024/01/15 16:37:21 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	create_token(t_tools *tools, t_token **token)
{
	int		i;
	char	**input;
	t_token	*new;

	input = NULL;
	input = ft_split_cmd(tools->arg, ' ');
//	input = ft_split(tools->arg, ' ');
	i = 0;
	while (input[i])
	{
		new = NULL;
		new = ft_token_new(input[i]);
		ft_add_token_last(token, new);
		free(input[i]);
		i++;
	}
	printf("Nº tokens: %d\n", i);
	return ;
}

int	lexer(char *input, t_tools *tools)
{
	tools->lexer = NULL;
	tools->arg = ft_strtrim(input, " \t\n\r");
	create_token(tools, &tools->lexer);
	return (0);
}
