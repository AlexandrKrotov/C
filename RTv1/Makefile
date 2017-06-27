# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akrotov <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/12 15:31:28 by akrotov           #+#    #+#              #
#    Updated: 2017/06/12 16:45:30 by akrotov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Colors =====
END:= "\033\[0;0m"
BLACK:="\033\[1;39m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;36m"
PURPLE:="\033[1;35m"
WHITE:="\033[1;37m"
#===================

NAME = RTv1

SOURCE = 

SCRPATH = SRC
HDRPATH = includes
OBJPATH = obj
LIBPATH = libft

CC = gcc

FLAGS = -Wall -Wextra -Werror -I $(HDRPATH)

MLX = -lmlx -framework OpenGL -framework Appkit -framework OpenCL

LIB = -L $(LIBPATH) -lft -lm

OBJ = $(addprefix $(OBJPATH)/,$(SOURCE:.c=.o))

INC = -I $(HDRPATH) -I $(LIBPATH)

all: load lib $(NAME)

lib:
	@make -C $(LIBPATH)

load:
	@echo $(CYAN) "        LOADING"

$(NAME): $(OBJ)
	@echo $(END)
	@$(CC) $(FLAGS) -o $(NAME) $(LIB) $(MLX) $^
	@echo $(GREEN)"$(NAME) installed"$(END)

$(OBJPATH)/%.o: $(SRCPATH)/%.c
	@echo ".\c"
	@mkdir $(OBJPATH) 2> /dev/null || true
	@clang $(FLAGS) $(INC) -o $@ -c $<

$(CCHF):
	@mkdir -p $(CCHPATH)
	@touch $(CCHF)

clean:
	@make clean -C $(LIBATH)
	@rm -rf $(OBJPATH)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBPATH)
	@echo $(RED)"$(NAME) installed"$(END)

re: fclean all

norm:
	@norminette SRC/$(SRC)
	@norminette $(HDRPATH)/*.h

.PHONY: all lib clean fclean re norme
