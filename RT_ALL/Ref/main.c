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

static int	get_color(t_coord color)
{
	return (((int)color.x << 16) + ((int)color.y << 8) + (int)color.z);
}

void	rtv1(t_env *e, t_scene *s)
{
	int		i;
	int		j;
	t_coord	pinhole;
	t_ray	ray;

	j = -1;
	while (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
		{
			pinhole = get_pinhole(s->cam, i, j);
			ray = compute_ray(s->cam.pos, pinhole);
			e->add[i + j * (int)WIDTH] = get_color(solve(ray, s));
		}
	}
}

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
