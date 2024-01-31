/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:55:21 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/01/31 14:57:53 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
/*
	TODO: 
		1. Verificar que sean uno o más comandos (según el número de pipes).
			1.1: Si es simple y builtin, se ejecuta en el padre. Si no, se crea un proceso (fork) se ejecuta en el hijo. Checkear redirects y luego ejecutar cmd como en pipex
			1.2: Si son varios:
				 Bucle para recorrer cmds y muchas movidas.
*/

