# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/25 20:36:21 by dbirtel           #+#    #+#              #
#    Updated: 2017/04/09 14:34:10 by dbirtel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

SRC = main.c\
	  error.c\
	  init.c\
	  check.c\
	  elements.c\
	  parse.c\
	  input.c\
	  sphere.c\
	  ray.c\
	  solve.c\
	  cylinder.c\
	  plane.c\
	  cone.c\
	  color.c\
	  normal.c\
	  o_reflect.c\
	  o_filter.c\
	  o_refraction.c\
	  o_transparent.c

OBJ = $(SRC:.c=.o)

CC = clang -I /usr/local/include

CFLAGS = -Wall -Wextra -Werror -O3

MLX_FLAGS = -L /usr/local/lib -lmlx -framework Opengl -framework Appkit

LIBFT = libft/libft.a

LIBMATH = libmath/libmath.a

all : $(NAME)
	@echo "\033[32m◊\033[0m $(NAME) ready"

$(NAME) : $(OBJ) rtv1.h
	make -C libft/
	make -C libmath/
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(SRC) $(LIBFT) $(LIBMATH) -o $(NAME) -g

clean :
	make clean -C libft/
	make clean -C libmath/
	rm -f $(OBJ)

fclean : clean
	make fclean -C libft/
	make fclean -C libmath/
	rm -f $(NAME)

re : fclean all
