/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:06:35 by pcervill          #+#    #+#             */
/*   Updated: 2024/01/23 12:19:00 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

# define RESET_COLOR	"\033[0m"
# define BLACK   		"\033[30m"
# define RED     		"\033[31m"
# define LIGHT_RED		"\033[91m"
# define GREEN   		"\033[32m"
# define LIGHT_GREEN	"\033[92m"
# define YELLOW  		"\033[33m"
# define LIGHT_YELLOW	"\033[93m"
# define BLUE    		"\033[34m"
# define LIGHT_BLUE		"\033[94m"
# define MAGENTA 		"\033[35m"
# define LIGHT_MAGENTA	"\033[95m"
# define CYAN    		"\033[36m"
# define LIGHT_CYAN		"\033[96m"
# define WHITE   		"\033[37m"
# define GREY    		"\033[90m"
# define LIGHT_GREY		"\033[37m"

# define BLACK_BOLD   	"\033[1;30m"
# define RED_BOLD     	"\033[1;31m"
# define GREEN_BOLD   	"\033[1;32m"
# define YELLOW_BOLD  	"\033[1;33m"
# define BLUE_BOLD    	"\033[1;34m"
# define MAGENTA_BOLD 	"\033[1;35m"
# define CYAN_BOLD    	"\033[1;36m"
# define WHITE_BOLD   	"\033[1;37m"

# define PROMPT_MSG "\033[1;36m$minishell/ \033[0m"

typedef struct s_string_info
{
	char	*s;
	size_t	*i;
	char	current_quote;
}t_info;

typedef enum e_token_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	RREDIR,
	HERE_DOC,
}	t_token_type;

/* Old checker_utils */
/* typedef enum e_token_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	RREDIR,
	HERE_DOC,
	DOUBLE_QUOTE,
	SINGLE_QUOTE
}	t_token_type; */

typedef struct s_token
{
	char			*token;
	t_token_type	type;
	int				i;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_tools
{
	t_token					*lexer;
	struct s_simple_cmds	*parser;
	char					*arg;
	int						pipes;
}	t_tools;

typedef struct s_simple_cmds
{
	char					**str;
	int						(*builtin)(t_tools *, struct s_simple_cmds *);
	int						num_redirections;
	char					*hd_file_name;
	t_token					*redirections;
	struct s_simple_cmds	*next;
	struct s_simple_cmds	*prev;
}	t_simple_cmds;


		/* main.c */
void	print_tokens(t_token *temp);
char	*prompt(void);
int		ft_err(char *msg, int nb, t_tools *tools);
void	free_err(t_tools *tools);

		/* minishell_loop.c */
void	minishell_loop(t_tools *tools);

	/* ###########	LEXER	########### */

		/* split */
char	**ft_split_cmd(char *s, char c);
size_t	ft_count_words_cmd(char *s, char c);
char	*get_next_word(char *s, size_t *start, char c);
void	skip_delimiters(char *s, size_t *start, char c, int in_quotes);
void	process_word(char *s, size_t *i, int *in_quotes, char *current_quote);
void	process_delimiter_split(char *s, size_t *i, char c, int in_quotes);
void	process_char(t_info *info, size_t *word_count, char c, int *in_quotes);
t_info	initialize_string_info(char *s, size_t *i);
void	process_delimiter(t_info *info, size_t *w_c, char c, int in_quotes);
void	p_quotes_cmd(char *s, size_t *i, int *in_quotes, char *current_quote);
int		ft_is_whitespace(char c);
int		ft_skip_spaces(char *str);

		/* lexer_utils.c */
t_token	*ft_token_new(char *token, int i);
void	ft_add_token_last(t_token **list, t_token *new);
void	ft_free_token(t_token **token);

		/* lexer.c */
void	create_token(t_tools *tools, t_token **token);
void	ft_strlen_token(char *str);
int		lexer(t_tools *tools);

	/* ###########	PARSER	########### */

		/* check_utils.c */
int		check_redirects(t_token **lst, t_tools *tools);
int		check_broken_pipes(t_token **lst, t_tools *tools);
void	check_tokens(t_tools *tools, t_token **lst);

		/* clean_lexer.c */
t_token	*ft_lexerclear_one(t_token **tmp);
void	ft_lexerdel_first(t_token **lexer);
void	ft_lexerdelone(t_token **lexer, int key);

		/* parser_utils.c */
void	count_pipes(t_token *lexer, t_tools *tools);

		/* parser.c */
void	parser(t_tools *tools);

	/* ###########	QUOTES	########### */

		/* quotes.c */
int		change_flag(int flag);
int		quotes(char *input, int *i, int flag, char c);
void	check_quotes(t_tools *tools);


#endif
