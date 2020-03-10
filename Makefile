# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/13 14:06:41 by dholiday          #+#    #+#              #
#    Updated: 2020/03/10 15:38:46 by dholiday         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIBFTPATH = ./libft
LIBFT = $(LIBFTPATH)/libft.a

MLXPATH = ./minilibx_macos
MLX = $(MLXPATH)/libmlx.a

FLAGS = -I $(MLXPATH) -L $(MLXPATH) -lmlx -framework OpenGL -framework AppKit -Wall -Werror -Wextra
CFLAGS =  -I. -I$(LIBFTPATH) -Iinc -g3

SRC_PATH = ./srcs/
SRC_NAME = main.c init.c print.c key.c clean.c general.c mouse.c algorithm.c color.c
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ = $(SRC:%.c=%.o)

GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
RESET = \033[0m

all: $(NAME)

$(NAME) :  $(MLX) $(OBJ) $(LIBFT)
	@echo "$(PURPLE)creating $(FDF)$(RESET)"
	@gcc  $(FLAGS) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ) : ./fractol.h

$(LIBFT) :
	@echo "$(YELLOW)make $(LIBFT)$(RESET)"
	@make -sC $(LIBFTPATH)

$(OBJ) : ./fractol.h

$(MLX) :
	@echo "$(GREEN)make $(MLX)$(RESET)"
	@make -sC $(MLXPATH)

clean:
	@echo "$(RED)make clean $(LIBFT)$(RESET)"
	@echo "$(RED)make clean $(MLX)$(RESET)"
	@echo "$(RED)clean objects$(RESET)"
	@make clean -sC $(LIBFTPATH)
	@make clean -sC $(MLXPATH)
	@rm -f $(OBJ)

fclean: clean
	@echo "$(RED)make fclean $(LIBFT)$(RESET)"
	@make fclean -sC $(LIBFTPATH)
	@echo "$(RED)clean $(NAME)$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
		
