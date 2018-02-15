CC = gcc
NAME = owinckle.filler

SRCS := srcs/main.c
SRCS += srcs/parsing.c
SRCS += srcs/assets.c
SRCS += srcs/piece_parsing.c
SRCS += srcs/play.c
SRCS += srcs/s_algo.c
SRCS += srcs/b_algo.c
SRCS += srcs/contact.c

FLAGS = -Wall -Wextra -Werror -ggdb

OBJ = $(SRCS:.c=.o)

INCL = -I includes/
LIB = -L libft/ -lft 

all : $(NAME)

$(NAME) : ./libft/libft.a $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(INCL) $(LIB)

./libft/libft.a : 
	make -C libft/

%.o : %.c
	$(CC) -o $@ -c $< $(FLAGS) $(INCL)

clean : 
	rm -f $(OBJ)
	make -C libft/ fclean

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)
