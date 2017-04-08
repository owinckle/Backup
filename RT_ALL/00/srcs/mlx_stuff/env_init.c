# include "rt.h"

t_env		*env_init(void)
{
	t_env	*e;
	int	info[3];
	int	i;

	e = (t_env *)malloc(sizeof(t_env));
	e->ptr = mlx_init();
	e->win = mlx_new_window(e->ptr, MAX_X, MAX_Y, "RT");
	e->img = mlx_new_image(e->ptr, MAX_X, MAX_Y);
	e->data_img = mlx_get_data_addr(e->img, info, info + 1, info + 2);
	e->c = NULL;
	e->o = NULL;
	e->debug = 1;
	i = -1;
	while (++i < 12)
		e->move[i] = 0;
	e->move[12] = 1;
	return (e);
}
