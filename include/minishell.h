/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:06:35 by pcervill          #+#    #+#             */
/*   Updated: 2023/12/15 14:16:28 by fdiaz-gu         ###   ########.fr       */
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
}	t_token_type;

typedef struct s_token
{
	char			*token;
	t_token_type	type;
	struct s_token	*next;
}	t_token;

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
void	read_input(char *argv);
#endif