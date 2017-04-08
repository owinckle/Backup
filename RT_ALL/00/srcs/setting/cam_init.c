#include "rt.h"

static void	cam_init_base(t_cam *c)
{
	if (c->base[2][0] == 0 && c->base[2][1] == 0)
			vect_set(c->base[0], 1, 0, 0);
	else
	{
		vect_set(c->base[0], c->base[2][1], -c->base[2][0], 0);
		ft_norme(c->base[0]);
	}
	vect_prod(c->base[1], c->base[2], c->base[0]);
}


void		cam_init(t_env *e, float *pos, float *dir)
{
	int		i;

	e->c = (t_cam *)malloc(sizeof(t_cam));
	e->c->pos = vect_set(NULL, pos[0], pos[1], pos[2]);
	e->c->base = (float **)malloc(sizeof(float *) * 3);
	i = -1;
	while (++i < 3)
		e->c->base[i] = vect_set(NULL, dir[0], dir[1], dir[2]);
	ft_norme(e->c->base[2]);
	cam_init_base(e->c);
	e->c->ray = (float **)malloc(sizeof(float *) * (MAX_X * MAX_Y));
	i = -1;
	while (++i < MAX_X * MAX_Y)
		e->c->ray[i] = (float *)malloc(sizeof(float) * 3);
	ray_set(e->c);
	e->c->inter = (float *)malloc(sizeof(float) * (MAX_X * MAX_Y));
	e->c->obj = (t_obj **)malloc(sizeof(t_obj *) * (MAX_X * MAX_Y));
}
