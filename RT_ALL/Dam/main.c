/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 20:40:34 by dbirtel           #+#    #+#             */
/*   Updated: 2017/04/10 09:37:02 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_ob	*th_objects(t_ob *o)
{
	t_ob		*th;

	th = (t_ob*)malloc(sizeof(t_ob));
	th->pos = o->pos;
	th->normal = o->normal;
	th->color = o->color;
	th->rot = o->rot;
	th->spec = o->spec;
	th->radius = o->radius;
	th->alpha = o->alpha;
	th->type = o->type;
	th->num = o->num;
	th->p[0] = (t_coord){0, 0, 0};
	th->p[1] = (t_coord){0, 0, 0};
	return (th);
}

static t_scene	*th_scene(t_scene *s)
{
	t_scene		*th;

	th = (t_scene*)malloc(sizeof(t_scene));
	th->spots = s->spots;
	th->cam = s->cam;
	th->obj = th_objects(s->obj);
	return (th);
}

static void		*processing(void *arg)
{
	t_th_tab	*tab;
	int			y;
	int			x;
	t_scene		*s;

	tab = (t_th_tab*)arg;
	s = th_scene(tab->s);
	y = -1;
	while (++y < HEIGHT)
	{
		x = WIDTH * tab->i / THREAD - 1;
		while (++x < WIDTH * (tab->i + 1) / THREAD)
			tab->e->add[x + y * (int)WIDTH] = solve(compute_ray
				(tab->s->cam.pos, get_pinhole(tab->s->cam, x, y)), s);
	}
	free_scene(s);
	free(s);
	pthread_exit(0);
}

static void		rtv1(t_env *e, t_scene *s)
{
	pthread_t	th[THREAD];
	t_th_tab	tab[THREAD];
	void		*ret;
	int			i;

	i = -1;
	while (++i < THREAD)
	{
		tab[i].i = i;
		tab[i].e = e;
		tab[i].s = s;
		pthread_create(&th[i], NULL, processing, &tab[i]);
	}
	i = -1;
	while (++i < THREAD)
		(void)pthread_join(th[i], &ret);
}

// void	rtv1(t_env *e, t_scene *s)
// {
// 	int		i;
// 	int		j;

// 	j = -1;
// 	while (++j < HEIGHT)
// 	{
// 		i = -1;
// 		while (++i < WIDTH)
// 			e->add[i + j * (int)WIDTH] =
// 		solve(compute_ray(s->cam.pos,get_pinhole(s->cam, i, j)), s);
// 	}
// }

int		main(int ac, char **av)
{
	t_env	e;
	t_scene	s;

	if (ac != 2)
		error(ERR_AC);
	init_scene(av[1], &s);
	init_env(&e);
	rtv1(&e, &s);
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	mlx_hook(e.win, 2, 1L << 0, key_press, &e);
	mlx_hook(e.win, 17, 1L << 17, red_cross, &e);
	mlx_loop(e.mlx);
	return (0);
}
