/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:46:30 by pcervill          #+#    #+#             */
/*   Updated: 2024/01/18 15:00:06 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	create_token(t_tools *tools, t_token **token)
{
	int		i;
	char	**input;
	t_token	*new;

	input = NULL;
	input = ft_split_cmd(tools->arg, ' ');
	i = 0;
	while (input[i])
	{
		new = NULL;
		new = ft_token_new(input[i]);
		ft_add_token_last(token, new);
		free(input[i]);
		i++;
	}
	free(input);
	printf("Nº tokens: %d\n", i);
	return ;
}

int	lexer(t_tools *tools)
{
	char	*tmp;

	tmp = ft_strtrim(tools->arg, " \t\n\r");
	free(tools->arg);
	tools->arg = tmp;
	tools->lexer = NULL;
	create_token(tools, &tools->lexer);
	return (0);
}
