/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:46:30 by pcervill          #+#    #+#             */
/*   Updated: 2024/01/30 14:46:00 by pcervill         ###   ########.fr       */
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
	if (!input)
		return ;
	i = 0;
	while (input[i])
	{
		new = NULL;
		new = ft_token_new(input[i], i);
		ft_add_token_last(token, new);
		free(input[i]);
		i++;
	}
	free(input);
	return ;
}

int	lexer(t_tools *tools)
{
	char	*tmp;

	tmp = ft_strtrim(tools->arg, " \t\n\r");
	if (!tmp[0])
		minishell_loop(tools);
	free(tools->arg);
	tools->arg = tmp;
	create_token(tools, &tools->lexer);
	return (0);
}
