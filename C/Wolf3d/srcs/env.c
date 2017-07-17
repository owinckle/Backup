/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 13:34:07 by owinckle          #+#    #+#             */
/*   Updated: 2016/05/27 13:34:11 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		init_player(t_env *e)
{
	e->player.pos.x = 0;
	e->player.pos.y = 0;
	e->player.dir.x = -1;
	e->player.dir.y = 0;
	e->player.z = 0;
	e->player.plane.x = 0;
	e->player.plane.y = 0.66;
	e->player.speed_turn = 0.05;
	e->player.speed_move = 0.01;
	e->player.move_up = 0;
	e->player.move_down = 0;
	e->player.move_right = 0;
	e->player.move_left = 0;
	e->player.move_jump = 0;
	e->player.is_jump = 0;
}

static void		init_mlx(t_env *e)
{
	e->mlx.mlx = mlx_init();
	e->mlx.bpp = 0;
	e->mlx.s_line = 0;
	e->mlx.img = mlx_new_image(e->mlx.mlx, WIDTH, HEIGHT);
	e->mlx.pxl = mlx_get_data_addr(e->mlx.img, &(e->mlx.bpp), &(e->mlx.s_line),
			&(e->mlx.ed));
	e->mlx.last_frame = clock();
	e->mlx.next_frame = 0;
}

t_env			*init_env(void)
{
	t_env	*e;

	e = (t_env *)malloc(sizeof(t_env));
	if (e == NULL)
		error_malloc();
	e->width = WIDTH;
	e->height = HEIGHT;
	init_player(e);
	init_mlx(e);
	e->color_1 = 0xff9600;
	e->color_2 = 0x73ff00;
	e->color_3 = 0xff00fc;
	e->color_4 = 0x46fffc;
	e->color_sky = 0x000ccff;
	e->color_ground = 0x5959590;
	e->smog = 1;
	e->smog_freq = 100;
	return (e);
}

t_env			*reset(t_env *e)
{
	e->player.speed_move = 0.05;
	e->player.speed_turn = 0.05;
	e->smog_freq = 100;
	e->smog = 1;
	return (e);
}
