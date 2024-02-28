/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:24:53 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/02/28 11:19:54 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	save_pwd(t_tools *tools)
{
	int	i;

	i = 0;
	tools->pwd = getcwd(NULL, sizeof(NULL));
	while (tools->env[i])
	{
		if (ft_strncmp(tools->env[i], "OLDPWD=", 7) == 0)
			tools->old_pwd = ft_substr(tools->env[i], 7,
				ft_strlen(tools->env[i]) - 7);
		i++;
	}
	return (1);
}

char	**dup_matrix(char **str)
{
	char 	**dup;
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	dup = ft_calloc(i + 1, sizeof (char *));
	i = 0;
	while (str[i])
	{
		dup[i] = ft_strdup(str[i]);
		i++;
	}
	return (dup);
}


t_simple_cmds	*ft_mini_lstnew(char **content)
{
	t_simple_cmds	*new;

	new = (t_simple_cmds *)malloc(sizeof(t_simple_cmds));
	if (!new)
		return (NULL);
	new->str = content;
	new->next = NULL;
	return (new);
}

t_simple_cmds	*ft_mini_lstlast(t_simple_cmds *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

void	ft_mini_lstadd_back(t_simple_cmds **lst, t_simple_cmds *new)
{
	t_simple_cmds	*cpy;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		cpy = *lst;
		while (cpy->next)
			cpy = cpy->next;
		cpy -> next = new;
	}
	return ;
}
