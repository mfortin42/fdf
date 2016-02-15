# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfortin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 20:51:06 by mfortin           #+#    #+#              #
#    Updated: 2016/02/15 21:52:30 by jgan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror -O3

NAME = fdf

SRC = 	src/main.c \
	  	src/parsing.c \
		src/resolver.c \
		src/utilities.c

OBJ = $(SRC:.c=.o)

MLX = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
		@make -k -C libft
		@gcc $(FLAG) -o $(NAME) $(OBJ) $(MLX) -Llibft -lft
		@echo "$(NAME) created"

%.o: %.c
		@gcc $(FLAG) -c $< -o $@

clean:
		@make clean -k -C libft
		@rm -f $(OBJ)
		@echo "$(NAME) *.o deleted"

fclean: clean
		@make fclean -k -C libft
		@rm -f $(NAME)
		@echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re
