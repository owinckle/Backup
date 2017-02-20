/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:30:44 by owinckle          #+#    #+#             */
/*   Updated: 2017/02/20 14:30:45 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// static void		mlx_put_pxl(int x, int y, int color, t_env *e)
// {
// 	unsigned int	new_color;
// 	int				i;

// 	new_color = mlx_get_color_value(e->mlx.mlx, color);
// 	i = x * 4 + y * e->mlx.sl;
// 	e->mlx.pxl[i] = (new_color & 0xFF);
// 	e->mlx.pxl[i + 1] = (new_color & 0xFF00) >> 8;
// 	e->mlx.pxl[i + 2] = (new_color & 0xFF0000) >> 16;
// }

static void		set_ray(t_th *th, double x, double y)
{
	double		xx;
	double		yy;

	xx = (WIDTH - x * 2) / HEIGHT;
	yy = (HEIGHT - y * 2) / WIDTH;
	THK = v_sub(&th->cam_dir, &th->cam_pos);
	v_norm(&THK);
	THI = v_cross(&THK, &((t_vect){0, 1, 0}));
	v_norm(&THI);
	THJ = v_cross(&THI, &THK);
	th->ray_dir = (t_vect){
		xx * THI.x + yy * THJ.x + 2 * THK.x,
		xx * THI.y + yy * THJ.y + 2 * THK.y,
		xx * THI.z + yy * THJ.z + 2 * THK.z
	};
	v_norm(&th->ray_dir);
}

static void		raytracing(t_th *th, t_obj *node, double x, double y)
{
	t_obj			*tmp;
	float			*tab;
	float			rgb[3];
	double			p;

	(void)node;
	(void)tmp;
	if (!(tab = (float*)malloc(sizeof(float) * 4)))
		ft_error(MALLOC);
	fzero(rgb, 3);
	p = 0;
	set_ray(th, x, y);
	if ((tmp = inter(th, node, th->ray_dir, th->cam_pos)))
	// 			tab = lambert(th, tmp, th->light, tab);
	free(tab);
}

static void		*processing(void *arg)
{
	t_th_tab		*tab;
	t_th			*th;
	t_obj			*node;
	double			x;
	double			y;

	tab = (t_th_tab*)arg;
	node = tab->e->obj;
	th = init_thread(tab->e);
	y = 0;
	while (y < HEIGHT)
	{
		x = WIDTH * tab->i / THREAD;
		while (x < WIDTH * (tab->i + 1) / THREAD)
		{
			raytracing(th, node, x++, y);
			x++;
		}
		y++;
	}
	free_lists(th->light, th->obj);
	free(th);
	pthread_exit(0);
}

void			draw(t_env *e)
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
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img, 0, 0);
}
