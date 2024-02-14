/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:09:52 by pcervill          #+#    #+#             */
/*   Updated: 2024/02/14 11:07:52 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
//#include "../../include/clean.h"

int	ft_err(char *msg, int nb, t_tools *tools)
{
	printf("%s%s%s\n", RED, msg, NORMAL);
	free_tools(tools);
	return (nb);
}

void	free_tools(t_tools *tools)
{
	t_token	*tmp;

	tmp = tools->lexer;
	if (tools->arg)
	{
		free(tools->arg);
		tools->arg = NULL;
	}
	if (tools->lexer)
		free_lexer(tools->lexer);
	if (tools->parser)
		free_parser(tools->parser);
	minishell_loop(tools);
}

void	free_lexer(t_token *lexer)
{
	t_token	*tmp;
	t_token	*tmp2;

	tmp = lexer;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp->token);
		free(tmp);
		tmp = tmp2;
	}
	lexer = NULL;
}

void	free_parser(t_simple_cmds *parser)
{
	t_simple_cmds	*tmp;
	t_simple_cmds	*tmp2;
	int				i;

	tmp = parser;
	while (tmp)
	{
		tmp2 = tmp->next;
		if (tmp->str)
		{
			i = 0;
			while (tmp->str[i])
				free(tmp->str[i++]);
			free(tmp->str);
			tmp->str = NULL;
		}
		if (tmp->redirections)
		{
			free_lexer(tmp->redirections);
			tmp->redirections = NULL;
		}
		free(tmp->hd_file_name);
		tmp->hd_file_name = NULL;
		free(tmp);
		tmp = tmp2;
	}
	parser = NULL;
}
