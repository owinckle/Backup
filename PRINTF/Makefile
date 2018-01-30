GCC = gcc

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

DIR_S = sources

DIR_O = temporary

HEADER = includes

SOURCES = ft_printf.c \
		fonctions2.c \
		functions.c \
		handlers_nb.c \
		handlers_str.c \
		handlers_pt.c \
		parsing.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temporary
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $OBJS
	@rm -rf $(DIR_O)

fclean: clean
	@rm -rf $(NAME)

re: clean fclean all