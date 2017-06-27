# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akrotov <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/20 11:31:35 by akrotov           #+#    #+#              #
#    Updated: 2017/05/21 22:21:34 by akrotov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Colors =====
END:="\033[0;0m"
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;36m"
PURPLE:="\033[1;35m"
WHITE:="\033[1;37m"
#===================

NAME = fractal

SOURCE = cl.c \
		cl_check_succes.c \
		ft_create_img.c \
		ft_error.c \
		ft_init.c \
		ftcl_create_kernel.c \
		ftcl_get_device.c \
		ftcl_load_program.c \
		ftcl_release.c \
		ftcl_thread.c \
		init_bonus.c \
		init_game.c \
		init_mandatory.c \
		key_hook.c \
		key_swap.c \
		main.c \
		mouse_hook.c \
		sierpinski.c \
		space.c \
		the_game.c

SRCPATH = SRC
HDRPATH = includes
OBJPATH = obj
LIBPATH = libft

CC = gcc

FLAGS = -Wall -Wextra -Werror -I $(HDRPATH)

MLX = -lmlx -framework OpenGL -framework AppKit

LIB = -L $(LIBPATH) -lft -lm


OBJ = $(addprefix $(OBJPATH)/,$(SOURCE:.c=.o))

INC = -I $(HDRPATH) -I $(LIBPATH)

all: load lib $(NAME)

lib:
	@make -C $(LIBPATH)

load:
	@echo $(CYAN)"      LOADING"

$(NAME): $(OBJ)
	@echo $(END)
	@$(CC) $(FLAGS) -o $(NAME) $(LIB) $(MLX) $^
	@echo $(GREEN)"Fractol installed"$(END)

$(OBJPATH)/%.o: $(SRCPATH)/%.c
	@echo ".\c"
	@mkdir $(OBJPATH) 2> /dev/null || true
	@clang $(FLAGS) $(INC) -o $@ -c $<

$(CCHF):
	@mkdir -p $(CCHPATH)
	@touch $(CCHF)

clean:
	@make clean -C $(LIBPATH)
	@rm -rf $(OBJPATH)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBPATH)
	@echo '\033[0;31m'"Fractol uninstalled"'\033[0m'

re: fclean all

norm:
	@norminette SRC/$(SRC)
	@norminette $(HDRPATH)/*.h

.PHONY: all lib clean fclean re norme