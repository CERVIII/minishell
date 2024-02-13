/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:55:21 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/02/13 17:13:03 by fdiaz-gu         ###   ########.fr       */
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
/*
07_minishell git:(fede_builtin) ✗ wc -l < prueba 
      13
➜  07_minishell git:(fede_builtin) ✗ prueba < wc -l
zsh: no such file or directory: wc
➜  07_minishell git:(fede_builtin) ✗ < prueba wc -l
      13*/
char	*get_cmd_route(char *path, char	*cmd)
{
	char	**possible_path;
	char	*cmd_route;
	char	*aux_route;
	char	*aux;
	int		i;

	i = 0;
	aux = ft_strtrim(path, "PATH=");
	possible_path = ft_split(aux, ':');
	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	while (possible_path[++i])
	{
		aux_route = ft_strjoin(possible_path[i], "/");
		cmd_route = ft_strjoin(aux_route, cmd);
		if (access(cmd_route, F_OK) != -1 && access(cmd_route, X_OK) != -1)
			break ;
		else
		{
			free(aux_route);
			free(cmd_route);
		}
	}
	free (aux);
	return (cmd_route);
}
char	*get_path(char **env)
{
	int		i;
	char	*envp_path;
	char	*cmd_route;

	i = 0;
	envp_path = NULL;
	cmd_route = NULL;
	while (env[i])
	{
		if (ft_strncmp("PATH", env[i], 4) == 0)
		{
			envp_path = env[i];
			return (envp_path);
		}
		i++;
	}
	//TODO:FT_ERROR
	return (NULL);
}

void exec_cmd(t_tools *tools)
{
	char	*path;
	char	*route;
	
	path = get_path(tools->env);
	route = get_cmd_route(path, tools->parser->str[0]);
	if (execve(route, tools->parser->str, tools->env) == -1)
		ft_error_cmd(tools->parser->str[0]);
	
}

void	check_cmd(t_tools *tools)
{
	int exit_code;
	//TODO: check cosas
	if (tools->parser->builtin != NULL)
	{
		exit_code = tools->parser->builtin(tools, tools->parser);
		exit(exit_code);
	}
	exec_cmd(tools);
}

void	execute_single(t_tools *tools)
{
	int pid;

	if (tools->parser->builtin)
	{
		tools->parser->builtin(tools, tools->parser);
		return ;
	}
	pid = fork();
	if (pid == -1) //TODO: FUNCION DE ERROR
		return ;
	if (pid == 0)
		check_cmd(tools);
	waitpid(pid, NULL, 0);
			
}

int	before_execution(t_tools *tools)
{
	if (tools->pipes == 0)
		execute_single(tools);
	else
	{
		tools->pid = ft_calloc(sizeof(int), tools->pipes + 2);
		if (!tools->parser)
		{
			free_tools(tools);
			return (0);
		}
		// execute(tools);
	}
	return (EXIT_SUCCESS);
}

