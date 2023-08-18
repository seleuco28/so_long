# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/01 13:47:33 by alvelazq          #+#    #+#              #
#    Updated: 2023/08/18 13:44:56 by alvelazq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Imlx
RM = rm -rf

HEADER = so_long.h

FUNCTIONS_SOURCES = ft_strlen.c ft_strncmp.c ft_split.c ft_strchr.c ft_strjoin.c get_next_line.c ft_strdup.c
FUNCTIONS_DIR = functions/
FUNCTIONS 			=	$(addprefix $(FUNCTIONS_DIR), $(FUNCTIONS_SOURCES))
FUNCTIONS_OBJ		=	$(FUNCTIONS:.c=.o)

SRC_SOURCES			= main.c utils.c map_creation_and_checks.c check_path.c exit_game.c start_game.c
SRC_DIR				= src/
SRC					= $(addprefix $(SRC_DIR), $(SRC_SOURCES))
SRC_OBJ				= $(SRC:.c=.o)

MLX_PATH = minilibx_opengl/
MINILIBX:= -L $(MLX_PATH) $(MLX_PATH)libmlx.a -lmlx -framework OpenGL -framework AppKit
MINILIBX_OBJ		= $(MINILIBX: .c=.o)


%.o: %.c $(HEADER) Makefile
				@${CC} ${FLAGS} -c $< -o $@

$(NAME):		$(FUNCTIONS_OBJ) $(SRC_OBJ) 
				@make -C $(MLX_PATH)
				@$(CC) $(FUNCTIONS_OBJ) $(SRC_OBJ) $(MINILIBX) -o $(NAME)
				@echo "$(NAME) creado!"

all:		$(NAME)

clean:
				@$(RM) $(FUNCTIONS_OBJ)
				@$(RM) $(SRC_OBJ)
				@echo "Archivos *.o borrados"

fclean:			clean
				@$(RM) $(NAME)
				@echo "Todo borrado!"

re:				fclean all

.PHONY:		all clean fclean re
