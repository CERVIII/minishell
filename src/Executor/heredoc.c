/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:33:22 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/03/06 12:07:28 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_heredoc_name(void)
{
	char	*name;

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
		aux = aux->next;
	}
	
	return (EXIT_SUCCESS);
}