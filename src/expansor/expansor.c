/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:47:51 by pcervill          #+#    #+#             */
/*   Updated: 2024/02/14 10:01:49 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	expansor(char *str)
{
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("Error: No arguments\n");
		return (1);
	}
	printf("Expansor: %s\n", argv[1]);
	return (0);
}
