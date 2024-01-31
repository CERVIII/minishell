/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:06:35 by pcervill          #+#    #+#             */
/*   Updated: 2024/01/26 11:47:30 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <signal.h>
#include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
// # include "readline.h"
# define NORMAL  "\x1B[0m"
# define RED  "\033[1;31m"
# define GREEN  "\x1B[32m"
# define YELLOW  "\x1B[33m"
# define BLUE  "\x1B[34m"
# define MAGENT  "\x1B[35m"
# define CYAN  "\x1B[36m"
# define WHITE  "\x1B[37m"

typedef enum e_token_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	RREDIR,
	HERE_DOC,
	DOUBLE_QUOTE,
	SINGLE_QUOTE,	
}	t_token_type;

typedef struct s_token
{
	char			*token;
	t_token_type	type;
	struct s_token	*next;
}	t_token;

typedef struct s_simple_cmds
{
	char                    **str;
	// int                     (*builtin)(t_tools *, struct s_simple_cmds *);
	int                     num_redirections;
	char                    *hd_file_name;
	t_token                 *redirections;
	struct s_simple_cmds	*next;
}	t_simple_cmds;

typedef struct s_tools
{
	char	*pwd;
	char	*old_pwd;
	char	**env;
	char	**export;
}	t_tools;

		/* main.c */
char			*prompt(void);
int				ft_err(char *msg, int nb);
void			print_tokens(t_token **temp);
void 			print_cmds(t_simple_cmds *temp);

		/* lexer.c */
void			create_token(char *input, t_token **token);
void			ft_strlen_token(char *input);
int				lexer(char *input, t_token **token);

		/* lexer_utils.c */
t_token			*ft_token_new(char *token);
void			ft_add_token_last(t_token **list, t_token *new);
void			ft_free_token(t_token **token);

		/* quotes.c */
void			check_quotes(t_token **lst);

		/* check_utils.c */
int				check_redirects(t_token **lst);
int				check_broken_pipes(t_token **lst);
void			check_tokens(t_token **lst);

		/*parser.c*/
void			split_pipes(t_token **lst);

		/* utils.c */
t_simple_cmds	*ft_mini_lstlast(t_simple_cmds *lst);
void			ft_mini_lstadd_back(t_simple_cmds **lst, t_simple_cmds *new);
t_simple_cmds	*ft_mini_lstnew(char **content);
char			**dup_matrix(char **str);
int				save_pwd(t_tools *tools);

		/*Built-ins*/
int				ft_cd(t_tools *tools, char *path);
int				ft_env(t_tools *tools);
int				ft_pwd(t_tools *tools);
int				ft_export(t_tools *tools, t_simple_cmds *simple_cmds);
int				check_builtin(t_token *tokens, t_tools *tools, t_simple_cmds *simple_cmds);
int				ft_unset(t_tools *tools, t_simple_cmds *simple_cmds);
int				ft_exit(t_tools *tools, t_simple_cmds *simple_cmds);
int				ft_echo(t_simple_cmds *simple_cmds);

		/*Built-ins utils*/
int				check_if_nb(char *str);
void			ft_join_export(char **exp);
void			ft_replace_var(char **exp, char *var_name, char *var);
void			ft_update_var(char **exp, char **env ,char *var);
int				ft_is_sorted(char **str);
char			**ft_sort_export(char **str);
void			ft_print_export(char **copy);
char			**ft_update_export(char **exp, char **new_exp, char *var);

		/*	Signals	*/
void			init_signals();
void			rl_replace_line(const char *text, int clear_undo);


#endif