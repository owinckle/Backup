/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 16:03:16 by owinckle          #+#    #+#             */
/*   Updated: 2016/03/31 16:03:16 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_fractal(t_env env, int x, int y)
{
	if (env.type == 1)
		return (mandelbrot(env, x, y));
	if (env.type == 2)
		return (julia(env, x, y));
	if (env.type == 3)
		return (burning_ship(env, x, y));
	else
		return (0);
}

int		ft_draw_fract(t_env env)
{
	int					clr;
	int					px;
	register int		x;
	register int		y;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			px = ft_fractal(env, x, y);
			clr = clr_get(px, env);
			pixel_put(env, x, y, clr);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env.mlx, env.win, env.img.ptr, 0, 0);
	return (0);
}
