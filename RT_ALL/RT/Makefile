# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: owinckle <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/27 13:46:00 by owinckle          #+#    #+#              #
#    Updated: 2016/05/27 13:46:01 by owinckle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rt

CC = gcc

FLAGS = -Wall -Wextra -Werror

IDIR = inc

SDIR = srcs

LDIR = libft

LIB = -L$(LDIR) -lft -L /usr/local/lib

MLX = -lmlx -framework OpenGL -framework Appkit -lpthread

INC = -I$(IDIR) -I /usr/local/include

# COLORS
C_NO = "\033[00m"
C_OK = "\033[35m"
C_GOOD = "\033[32m"
C_ERROR = "\033[31m"
C_WARN = "\033[33m"

# MESSAGE
SUCCESS = $(C_GOOD)[SUCCESS]$(C_NO)
PROG = $(C_WARN)$(NAME)$(C_NO)
COMPILED = $(C_ERROR)Compiling $(C_WARN)$(NAME) $(C_ERROR)- $(SUCCESS)$(C_NO)
CLEAN = $(C_ERROR)Removing all $(C_WARN).o $(C_ERROR)files - $(SUCCESS)$(C_NO)
FCLEAN = $(C_ERROR)Removing $(C_WARN)$(NAME) $(C_ERROR)- $(SUCCESS)$(_NO)
RESET = $(C_OK)Reset...$(C_NO)
RESET_COMPLETE = $(C_OK)Reset complete$(C_NO)

SRC_FILES = main.c \
			parsing/objects.c \
			parsing/options.c \
			parsing/parse.c \
			utils/error.c \
			utils/utils.c

SRC_FILES_O = main.c \
			objects.c \
			options.c \
			parse.c \
			error.c \
			utils.c

SRCS = $(addprefix $(SDIR)/, $(SRC_FILES))

OBJS = $(SRC_FILES_O:.c=.o)

all: $(NAME)

$(NAME) :
		@make -C $(LDIR)
		@make -C $(LDIR) clean
		@$(CC) -c $(FLAGS) $(SRCS) $(INC)
		@$(CC) $(FLAGS) $(OBJS) $(LIB) $(INC) $(MLX) -o $(NAME)
		@echo $(COMPILED)

clean:
		@rm -rf $(OBJS)
		@echo $(CLEAN)

fclean: clean
		@make -C $(LDIR) fclean
		@rm -rf $(NAME)
		@echo $(FCLEAN)

rmsg:
		@echo $(RESET)

re: rmsg fclean all
	@echo $(RESET_COMPLETE)

.PHONY: all clean fclean re lib
