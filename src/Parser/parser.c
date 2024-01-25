/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:02:28 by pcervill          #+#    #+#             */
/*   Updated: 2024/01/25 15:49:43 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	parser(t_tools *tools)
{
	t_token *cpy;

	cpy = tools->lexer;
	count_pipes(tools->lexer, tools);
	printf("Number of pipes: %d\n", tools->pipes);
	while (tools->lexer && cpy)
	{
		if (cpy && cpy->type == PIPE)
			ft_lexerdelone(&tools->lexer, cpy->i);
		cpy = cpy->next;
	}
}

/* void	parser(t_tools *tools)
{
	t_token	*current;

	current = NULL;
	count_pipes(tools->lexer, tools);
	printf("Number of pipes: %d\n", tools->pipes);

	// Iterar sobre la lista hasta que no haya más nodos
	while (tools->lexer)
	{
		// Guardar el nodo actual antes de borrarlo
		current = tools->lexer;

		// Avanzar al siguiente nodo antes de eliminar el actual
		tools->lexer = tools->lexer->next;

		// Verificar si el nodo actual es un PIPE y eliminarlo
		if (current->type == PIPE)
		{
			ft_lexerdelone(&tools->lexer, current->i);
		}

		// Si ya no hay más nodos, salir del bucle
		if (!tools->lexer)
		{
			break;
		}
	}
} */
