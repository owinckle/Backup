# include "rt.h"

void	rt(t_env *e)
{
	int	i;

	i = -1;
	while (++i < MAX_X * MAX_Y)
	{
		inter(e, i);
		if (e->c->obj[i])
			*((int *)e->data_img + i) = e->c->obj[i]->color;
	}
}
