# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 09:52:26 by pcervill          #+#    #+#              #
#    Updated: 2024/04/24 12:25:33 by pcervill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g3 #-fsanitize=address

UNAME		:=	$(shell uname -s)
ifeq ($(UNAME),Darwin)
	EXTRAFLAGS	=	-lreadline -lhistory -L/Users/$(USER)/.brew/opt/readline/lib -I/Users/$(USER)/.brew/opt/readline/include
else
	EXTRAFLAGS	=	-lreadline -lhistory -L/usr/lib/x86_64-linux-gnu -I/usr/include/readline
endif

SRCS		=	main.c minishell_loop.c shlvl.c signals.c utils.c utils2.c \
				cd_in.c check_builtin.c echo_in.c env_in.c exit_in.c export_in.c \
				export_trim.c export_utils.c pwd_in.c unset_in.c free_tools.c \
				error.c executor_utils.c executor.c find_cmd.c handle_redirects.c \
				heredoc.c expander_utils_2.c expander_utils.c expander.c \
				check_input.c ft_split_cmd_aux_2.c ft_split_cmd_aux.c \
				ft_split_cmd.c lexer_utils.c lexer.c check_token.c clean_lexer.c \
				cmd_utils.c parser_utils.c parser.c redirections.c quotes.c \

OBJS_PATH	=	./src
LIBFT_PATH	=	./libft/

OBJS		=	$(addprefix $(OBJS_PATH)/, $(SRCS:.c=.o))
LIBFT		=	-L $(LIBFT_PATH) $(LIBFT_PATH)libft.a

NAME		=	minishell

all: $(NAME)
	@echo " \033[32m[ OK ] | ✅ Minishell ready! ✅\033[0m"

$(NAME): $(OBJS)
	@echo " \033[33m[ .. ] | Compiling Libft..\033[0m"
	@make bonus -C $(LIBFT_PATH) --silent
	@echo " \033[32m[ OK ] | ✅ Libft ready! ✅\033[0m"
	@echo " \033[33m[ .. ] | Compiling minishell..\033[0m"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(EXTRAFLAGS)

clean:
	@make clean -C $(LIBFT_PATH) --silent
	@rm -rf $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@rm -f $(NAME)
	@echo " \033[1;31m[ OK ] | 🧹 Minishell fclean ready! 🧹 \033[0m"

re: fclean all

.PHONY = all clean fclean re
.SILENT: $(OBJS)
