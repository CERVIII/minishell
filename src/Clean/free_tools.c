/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:09:52 by pcervill          #+#    #+#             */
/*   Updated: 2024/02/27 15:42:50 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
//#include "../../include/clean.h"

void	free_arr(char **split_arr)
{
	int	i;

	i = 0;
	while (split_arr[i])
	{
		free(split_arr[i]);
		i++;
	}
	free(split_arr);
}
void	ft_lexorclear(t_token **lst)
{
	t_token	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		if ((*lst)->token)
			free((*lst)->token);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

void	ft_simple_cmdsclear(t_simple_cmds **lst)
{
	t_simple_cmds	*tmp;
	t_token			*redirections_tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		redirections_tmp = (*lst)->redirections;
		ft_lexorclear(&redirections_tmp);
		if ((*lst)->str)
			free_arr((*lst)->str);
		if ((*lst)->hd_file_name)
			free((*lst)->hd_file_name);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

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
		free(tools->arg);
	if (tools->lexer)
		free_lexer(tools->lexer);
	if (tools->parser)
		free_parser(tools->parser);
	init_tools(tools);
	tools->reset = true;
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

