# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 09:52:26 by pcervill          #+#    #+#              #
#    Updated: 2024/01/16 12:16:39 by pcervill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra #-g3 -fsanitize=address
EXTRAFLAGS	= -lreadline -L /Users/$(USER)/.brew/opt/readline/lib

SRC_DIR		= ./src

SRCS		= main.c lexer2.c lexer_utils.c quotes2.c check_utils2.c ft_split_cmd_aux_2.c ft_split_cmd_aux.c ft_split_cmd.c

OBJS		= $(addprefix $(OBJS_PATH)/, ${SRCS:.c=.o})

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