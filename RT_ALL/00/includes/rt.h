#ifndef RT_H
# define RT_H


# include <stdio.h>

# include <math.h>
# include <mlx.h>
# include <pthread.h>
# include "libft.h"

# define THREAD		5
# define MAX_X		500
# define MAX_Y		500
# define VP_WIDTH	1.0
# define VP_HEIGHT	1.0
# define VP_DIST	1.0
# define MAX_INTER	42000


/*
# define EXIT		65307
# define ZERO		119
# define UN		115
# define DEUX		97
# define TROIS		100
# define QUATRE		113
# define CINQ		101
# define SIX		65361
# define SEPT		65363
# define HUIT		65364
# define NEUF		65362
# define DIX		65456
# define ONZE		32
# define FAUCON		65505
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

typedef struct		s_obj
{
	char			*name;
	float			*ori;
	float			rad;
	float			*axe;
	int				color;
	struct	s_obj	*next;
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
	int				debug;
}					t_env;

typedef struct		s_th_tab
{
	t_env			*e;
	int				i;
}					t_th_tab;

// vect_and_mat
float	*vect_sum(float *sum, float *u, float *v);
float	*vect_sub(float *sub, float *u, float *v);
float	*vect_multi(float *multi, float k, float *u);
float	*vect_prod(float *prod, float *u, float *v);
float	dot_prod(float *u, float *v);
float	*vect_set(float *dst, float a, float b, float c);
float	*vect_copy(float *dst, float *src);
float	ft_dist(float *a, float *b);
float	*ft_norme(float *v);
float	*mat_prod(float *mp, float **mat, float *src);
int	rot(float *ez, float value, float *n);

//setting
void	cam_init(t_env *e, float *pos, float *dir);
void	ray_set(t_cam *c);
void	cam_set(t_env *e);
void	plan_set(t_env *e, float *pos, float *nor, int color);
void	sphere_set(t_env *e, float *pos, float rayon, int color);

//intersection

void			inter(t_env *e, int i, t_obj *node);
void			plan_inter(t_env *e, int i, t_obj *node);
void			sphere_inter(t_env *e, int i, t_obj *node);

//pixel

void	clear(t_env *e);
void	rt(t_env *e);

//mlx_stuff

t_env	*env_init(void);
int	expose(t_env *e);
int	key_press(int keycode, t_env *e);
int	key(int keycode, t_env *e);
int	loop_hook(t_env *e);
void	loop(t_env *e);

#endif
