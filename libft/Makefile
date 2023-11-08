# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 20:25:05 by pcervill          #+#    #+#              #
#    Updated: 2023/11/08 12:57:58 by pcervill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	libft.a

####FILES####

SRC		= 	ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		  	ft_isprint.c ft_memchr.c ft_memcpy.c ft_memmove.c ft_memset.c \
			ft_strchr.c	ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
			ft_strrchr.c ft_tolower.c ft_toupper.c ft_atoi.c ft_memcmp.c \
			ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_strcmp.c ft_get_next_line.c ft_get_next_line_utils.c ft_error.c \
			ft_intlen.c ft_freestr.c

BONUS	=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ 	= 	$(SRC:%.c=%.o)

OBJB	=	$(BONUS:%.c=%.o)

####COMPILE####

CFLAGS 	= 	-Wall -Wextra -Werror 

CC		=	gcc

RM 		= 	rm -f

B		=	.

#####COMPILE TARGET####

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

bonus: $(B)
	
$(B):	$(OBJ) $(OBJB)
	@ar rcs $(NAME) $(OBJ) $(OBJB)

####TARGETS####

clean:
	@$(RM) $(OBJ) $(OBJB)

fclean:
	@$(RM) $(NAME)
	@$(RM) $(OBJ) $(OBJB)

re: fclean all bonus

.PHONY: fclean all clean re bonus
