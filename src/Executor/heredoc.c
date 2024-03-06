/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:33:22 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/03/06 18:36:09 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_heredoc_name(void)
{
	static int	i = 0;
	char		*name;
	char		*num;

	num = ft_itoa(i++);
	name = ft_strjoin("temp/tmp_heredoc_", num);
	free(num);
	return (name);
}

int	check_heredoc(t_tools *tools, t_simple_cmds *cmds)
{
	t_simple_cmds	*aux;

	aux = cmds;
	while (aux)
	{
		if (aux->hd_file_name)
			free(aux->hd_file_name);
		aux->hd_file_name = ft_heredoc_name();
		if (handle_heredoc(tools))
		{
			g_error = 1;
			free_tools(tools);
			return (EXIT_FAILURE);
		}
		aux = aux->next;
	}
	return (EXIT_SUCCESS);
}
