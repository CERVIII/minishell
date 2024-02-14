/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:44:41 by pcervill          #+#    #+#             */
/*   Updated: 2024/02/14 09:54:21 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
//#include "../../include/parser.h"

t_simple_cmds	*create_node_cmd(t_parser_tools *parser_tools)
{
	char	**str;
	int		num_arg;
	int		i;
	t_token	*tmp;

	num_arg = 0;
	redirection_add(parser_tools);
	num_arg = count_arg(parser_tools->lexer);
	str = (char **)ft_calloc(sizeof(char *), (num_arg + 1));
	if (!str)
		return (new_node_cmd(NULL, parser_tools)); //falta funcion error
	i = 0;
	tmp = parser_tools->lexer;
	while (num_arg > 0)
	{
		if (tmp->type == WORD)
		{
			str[i++] = ft_strdup(tmp->token);
			ft_lexerdelone(&parser_tools->lexer, tmp->i);
			tmp = parser_tools->lexer;
			num_arg--;
		}
	}
	return (new_node_cmd(str, parser_tools));
}

t_simple_cmds	*new_node_cmd(char **str, t_parser_tools *parser_tools)
{
	t_simple_cmds	*node;

	node = (t_simple_cmds *)malloc(sizeof(t_simple_cmds));
	node->builtin = check_built(str[0]);
	node->hd_file_name = NULL;
	node->num_redirections = parser_tools->num_redirections;
	node->redirections = parser_tools->redirections;
	node->str = str;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	add_back_cmd(t_simple_cmds **cmd, t_simple_cmds *node)
{
	t_simple_cmds	*tmp;

	tmp = *cmd;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	tmp->next->prev = tmp;
}
