# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akrotov <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/18 21:12:29 by akrotov           #+#    #+#              #
#    Updated: 2017/05/18 21:20:41 by akrotov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FdF

CC = gcc

CFLAG = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

SOURCE = main.c ft_draw_line.c ft_parser.c libft/get_next_line.c ft_hook.c \
ft_error.c axis_rotation.c mulst_scale_shift.c all_calc.c all_free.c \
all_color.c bonus_ft.c draw_map.c ft_mouse_hook.c

OBJ = $(SOURCE:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAG)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: clean all
