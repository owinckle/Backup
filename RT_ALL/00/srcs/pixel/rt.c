# include "rt.h"

static void	*processing(void *arg)
{
	t_th_tab		*tab;
	int				i;

	tab = (t_th_tab*)arg;
	i = MAX_X * tab->i / THREAD;
	// printf("TAB->I = %d and MAX THREAD = %d and I = %d\n", tab->i, MAX_X * (tab->i + 1) / THREAD, MAX_X * tab->i / THREAD);
	while (i < MAX_X * (tab->i + 1) / THREAD)
	{
		inter(tab->e, i);
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

// void	rt(t_env *e)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < MAX_X * MAX_Y)
// 	{
// 		ft_putnbr(i);
// 		ft_putchar('\n');
// 		inter(e, i);
// 		if (e->c->obj[i])
// 			*((int *)e->data_img + i) = e->c->obj[i]->color;
// 	}
// }
