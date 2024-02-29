/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:49:38 by pcervill          #+#    #+#             */
/*   Updated: 2024/02/28 18:05:56 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

		/*Built-ins*/
int		(*check_builtin(char *tokens))(t_tools *tools, t_simple_cmds *simple_cmds);
int		ft_cd(t_tools *tools, t_simple_cmds *simple_cmds);
int		ft_env(t_tools *tools, t_simple_cmds *simple_cmds);
int		ft_pwd(t_tools *tools, t_simple_cmds *simple_cmds);
int		ft_export(t_tools *tools, t_simple_cmds *simple_cmds);
int		ft_unset(t_tools *tools, t_simple_cmds *simple_cmds);
int		ft_exit(t_tools *tools, t_simple_cmds *simple_cmds);
int		ft_echo(t_tools *tools, t_simple_cmds *simple_cmds);

		/*Built-ins utils*/
char	*ft_joinvar(char *str);
int		check_if_nb(char *str);
void	ft_join_export(char **exp);
void	ft_update_var(char **exp, char *var);
int		ft_is_sorted(char **str);
char	**ft_sort_export(char **str);
void	ft_print_export(char **copy);
char	**ft_update_export(char **exp, char **new_exp, char *var);
char	*ft_trim_quotes(char *str);
void	ft_update_both(char **env, char **exp, char *str);
int		ft_check_if_exists(char **export, char *var);

#endif