#ifndef RT_H
# define RT_H


# include <stdio.h>

# include <math.h>
# include <mlx.h>
# include "libft.h"
# include <fcntl.h>

/*
** ERRORS
*/
# define ARG		1
# define MALLOC		2
# define FILE		3
# define DATA		4

/*
** DATA
*/
# define THREAD		5

/*
** ALIASES
*/
# define CAMX		e->cam_pos.x
# define CAMY		e->cam_pos.y
# define CAMZ		e->cam_pos.z
# define CAMDX		e->cam_dir.x
# define CAMDY		e->cam_dir.y
# define CAMDZ		e->cam_dir.z
# define LIGHT		e->lighting

# define MAX_X		500
# define MAX_Y		500
# define VP_WIDTH	1.0
# define VP_HEIGHT	1.0
# define VP_DIST	1.0
# define MAX_INTER	42000

/*
** KEYCODES
*/
# define EXIT		53
# define ZERO		13
# define UN			1
# define DEUX		0
# define TROIS		2
# define QUATRE		12
# define CINQ		14
# define SIX		123
# define SEPT		124
# define HUIT		125
# define NEUF		126
# define DIX		82
# define ONZE		49
# define FAUCON		257
# define PAS		3
# define MILLENIUM	10

# define ROT		M_PI / 25

typedef struct		s_vect
{
	float			x;
	float			y;
	float			z;
}					t_vect;

typedef	struct		s_color
{
	float			red;
	float			green;
	float			blue;
}					t_color;

typedef struct		s_obj
{
	char			*name;
	float			*ori;
	float			rad;
	float			*axe;
	int				color;
	struct	s_obj	*next;

	t_vect			rot;
	t_color			col;
	float			shine;
	float			reflection;
	float			negative;
	float			cel_shading;
	float			transparent;
	t_vect			pos;
	int				type;
	float			size;

}					t_obj;

typedef struct		s_cam
{
	float			*pos;
	float			**base;
	float			**ray;
	float			*inter;
	t_obj			**obj;
}					t_cam;

typedef struct		s_env
{
	void			*ptr;
	void			*win;
	void			*img;
	char			*data_img;
	t_cam			*c;
	t_obj			*o;
	char			move[13];

	t_obj			*obj;
	float			lighting;
	float			antialiasing;
	char			**scene;
	char			*file;
	int				lc;
	t_obj			*l;
	t_vect			cam_pos;
	t_vect			cam_dir;

}					t_env;

typedef struct		s_th_tab
{
	t_env			*e;
	int				i;
}					t_th_tab;


// vect_and_mat
float			*vect_sum(float *sum, float *u, float *v);
float			*vect_sub(float *sub, float *u, float *v);
float			*vect_multi(float *multi, float k, float *u);
float			*vect_prod(float *prod, float *u, float *v);
float			dot_prod(float *u, float *v);
float			*vect_set(float *dst, float a, float b, float c);
float			*vect_copy(float *dst, float *src);
float			ft_dist(float *a, float *b);
float			*ft_norme(float *v);
float			*mat_prod(float *mp, float **mat, float *src);
int				rot(float *ez, float value, float *n);

//setting
void			cam_init(t_env *e, float *pos, float *dir);
void			ray_set(t_cam *c);
void			cam_set(t_env *e);
void			plan_set(t_env *e, float *pos, float *nor, int color);
void			sphere_set(t_env *e, float *pos, float rayon, int color);

//intersection

void			inter(t_env *e, int i);
void			plan_inter(t_env *e, int i);
void			sphere_inter(t_env *e, int i);

//pixel

void			clear(t_env *e);
void			rt(t_env *e);

//mlx_stuff

t_env			*env_init(char *file);
int				expose(t_env *e);
int				key_press(int keycode, t_env *e);
int				key(int keycode, t_env *e);
int				loop_hook(t_env *e);
void			loop(t_env *e);

//utils
void			ft_error(int error);
int				open_file(char *file);
int				linelen(char *buf, int k);

//parsing
t_env			*parse(t_env *e);
void			parse_options(t_env *e);
t_obj			*parse_effects(t_obj *link, int j, int i, t_env *e);
t_env			*add_light(t_env *e, int *j, int i);
t_env			*add_cyclone(t_env *e, int *j, int i, int t);
t_env			*add_plane(t_env *e, int *j, int i);
t_env			*add_sphere(t_env *e, int *j, int i);
t_obj			*add_link(t_env *e, t_obj *link, int type);

#endif
