/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:06:35 by pcervill          #+#    #+#             */
/*   Updated: 2024/01/08 13:10:00 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

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
	char					**str;
//	int						(*builtin)(t_tools *, struct s_simple_cmds *);
	int						num_redirections;
	char					*hd_file_name;
	t_token					*redirections;
	struct s_simple_cmds	*next;
	struct s_simple_cmds	*prev;
}	t_simple_cmds;

		/* main.c */
char		*prompt(void);
int			ft_err(char *msg, int nb);

		/* lexer.c */
void		create_token(char *input, t_token **token);
void		ft_strlen_token(char *input);
int			lexer(char *input, t_token **token);

		/* lexer_utils.c */
t_token		*ft_token_new(char *token);
void		ft_add_token_last(t_token **list, t_token *new);
void		ft_free_token(t_token **token);

		/* quotes.c */
void		check_quotes(t_token **lst);

		/* check_utils.c */
int			check_redirects(t_token **lst);
int			check_broken_pipes(t_token **lst);
void		check_tokens(t_token **lst);

#endif
