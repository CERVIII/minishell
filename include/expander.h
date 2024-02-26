/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:23:21 by pcervill          #+#    #+#             */
/*   Updated: 2024/02/26 11:46:03 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "minishell.h"

typedef struct s_string_info	t_info;
typedef struct s_token			t_token;
typedef struct s_tools			t_tools;
typedef struct s_token			t_token;
typedef struct s_simple_cmds	t_simple_cmds;

char			*check_env(char *str, char **env, int *i);
char			*detect_dollar_sign(char *str, char **env);
int				cmp_dollar(char *str, int *i, char flag);
int				quotes_dollar(char *str);
int				dollar_sign(char *str);
char			**expansor(char **str, t_tools *tools);
t_simple_cmds	*check_expander(t_tools *tools, t_simple_cmds *cmd);

#endif