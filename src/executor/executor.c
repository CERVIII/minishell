/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:55:21 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/02/22 11:26:54 by fdiaz-gu         ###   ########.fr       */
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
		if (access(cmd_route, F_OK | X_OK) != -1)
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
	perror("Error");
	return (NULL);
}

int exec_cmd(t_tools *tools)
{
	char	*path;
	char	*route;
	
	path = get_path(tools->env);
	route = get_cmd_route(path, tools->parser->str[0]);
	execve(route, tools->parser->str, tools->env);
	return (ft_error_cmd(tools->parser->str[0]));
}

void	check_cmd(t_tools *tools)
{
	int exit_code;

	exit_code = 0;
	// if (tools->parser->num_redirections > 0)
	// 	if (handle_redirects(tools->parser->redirections) == 0)
	// 		exit(1);
	// if (tools->parser->builtin != NULL)
	// {
	// 	exit_code = tools->parser->builtin(tools, tools->parser);
	// 	exit(exit_code);
	// }
	if (tools->parser->str[0][0])
		exit_code = exec_cmd(tools);
	exit(exit_code);
}

void	execute_single(t_tools *tools)
{
	pid_t	pid;
	int	status;
	// *RESETAER FD
	if (tools->parser->redirections > 0)
		handle_redirects(tools->parser->redirections);
	if (tools->parser->builtin)
	{
		//TODO: Revisar redirecciones con bultins
		tools->parser->builtin(tools, tools->parser);
	}
	else
	{	
		pid = fork();
		if (pid < 0) //TODO: FUNCION DE ERROR
			return ;
		if (pid == 0)
			check_cmd(tools);
		waitpid(pid, &status, 0);
		// if (WIFEXITED(status))
		// 	printf("STATUS: %i\n", WEXITSTATUS(status));
	}
	dup2(tools->input, STDIN_FILENO);
	dup2(tools->output, STDOUT_FILENO);
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

