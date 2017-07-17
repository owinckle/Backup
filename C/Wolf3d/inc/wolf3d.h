/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 13:39:26 by owinckle          #+#    #+#             */
/*   Updated: 2016/09/26 17:11:33 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include "get_next_line.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include <stdio.h>

# define WIDTH 1000
# define HEIGHT 800

# define KEY_UP 13
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_DOWN 1
# define KEY_JUMP 49
# define KEY_ESC 53
# define KEY_FOG 113
# define KEY_NO_FOG 105
# define KEY_FOG_UP 116
# define KEY_FOG_DN 121
# define KEY_SP_UP 24
# define KEY_SP_DN 27
# define MWU 5
# define MWD 4
# define ROTATE_UP 124
# define ROTATE_DN 123
# define RESET 36

# define KEY_PRESS_MASK (1L<<0)
# define KEY_PRESS 2

typedef struct		s_ixy
{
	int				x;
	int				y;
}					t_ixy;

typedef struct		s_dxy
{
	double			x;
	double			y;
}					t_dxy;

typedef struct		s_player
{
	struct s_dxy	pos;
	struct s_dxy	dir;
	struct s_dxy	plane;
	double			speed_turn;
	double			speed_move;
	int				z;
	char			is_jump;
	char			move_left;
	char			move_right;
	char			move_up;
	char			move_down;
	char			move_jump;
}					t_player;

typedef struct		s_ray
{
	struct s_dxy	pos;
	struct s_dxy	dir;
	struct s_ixy	map;
	struct s_dxy	side;
	struct s_dxy	delta;
	struct s_ixy	step;
	double			dist;
	double			cam;
	int				hit;
	int				hit_side;
}					t_ray;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*pxl;
	int				bpp;
	int				s_line;
	int				ed;
	clock_t			last_frame;
	clock_t			next_frame;
}					t_mlx;

typedef struct		s_env
{
	struct s_mlx	mlx;
	struct s_player	player;
	struct s_ray	ray;
	int				height;
	int				width;
	int				**map;
	int				map_width;
	int				map_height;
	unsigned int	color_1;
	unsigned int	color_2;
	unsigned int	color_3;
	unsigned int	color_4;
	unsigned int	color_sky;
	unsigned int	color_ground;
	int				start_x;
	int				start_y;
	int				smog;
	int				smog_freq;
}					t_env;

t_env				*reset(t_env *e);
int					mouse_hook(int button, int x, int y, t_env *env);
int					loop_hook(t_env *e);
int					open_file(t_env *e, char *f);
int					key_press(int k, t_env *e);
int					key_release(int k, t_env *e);
t_env				*init_env(void);
void				draw_line(t_env *e, int x, int start, int end);
void				raycasting(t_env *e);
void				move_left(t_env *e);
void				move_right(t_env *e);
void				move_up(t_env *e);
void				move_down(t_env *e);
void				move_jump(t_env *e);
void				error_map(void);
void				error_arg(void);
void				error_malloc(void);
void				aux(t_env *e);

#endif
