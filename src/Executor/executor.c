/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:55:21 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/02/27 12:38:27 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
/*
	TODO: 
		1. Verificar que sean uno o más comandos (según el número de pipes).
			1.1: Si es simple y builtin, se ejecuta en el padre. Si no,
				se crea un proceso (fork) se ejecuta en el hijo.
				Checkear redirects y luego ejecutar cmd como en pipex
			1.2: Si son varios:
				 Bucle para recorrer cmds y muchas movidas.
*/
