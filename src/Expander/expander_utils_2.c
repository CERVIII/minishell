/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:10:24 by pcervill          #+#    #+#             */
/*   Updated: 2024/03/04 14:12:53 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**empty_str(char **str)
{
	int		i;
	char	**tmp;

	i = 0;
	if (ft_strlen(str[0]) < 1)
	{
		while (str[i])
			i++;
		tmp = (char **)ft_calloc(i - 1, sizeof(char *));
		i = 0;
		while (str[i])
		{
			str[i] = str[i + 1];
			i++;
		}
	}
	return (str);
}
