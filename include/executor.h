/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:22:04 by pcervill          #+#    #+#             */
/*   Updated: 2024/03/05 10:18:12 by pcervill         ###   ########.fr       */
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
void			handle_dup(t_simple_cmds *cmd, t_tools *tools,
					int pipe_fd[2], int fd_in);
void			execute_single(t_tools *tools);
int				exec_cmd(t_tools *tools);
void			execute_one(t_tools *tools);
int				ft_fork(t_tools *tools, int pipe_fd[2], int fd_in,
					t_simple_cmds *parser);
int				pipe_wait(int *pid, int amount);
t_simple_cmds	*ft_simple_cmdsfirst(t_simple_cmds *map);
void			handle_cmd(t_tools *tools);
int				ft_error_cmd(t_tools *tools);
int				ft_error_export(char *str);
int				check_cmd(char **cmd);
int				check_fd_heredoc(t_tools *tools, int end[2], t_simple_cmds *cmd);

#endif