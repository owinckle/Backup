/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 13:51:21 by owinckle          #+#    #+#             */
/*   Updated: 2016/03/28 13:51:25 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_fill_image(t_env *e)
{
	int		x;
	int		y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			pixel_put(e, x, y, 0x000000);
		}
	}
}

void	ft_display_menu(void)
{
	ft_putstr("\
_____________________________________\n\
CONTROLS:\n\
Mouvements:\n\
	Y Object: Arrow: UP, DOWN\n\
	X Object: Arrow: LEFT, RIGHT\n\
	Y View: Keyboard: W, S\n\
	X View: Keyboard: A, D\n\
\n\
Rotation:\n\
	Left: Keypad: 7\n\
	Right: Keypad: 9\n\
\n\
Zoom:\n\
	IN: Keypad: +\n\
	OUT: Keypad: -\n\
\n\
Visual:\n\
	THEME: Keyboard: 'T'\n\
	PROJECTION: Keyboard: 'P'\n\
	WIRES: Keyboard: 'F''\n\
	Z UP: Keypad: 6\n\
	Z DOWN: Keypad: 4\n\
_____________________________________\n\
	\n");
}

int		ft_expose_hook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_fill_image(e);
	if (e->tpro == 0 && e->wire == 0)
		isometric(e);
	else if (e->tpro == 0 && e->wire == 1)
		isometricf(e);
	else if (e->tpro == 1)
		parallel(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img_ptr, 0, 0);
	return (0);
}

int		ft_key_hook(int keycode, t_env *e)
{
	if (keycode == ESC_KEY)
		exit(1);
	else
		ft_eventkey(e, keycode);
	ft_expose_hook(*&e);
	return (0);
}

void	ft_display_tab(int **array, int length, int width, int **color)
{
	t_env	e;

	e = ft_get_env(length, width, array, color);
	mlx_key_hook(e.win, ft_key_hook, &e);
	mlx_expose_hook(e.win, ft_expose_hook, &e);
	ft_display_menu();
	mlx_loop(e.mlx);
}
