/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 15:37:28 by owinckle          #+#    #+#             */
/*   Updated: 2016/03/28 15:37:45 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH				1600
# define HEIGHT				900
# define NO_DATA			"No data found."
# define USAGE				"Usage : ./fdf <file_name>"
# define SEVEN_ROTATE_LEFT	89
# define NINE_ROTATE_RIGHT	92
# define FOUR_LOW			86
# define SIX_HIGH			88
# define OUT_ZOOM			78
# define IN_ZOOM			69
# define UP_KEY				126
# define DOWN_KEY			125
# define RIGHT_KEY			124
# define LEFT_KEY			123
# define T_THEME			17
# define P_PROJECT			35
# define F_WIRES			3
# define ESC_KEY			53
# define NO_FILE			"No file "
# define W_KEY				13
# define A_KEY				0
# define S_KEY				1
# define D_KEY			2

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"

typedef struct		s_img
{
	void			*img_ptr;
	char			*img;
	int				bpp;
	int				sl;
	int				endian;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				**array;
	int				length;
	int				width;
	double			scale;
	int				z_max;
	int				z_min;
	double			z_mid;
	double			x_offset;
	double			y_offset;
	double			x_origin;
	double			y_origin;
	double			height;
	int				**color;
	int				cnum;
	int				tpro;
	int				wire;
	double			cte1;
	double			cte2;
	double			cte3;
	double			cte4;
	int				x;
	int				y;
	int				z;
	t_img			img;
	double			pasx;
	double			pasy;
	double			pasy1;
	double			pasy2;
	double			pasz;
	double			pasz1;
	double			pasz2;
}					t_env;

typedef struct		s_color
{
	int				color1;
	int				color2;
}					t_color;

typedef struct		s_coord
{
	double			x;
	double			y;
	double			z;
}					t_coord;

typedef struct		s_mcoord
{
	t_coord			p1;
	t_coord			p2;
	t_coord			p3;
	t_coord			p4;
}					t_mcoord;

t_list				*get_lstfile(int fd, int **len);
int					ft_tablen(char **array);
int					**get_array(int fd, int *len, int *width);
int					*put_array(char **line, int **len);
int					*ft_putcolor(int a, int b, int c);
int					**getcolor(char **av, int ac);
int					**ft_tabmalloc(int x, int y);
t_env				*ft_revarray(t_env *e, int sens);
t_coord				get_isometricpoint(int x, int y, int z, t_env *e);
void				isometric(t_env *e);
void				isometricf(t_env *e);
char				*theme(int i);
void				ft_eventkey2(t_env *e, int keycode);
int					ft_eventkey(t_env *e, int keycode);
void				ft_get_img(t_env *e);
t_env				ft_get_min_max(t_env *e);
t_env				ft_abs_array(t_env *e);
t_env				ft_get_env(int length, int width, int **array, int **color);
t_coord				get_parallelpoint(int x, int y, int z, t_env *e);
void				parallel(t_env *e);
void				horline(t_env *e, t_coord *p1, t_coord *p2, int x);
void				pixel_put(t_env *e, int x, int y, int color);
void				fillbottri(t_coord *p1, t_coord *p2, t_coord *p3, t_env *e);
void				draw_triangle(t_coord *p1, t_coord *p2, t_coord *p3,
	t_env *e);
void				filltoptri(t_coord *p1, t_coord *p2, t_coord *p3, t_env *e);
int					ft_find_color(t_color *color, int z, int z_min, int z_max);
int					ft_level(t_env *e, double z);
void				ft_draw_right(t_env *e, t_coord *p1, t_coord *p2);
void				ft_draw_left(t_env *e, t_coord *p1, t_coord *p2);
void				ft_draw_up(t_env *e, t_coord *p1, t_coord *p2);
void				ft_draw_down(t_env *e, t_coord *p1, t_coord *p2);
void				ft_draw(t_env *e, t_coord *p1, t_coord *p2);
void				mlx_fill_image(t_env *e);
void				ft_display_menu(void);
int					ft_expose_hook(t_env *e);
int					ft_key_hook(int keycode, t_env *e);
void				ft_display_tab(int **array, int length, int width,
		int **color);
int					ft_error(char *msg);

#endif
