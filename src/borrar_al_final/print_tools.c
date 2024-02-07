/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:56:44 by pcervill          #+#    #+#             */
/*   Updated: 2024/02/07 13:57:27 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/borrar_al_final.h"

void	print_tokens(t_token *tmp)
{
	while (tmp)
	{
		printf("%sToken: %s%s	%sType: %s%d	%sIndex: %s%d%s\n", YELLOW_BOLD, YELLOW, tmp->token, BLUE_BOLD, BLUE, tmp->type, MAGENTA_BOLD, MAGENTA, tmp->i, NORMAL);
		tmp = tmp->next;
	}
}

void	print_simple_cmd(t_simple_cmds *cmd)
{
	t_simple_cmds	*tmp;
	int				i;
	int				j;

	tmp = cmd;
	printf("\n%sSimple command%s\n", GREEN_BOLD, NORMAL);
	j = 1;
	while (tmp)
	{
		i = 0;
		printf("\n%sCommand number: %d%s\n", RED_BOLD, j++, NORMAL);
		printf("%sNumber of redirections: %d%s\n", BLUE_BOLD, tmp->num_redirections, NORMAL);
		if (tmp->redirections > 0)
		{
			printf("\n%sRedirections:%s\n", BLUE_BOLD, NORMAL);
			print_tokens(tmp->redirections);
		}
		if (tmp->str)
		{
			printf("\n%sArguments:%s\n", BLUE_BOLD, NORMAL);
			while (tmp->str[i])
			{
				printf("%s\n", tmp->str[i]);
				i++;
			}
		}
		tmp = tmp->next;
	}
}
