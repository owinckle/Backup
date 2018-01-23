NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCS = srcs/main.c

OBJS = $(SRCS:.c=.o)

INC = -I includes/

HDIR = includes/libftprintf.h

all: $(NAME)

$(NAME): $(OBJS) $(HDIR)
		@ar rc $@ $^
		@ranlib $(NAME)

%.o: %.c $(HDIR)
		@gcc $(FLAGS) $(INC) -o $@ -c $<
	 

clean:
		@rm -rf $(OBJS)

fclean: clean
		@rm -rf $(NAME)

re: fclean all