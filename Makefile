# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/01 13:47:33 by alvelazq          #+#    #+#              #
#    Updated: 2023/09/11 12:40:47 by alvelazq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Imlx 
RM = rm -rf

HEADER = so_long.h
HEADER_BONUS = so_long_bonus.h

FUNCTIONS_SOURCES = ft_strlen.c ft_strncmp.c ft_split.c ft_strchr.c ft_strjoin.c get_next_line.c ft_strdup.c ft_putstr.c ft_itoa.c
FUNCTIONS_DIR = functions/
FUNCTIONS 			=	$(addprefix $(FUNCTIONS_DIR), $(FUNCTIONS_SOURCES))
FUNCTIONS_OBJ		=	$(FUNCTIONS:.c=.o)

SRC_SOURCES			= main.c utils.c map_creation_and_checks.c check_path.c exit_game.c moves.c key_detection.c counts.c
SRC_DIR				= src/
SRC					= $(addprefix $(SRC_DIR), $(SRC_SOURCES))
SRC_OBJ				= $(SRC:.c=.o)

SRC_SOURCES_BONUS	= main_bonus.c utils_bonus.c map_creation_and_checks_bonus.c check_path_bonus.c exit_game_bonus.c moves_bonus.c key_detection_bonus.c counts_bonus.c
SRC_DIR_BONUS		= src/bonus/
SRC_BONUS			= $(addprefix $(SRC_DIR_BONUS), $(SRC_SOURCES_BONUS))
SRC_OBJ_BONUS		= $(SRC_BONUS:.c=.o)

MLX_PATH = minilibx_opengl/
MINILIBX:= -L $(MLX_PATH) $(MLX_PATH)libmlx.a -lmlx -framework OpenGL -framework AppKit
MINILIBX_OBJ		= $(MINILIBX: .c=.o)


%.o: %.c $(HEADER) $(HEADER_BONUS) Makefile
				@${CC} ${FLAGS} -c $< -o $@


$(NAME):		$(FUNCTIONS_OBJ) $(SRC_OBJ)
				@$(CC) $(FUNCTIONS_OBJ) $(SRC_OBJ) $(MINILIBX) -o $(NAME)
				@echo "$(NAME) creado!"

$(NAME_BONUS): $(FUNCTIONS_OBJ) $(SRC_OBJ_BONUS)
				@$(CC) $(FUNCTIONS_OBJ) $(SRC_OBJ_BONUS) $(MINILIBX) -o $(NAME_BONUS)
				@echo "$(NAME_BONUS) creado!"

all:		$(NAME)			

bonus : $(NAME_BONUS)
		@echo "bonus NO tira?"

clean:
				@$(RM) $(FUNCTIONS_OBJ)
				@$(RM) $(SRC_OBJ) $(SRC_OBJ_BONUS)
				@echo "Archivos *.o borrados"

fclean:			clean
				@$(RM) $(NAME) $(NAME_BONUS)
				@echo "Todo borrado!"

re:				fclean all


.PHONY:		all clean fclean re
