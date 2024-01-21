# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fede <fede@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 09:52:26 by pcervill          #+#    #+#              #
#    Updated: 2024/01/21 12:50:50 by fede             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra #-g3 -fsanitize=address
EXTRAFLAGS	= -lreadline -L /Users/$(USER)/.brew/opt/readline/lib

SRC_DIR		= ./src
SRC_BUILTIN = ./src/builtins

SRCS		= main.c lexer.c lexer_utils.c quotes.c check_utils.c parser.c utils.c \
			 builtins/cd_in.c builtins/env_in.c builtins/pwd_in.c builtins/check_builtin.c builtins/export_in.c \
			 builtins/unset_in.c builtins/echo_in.c builtins/exit_in.c

OBJS		= $(addprefix $(OBJS_PATH)/, $(notdir $(patsubst %.c, %.o, $(SRCS))))
NAME		= minishell

LIBFT_PATH	= ./libft/

OBJS_PATH = .objs


all: $(NAME)
	@echo " \033[32m[ OK ] | ✅ Minishell ready! ✅\033[0m"

$(NAME): $(OBJS)
	@echo " \033[33m[ .. ] | Compiling libft..\033[0m"
	@make bonus -C $(LIBFT_PATH) --silent
	@echo " \033[32m[ OK ] | ✅ Libft ready! ✅\033[0m"
	@echo " \033[33m[ .. ] | Compiling minishell..\033[0m"
	@$(CC) -L $(LIBFT_PATH) -l ft $(CFLAGS) $(EXTRAFLAGS) $(OBJS)  -o $(NAME)

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)	

$(OBJS_PATH)/%.o:$(SRC_DIR)/%.c | $(OBJS_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_PATH)/%.o:$(SRC_BUILTIN)/%.c | $(OBJS_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_PATH) --silent
	@rm -rf $(OBJS_PATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo " \033[1;31m[ OK ] | 🧹 Minishell fclean ready! 🧹 \033[0m"

re: fclean all

.PHONY = all clean fclean re
.SILENT: $(OBJS)