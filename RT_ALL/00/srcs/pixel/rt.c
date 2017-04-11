# include "rt.h"

static void	*processing(void *arg)
{
	t_th_tab		*tab;
	int				i;
	t_obj			*node;

	tab = (t_th_tab*)arg;
	node = tab->e->o;
	i = MAX_X * tab->i / THREAD;
	while (i < MAX_X * (tab->i * MAX_X + MAX_X) / THREAD)
	{
		inter(tab->e, i, node);
		if (tab->e->c->obj[i])
			*((int *)tab->e->data_img + i) = tab->e->c->obj[i]->color;
		i++;
	}
	pthread_exit(0);
}

void		rt(t_env *e)
{
	pthread_t		th[THREAD];
	t_th_tab		tab[THREAD];
	void			*ret;
	int				i;

	i = -1;
	while (++i < THREAD)
	{
		tab[i].i = i;
		tab[i].e = e;
		pthread_create(&th[i], NULL, processing, &tab[i]);
	}
	i = -1;
	while (++i < THREAD)
		(void)pthread_join(th[i], &ret);
}
