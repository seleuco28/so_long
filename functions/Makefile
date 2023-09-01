# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 17:19:36 by alvarovelaz       #+#    #+#              #
#    Updated: 2022/05/10 11:09:56 by alvelazq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIB = ar -rcs

SRC = ft_printf_s.c ft_printf_di.c ft_printf_p.c ft_printf_u.c ft_printf_xX.c ft_printf.c \

OBJ = $(SRC:.c=.o)

RM = rm -f

CC = gcc -Wall -Wextra -Werror

$(NAME) : $(OBJ)
	$(LIB) $(NAME) $(OBJ)

all: $(NAME)

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re

