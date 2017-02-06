/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 13:29:22 by owinckle          #+#    #+#             */
/*   Updated: 2016/09/26 17:13:10 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			aux(t_env *e)
{
	int c;

	c = (e->smog_freq > 10) ? 0x000000 : 0xffffff;
	mlx_string_put(e->mlx.mlx, e->mlx.win, 3, 3, c,
		ft_strjoin(ft_itoa(e->player.speed_move * 100), " km/h"));
	mlx_string_put(e->mlx.mlx, e->mlx.win, 860, 3, c,
		"Speed : Wheel");
}

int				ft_red(t_env *e)
{
	mlx_destroy_window(e->mlx.mlx, e->mlx.win);
	exit(0);
}

int				main(int argc, char **argv)
{
	t_env	*env;

	env = init_env();
	if (argc != 2)
		error_arg();
	if (open_file(env, argv[1]) == 0)
		error_map();
	env->mlx.win = mlx_new_window(env->mlx.mlx, WIDTH, HEIGHT,
			"Wolf3d");
	mlx_do_key_autorepeatoff(env->mlx.mlx);
	mlx_loop_hook(env->mlx.mlx, loop_hook, env);
	mlx_hook(env->mlx.win, KEY_PRESS, KEY_PRESS_MASK, key_press, env);
	mlx_hook(env->mlx.win, 17, 0, ft_red, env);
	mlx_key_hook(env->mlx.win, key_press, env);
	mlx_mouse_hook(env->mlx.win, mouse_hook, env);
	mlx_loop(env->mlx.mlx);
	return (0);
}
