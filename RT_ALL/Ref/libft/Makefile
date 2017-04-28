# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/07 14:41:20 by dbirtel           #+#    #+#              #
#    Updated: 2017/03/30 00:45:19 by dbirtel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
	  ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c\
	  ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c\
	  ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c\
	  ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c\
	  ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c\
	  ft_striteri.c ft_strjoin.c ft_strlen.c ft_strmap.c ft_strmapi.c\
	  ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c\
	  ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c\
	  ft_strtrim.c ft_tolower.c ft_toupper.c ft_strlcat.c ft_intlen.c\
	  ft_isspace.c ft_lstadd.c ft_lstnew.c ft_lstdel.c ft_lstdelone.c\
	  ft_lstiter.c ft_lstpushback.c ft_lstmap.c ft_trimc.c ft_lstaffstr.c\
	  ft_pow.c ft_strtolower.c ft_strtoupper.c ft_strndup.c ft_strjoinc.c\
	  get_next_line.c ft_atof.c

OBJ = $(SRC:.c=.o)

CC = clang

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)
	@echo "\033[32m◊\033[0m libft ready"

$(NAME) : $(OBJ) libft.h
		$(CC) $(CFLAGS) -c $(SRC)
		ar rc $(NAME) $(OBJ)

clean :
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean all
