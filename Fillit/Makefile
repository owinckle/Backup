# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: owinckle <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/03 11:19:38 by owinckle          #+#    #+#              #
#    Updated: 2016/02/06 16:41:12 by opichou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

FLAGS = -Wall -Wextra -Werror

IDIR = inc

SRCS = $(addprefix $(SDIR)/, $(SRC_FILES))

SDIR = srcs

LDIR = Libft

LIB = -L$(LDIR) -lft

INC = -I$(IDIR)

# COLORS
C_NO = "\033[00m"
C_OK = "\033[35m"
C_GOOD = "\033[32m"
C_ERROR = "\033[31m"
C_WARN = "\033[33m"

# MESSAGE
SUCCESS = $(C_GOOD)[SUCCESS]$(C_NO)
OK = $(C_OK)OK$(C_NO)
PROG = $(C_WARN)$(NAME)
COMPILED = $(C_WARN)Compiling $(NAME) - $(SUCCESS)$(C_NO)
CLEAN = $(C_ERROR)Removing all $(C_WARN).o $(C_ERROR)files - $(SUCCESS)$(C_NO)
FCLEAN = $(C_ERROR)Removing $(C_WARN)$(NAME) $(C_ERROR)- $(SUCCESS)$(C_NO)
RESET = $(C_OK)Reset...$(C_NO)

SRC_FILES = main.c \
			filecheck.c \
			error.c \
			functions.c \
			optimize.c \
			fillit_testing.c \
			print.c \
			ft_orgn.c \
			ft_pos.c \
			ft_cgt_bases.c

OBJS = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): lib
		@$(CC) -c $(FLAGS) $(SRCS) $(INC)
		@$(CC) $(FLAGS) $(OBJS) $(LIB) $(INC) -o $(NAME)
		@echo $(COMPILED)

lib:
		@make -C $(LDIR)
		@make clean -C $(LDIR)

clean:
		@rm -rf $(OBJS)
		@echo $(CLEAN)

fclean: clean
		@make fclean -C $(LDIR)
		@rm -rf $(NAME)
		@echo $(FCLEAN)

rmsg:
		@echo $(RESET)

re: rmsg fclean all
		@echo $(C_OK)Reset complete$(C_NO)

.PHONY: all clean fclean re
