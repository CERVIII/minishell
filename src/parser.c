/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:02:31 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/01/09 12:35:06 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* void	split_pipes(t_token **lst)
{
	t_simple_cmds	**new_lst;
	t_token			*aux_lst;
	t_simple_cmds	*new;
	char			**aux;

	new_lst = (t_simple_cmds **) malloc(sizeof(t_simple_cmds *));
	*new_lst = NULL;
	aux_lst = *lst;
	while (aux_lst)
	{		
		if (aux_lst->type == 1)
			aux_lst = aux_lst->next;
		aux = ft_split(aux_lst->token, ' ');		
		new = ft_mini_lstnew(aux);		
		ft_mini_lstadd_back(new_lst, new);
		aux_lst = aux_lst->next;		
	}	
	print_cmds(*new_lst);
} */

void	split_pipes(t_token **lst)
{
	t_simple_cmds	**new_lst;
	t_token			*aux_lst;
	t_simple_cmds	*new;
	// char			*aux_join;
	char			*main_join;
	char			**aux;

	new_lst = (t_simple_cmds **) malloc(sizeof(t_simple_cmds *));
	*new_lst = NULL;
	aux_lst = *lst;
	while (aux_lst->next)
	{
		main_join = NULL;
		while (aux_lst && aux_lst->type != 1)
		{
			// printf("Token %s\n", aux_lst->token);
			if (aux_lst->type == 1)
				break ;
			main_join = ft_strjoin2(main_join, aux_lst->token);			
			aux_lst = aux_lst->next;
			printf("Bucle: %s\n", main_join);
		}
		printf("FUERA\n");
		printf("JOIN: %s\n", main_join);
		aux = ft_split(main_join, ' ');		
		new = ft_mini_lstnew(aux);		
		ft_mini_lstadd_back(new_lst, new);
		printf("---------------------------\n");
		aux_lst = aux_lst->next;		
	}	
	// print_cmds(*new_lst);
}
