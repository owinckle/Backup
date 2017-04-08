# include "rt.h"

void	clear(t_env *e)
{
	int	i;

	i = -1;
	while (++i < MAX_X * MAX_Y)
	{
		*((int *)e->data_img + i) = 0;
		e->c->inter[i] = MAX_INTER;
		e->c->obj[i] = NULL;
	}
}
