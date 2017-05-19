# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akrotov <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/18 21:12:29 by akrotov           #+#    #+#              #
#    Updated: 2017/05/19 17:48:12 by akrotov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

FLAG = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

LIB = libft/libft.a

SOURCE = main.c ft_draw_line.c ft_parser.c libft/get_next_line.c ft_hook.c \
ft_error.c axis_rotation.c mulst_scale_shift.c all_calc.c all_free.c \
all_color.c bonus_ft.c draw_map.c ft_mouse_hook.c

OBJ = $(SOURCE:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C ./libft
	@$(CC) $(OBJ) $(LIB) $(CFLAG) $(MLX) -o $(NAME)
	@echo '\033[0;32m'"FDF READY"'\033[0m'

%.o: %.c
	 @gcc -c -Wall -Wextra -Werror -o $@ $<
	 @echo "*"

clean:
	@make clean -C ./libft
	@rm -f $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(LIB)
	@echo '\033[0;31m'"FDF IS CLEARED"'\033[0m'

re: fclean all
