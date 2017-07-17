/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 13:32:26 by owinckle          #+#    #+#             */
/*   Updated: 2016/09/26 17:12:12 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_env	*key_move_2(int k, t_env *e)
{
	if (k == KEY_FOG_UP && e->smog_freq > 0 && e->smog == 0)
		e->smog_freq -= 5;
	if (k == KEY_FOG_DN && e->smog_freq < 200 && e->smog == 0)
		e->smog_freq += 5;
	if (k == RESET)
		e = reset(e);
	return (e);
}

void			key_move(int k, t_env *e)
{
	if (k == KEY_UP)
		e->player.move_up = !e->player.move_up;
	if (k == KEY_DOWN)
		e->player.move_down = !e->player.move_down;
	if (k == KEY_LEFT)
		e->player.move_left = !e->player.move_left;
	if (k == KEY_RIGHT)
		e->player.move_right = !e->player.move_right;
	if (k == KEY_JUMP && e->player.move_jump == 0)
		e->player.move_jump = 1;
	if (k == KEY_SP_UP)
		e->player.speed_move += 0.01;
	if (k == KEY_SP_DN && e->player.speed_move > 0.00)
		e->player.speed_move -= 0.01;
	if (k == KEY_NO_FOG)
		e->smog = 1;
	if (k == KEY_FOG)
		e->smog = 0;
	if (k == KEY_ESC)
	{
		mlx_destroy_window(e->mlx.mlx, e->mlx.win);
		exit(0);
	}
	e = key_move_2(k, e);
}

int				key_press(int k, t_env *e)
{
	key_move(k, e);
	return (0);
}

int				loop_hook(t_env *e)
{
	e->mlx.last_frame = clock();
	if (e->mlx.next_frame > e->mlx.last_frame)
		return (0);
	e->mlx.next_frame = e->mlx.last_frame + (CLOCKS_PER_SEC / 100);
	if (e->player.move_up)
		move_up(e);
	if (e->player.move_down)
		move_down(e);
	if (e->player.move_right)
		move_right(e);
	if (e->player.move_left)
		move_left(e);
	if (e->player.move_jump == 1)
		move_jump(e);
	raycasting(e);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img, 0, 0);
	aux(e);
	return (0);
}

int				mouse_hook(int button, int x, int y, t_env *env)
{
	(void)x;
	(void)y;
	if (button == MWD)
		key_move(KEY_SP_UP, env);
	else if (button == MWU)
		key_move(KEY_SP_DN, env);
	return (0);
}
