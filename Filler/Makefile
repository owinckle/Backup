CC = gcc
NAME = owinckle.filler
# FLAGS = -Wall -Wextra -Werror -ggdb
SRC = srcs/main.c\
	srcs/assets.c
	
OBJ = $(SRC:.c=.o)

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
