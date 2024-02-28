/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:22:04 by pcervill          #+#    #+#             */
/*   Updated: 2024/02/28 17:33:33 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "minishell.h"

typedef struct s_string_info	t_info;
typedef struct s_token			t_token;
typedef struct s_tools			t_tools;

	/*		Executor.c		*/
int				before_execution(t_tools *tools);
int				handle_redirects(t_token *redirects);
char			*get_cmd_route(char *path, char	*cmd);
char			*get_path(char **env);
void			handle_dup(t_simple_cmds *cmd, t_tools *tools, int pipe_fd[2], int fd_in);
void			execute_single(t_tools *tools);
int				exec_cmd(t_tools *tools);
void			execute_one(t_tools *tools);
int				ft_fork(t_tools *tools, int pipe_fd[2], int fd_in, t_simple_cmds *parser);
int				pipe_wait(int *pid, int amount);
t_simple_cmds	*ft_simple_cmdsfirst(t_simple_cmds *map);
int				ft_error_cmd(t_tools *tools);
#endif