# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 09:52:26 by pcervill          #+#    #+#              #
#    Updated: 2024/03/12 11:54:32 by pcervill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc

CFLAGS		= -Wall -Werror -Wextra -g3 #-fsanitize=address
EXTRAFLAGS	= -lreadline -lhistory -L/Users/$(USER)/.brew/opt/readline/lib -I/Users/$(USER)/.brew/opt/readline/include

SRC_DIR			= ./src
SRC_BUILTIN		= ./src/builtins
SRC_EXECUTOR	= ./src/Executor
SRC_LEXER		=	./src/Lexer
SRC_PARSER		=	./src/Parser
SRC_QUOTES		=	./src/Quotes
SRC_EXPANDER	= 	./src/Expander
SRC_CLEAN		=	./src/Clean
SRC_DELETE		=	./src/borrar_al_final

SRCS		=	main.c utils.c utils2.c signals.c minishell_loop.c \
				builtins/cd_in.c builtins/check_builtin.c builtins/echo_in.c \
				builtins/env_in.c builtins/exit_in.c builtins/export_in.c \
				builtins/export_trim.c builtins/export_utils.c builtins/pwd_in.c \
				builtins/unset_in.c \
				Lexer/check_input.c Lexer/ft_split_cmd.c Lexer/ft_split_cmd_aux.c Lexer/ft_split_cmd_aux_2.c Lexer/lexer_utils.c Lexer/lexer.c \
				Parser/check_token.c Parser/parser.c Parser/clean_lexer.c Parser/cmd_utils.c Parser/parser_utils.c Parser/redirections.c \
				Quotes/quotes.c \
				Clean/free_tools.c \
				borrar_al_final/print_tools.c \
				Expander/expander.c Expander/expander_utils.c Expander/expander_utils_2.c \
				Executor/executor.c Executor/executor_utils.c Executor/find_cmd.c Executor/handle_redirects.c Executor/error.c

OBJS		= $(addprefix $(OBJS_PATH)/, $(notdir $(patsubst %.c, %.o, $(SRCS))))
NAME		= minishell

LIBFT_PATH	=	./libft/

OBJS_PATH = .objs

all: $(NAME)
	@echo " \033[32m[ OK ] | ✅ Minishell ready! ✅\033[0m"

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)	

$(OBJS_PATH)/%.o:$(SRC_DIR)/%.c | $(OBJS_PATH)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(OBJS_PATH)/%.o:$(SRC_LEXER)/%.c | $(OBJS_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_PATH)/%.o:$(SRC_PARSER)/%.c | $(OBJS_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_PATH)/%.o:$(SRC_QUOTES)/%.c | $(OBJS_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_PATH)/%.o:$(SRC_CLEAN)/%.c | $(OBJS_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_PATH)/%.o:$(SRC_DELETE)/%.c | $(OBJS_PATH)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(OBJS_PATH)/%.o:$(SRC_BUILTIN)/%.c | $(OBJS_PATH)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(OBJS_PATH)/%.o:$(SRC_EXPANDER)/%.c | $(OBJS_PATH)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(OBJS_PATH)/%.o:$(SRC_EXECUTOR)/%.c | $(OBJS_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo " \033[33m[ .. ] | Compiling Libft..\033[0m"
	@make bonus -C $(LIBFT_PATH) --silent
	@echo " \033[32m[ OK ] | ✅ Libft ready! ✅\033[0m"
	@echo " \033[33m[ .. ] | Compiling minishell..\033[0m"
	@$(CC) -L $(LIBFT_PATH) -l ft $(CFLAGS) $(EXTRAFLAGS) $(OBJS)  -o $(NAME)

clean:
	@make clean -C $(LIBFT_PATH) --silent
	@rm -rf $(OBJS_PATH)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@rm -f $(NAME)
	@echo " \033[1;31m[ OK ] | 🧹 Minishell fclean ready! 🧹 \033[0m"

re: fclean all

.PHONY = all clean fclean re
.SILENT: $(OBJS)

