OBJ_DIR		=	obj/

NAME1		=	Colleen
NAME2		=	Grace
NAME3		=	Sully

CC			=	clang
CFLAGS		=	-Wall -Werror -Wextra

SRC1		=	$(NAME1).c
SRC2		=	$(NAME2).c
SRC3		=	$(NAME3).c
OBJ1		=	$(addprefix $(OBJ_DIR), $(SRC1:.c=.o))
OBJ2		=	$(addprefix $(OBJ_DIR), $(SRC2:.c=.o))
OBJ3		=	$(addprefix $(OBJ_DIR), $(SRC3:.c=.o))

all: $(NAME1) $(NAME2) $(NAME3)

$(NAME1): $(OBJ1)
	$(CC) $(CFLAGS) -o $(NAME1) $^
	@echo "\033[32m•\033[0m $(NAME1) is ready."

$(NAME2): $(OBJ2)
	$(CC) $(CFLAGS) -o $(NAME2) $^
	@echo "\033[32m•\033[0m $(NAME2) is ready."

$(NAME3): $(OBJ3)
	$(CC) $(CFLAGS) -o $(NAME3) $^
	@echo "\033[32m•\033[0m $(NAME3) is ready."

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME1) $(NAME2) $(NAME3)

re: fclean all

.PHONY: all re fclean clean
