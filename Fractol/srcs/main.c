/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 13:32:54 by owinckle          #+#    #+#             */
/*   Updated: 2016/03/29 13:32:55 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_env	env;

	if (ac != 2)
		ft_error(USAGE);
	env = ft_init_env(av[1]);
	ft_draw_fract(env);
	ft_display_menu();
	mlx_key_hook(env.win, ft_keyhook, &env);
	mlx_mouse_hook(env.win, ft_mousehook, &env);
	mlx_hook(env.win, 6, 1L << 6, ft_motionhook, &env);
	mlx_loop(env.mlx);
}
