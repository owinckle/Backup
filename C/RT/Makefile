CC = gcc
NAME = rt
FLAGS = -Wall -Wextra -Werror -ggdb
SRC = srcs/main.c\
	srcs/parsing/parsing.c\
	srcs/parsing/tools.c\
	srcs/parsing/cam_init.c\
	srcs/parsing/new_obj.c\
	srcs/parsing/plan_set.c\
	srcs/parsing/sphere_set.c\
	srcs/parsing/cyl_set.c\
	srcs/parsing/cone_set.c\
	srcs/parsing/light_set.c\
	srcs/parsing/add_neg_obj.c\
	srcs/parsing/lim_set.c\
	srcs/parsing/motion_blur_set.c\
	srcs/texture/load_png.c\
	srcs/texture/tex.c\
	srcs/texture/plan_tex.c\
	srcs/texture/sphere_tex.c\
	srcs/texture/cone_tex.c\
	srcs/texture/cyl_tex.c\
	srcs/mlx_stuff/env_init.c\
	srcs/mlx_stuff/loop.c\
	srcs/mlx_stuff/hook_func.c\
	srcs/mlx_stuff/real_time.c\
	srcs/mlx_stuff/solar_sys.c\
	srcs/intersection/inter.c\
	srcs/intersection/antialiasing.c\
	srcs/intersection/motion_blur.c\
	srcs/intersection/plan_inter.c\
	srcs/intersection/sphere_inter.c\
	srcs/intersection/limit.c\
	srcs/intersection/misc.c\
	srcs/intersection/hit_void.c\
	srcs/intersection/cyl_inter.c\
	srcs/intersection/cone_inter.c\
	srcs/vect_and_mat/mat_ope.c\
	srcs/vect_and_mat/vect_ope.c\
	srcs/vect_and_mat/vect_tools.c\
	srcs/vect_and_mat/var_init.c\
	srcs/vect_and_mat/compute.c\
	srcs/vect_and_mat/normal.c\
	srcs/pixel/rt.c\
	srcs/pixel/recursive.c\
	srcs/pixel/inv_col.c\
	srcs/pixel/color.c\
	srcs/pixel/color_bis.c\
	srcs/pixel/sinus.c\
	srcs/pixel/damier.c\
	srcs/parsing/cube_set.c\
	srcs/pixel/cartoon.c\
	srcs/pixel/output.c
	
OBJ = $(SRC:.c=.o)

INCL = -I includes/ -I /usr/local/include -I ./ -I /usr/local/PAMP/libpng-1.6.19/include -I libmath
LIB = -L libft/ -lft -L libmath -lmath -L /usr/local/lib -lmlx -lxml2 -framework OpenGL -framework AppKit -L /usr/local/PAMP/libpng-1.6.19/lib -lpng

all : $(NAME)

$(NAME) : ./libft/libft.a ./libmath/libmath.a $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(INCL) $(LIB) -O3

./libft/libft.a : 
	make -C libft/

./libmath/libmath.a :
	make -C libmath

%.o : %.c
	$(CC) -o $@ -c $< $(FLAGS) $(INCL) -O3

clean : 
	rm -f $(OBJ)
	make -C libft/ fclean
	make -C libmath/ fclean

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)
