/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 10:53:24 by owinckle          #+#    #+#             */
/*   Updated: 2017/04/03 18:12:22 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libft.h"
# include "get_next_line.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>

# define WIDTH		800
# define HEIGHT		800
# define THREAD		8

# define KEY_ESC	53

# define ARG		1
# define MALLOC		2
# define FILE		3
# define DATA		4

# define CAMX			e->cam_pos.x
# define CAMY			e->cam_pos.y
# define CAMZ			e->cam_pos.z
# define CAMDX			e->cam_dir.x
# define CAMDY			e->cam_dir.y
# define CAMDZ			e->cam_dir.z
# define RAYDX			e->ray_dir.x
# define RAYDY			e->ray_dir.y
# define RAYDZ			e->ray_dir.z

# define TH_CAMX		th->cam_pos.x
# define TH_CAMY		th->cam_pos.y
# define TH_CAMZ		th->cam_pos.z
# define TH_CAMDX		th->cam_dir.x
# define TH_CAMDY		th->cam_dir.y
# define TH_CAMDZ		th->cam_dir.z
# define TH_RAYDX		th->ray_dir.x
# define TH_RAYDY		th->ray_dir.y
# define TH_RAYDZ		th->ray_dir.z

# define THI			th->i
# define THJ			th->j
# define THK			th->k

typedef struct		s_vect
{
	float			x;
	float			y;
	float			z;
}					t_vect;

typedef struct		s_color
{
	float			red;
	float			green;
	float			blue;
}					t_color;

typedef struct		s_obj
{
	int				type;
	float			size;
	t_vect			rot;
	t_vect			pos;
	t_color			color;
	struct s_obj	*next;
}					t_obj;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*pxl;
	int				bpp;
	int				sl;
	int				ed;
}					t_mlx;

typedef struct		s_env
{
	t_mlx			mlx;
	t_obj			*obj;
	t_obj			*light;
	t_vect			cam_pos;
	t_vect			cam_dir;
	char			**scene;
	char			*file;
	int				lc;
	int				fd;
	int				width;
	int				height;
}					t_env;

typedef struct		s_th
{
	t_obj			*obj;
	t_obj			*light;
	t_vect			cam_pos;
	t_vect			cam_dir;
	t_vect			i;
	t_vect			j;
	t_vect			k;
	t_vect			dist;
	t_vect			norm;
	t_vect			ray_dir;
	t_mlx			mlx;
	float			t0;
	float			t1;
	float			t;
	float			a;
	float			b;
	float			c;
}					t_th;

typedef struct		s_th_tab
{
	t_env			*e;
	int				i;
}					t_th_tab;

/*
** draw.
*/
void				draw(t_env *e);

/*
** error.c
*/
void				ft_error(int error);

/*
** functions.c
*/
int					linelen(char *buf, int k);
int					open_file(char *file);
int					key_hook(int k, t_env *e);
void				fzero(float *s, int n);
float				*ft_average(float *r, float *tab);

/*
** inter.c
*/
double				inter_cylinder(t_th *th, t_obj *tmp, t_vect ray,
						t_vect pos);
double				inter_cone(t_th *th, t_obj *tmp, t_vect ray, t_vect pos);
double				inter_sphere(t_th *th, t_obj *tmp, t_vect ray, t_vect pos);
double				inter_plane(t_th *th, t_obj *tmp, t_vect ray, t_vect pos);
t_obj				*inter(t_th *th, t_obj *node, t_vect ray, t_vect pos);

/*
** light.c
*/
float				*lambert(t_th *th, t_obj *tmp, t_obj *light, float *tab);

/*
** main.c
*/
int					ft_red(t_env *e);

/*
** objects.c
*/
t_env				*add_light(t_env *e, int *j, int i);
t_env				*add_cyclone(t_env *e, int *j, int i, int t);
t_env				*add_plane(t_env *e, int *j, int i);
t_env				*add_sphere(t_env *e, int *j, int i);

/*
** parse.c
*/
t_env				*parse(t_env *e);
t_obj				*add_link(t_env *e, t_obj *link, int type);

/*
** thread.c
*/
t_th				*init_thread(t_env *e);
int					free_lists(t_obj *light, t_obj *obj);

/*
** vectors.c
*/
t_vect				v_sub(t_vect *v1, t_vect *v2);
t_vect				v_cross(t_vect *v1, t_vect *v2);
void				v_norm(t_vect *v);
float				v_dot(t_vect *v1, t_vect *v2);
t_vect				v_scale(t_vect *v, float n);

#endif
