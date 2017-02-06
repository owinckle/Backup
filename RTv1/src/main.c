/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:02:58 by owinckle          #+#    #+#             */
/*   Updated: 2016/12/23 15:02:59 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int		ft_red(t_env *e)
{
	mlx_destroy_window(e->mlx.mlx, e->mlx.win);
	ft_bs(9, "\x1b[33m[TERMINATED]", 1);
	exit(0);
}

static void		init_mlx(t_env *e)
{
	e->mlx.mlx = mlx_init();
	e->mlx.img = mlx_new_image(e->mlx.mlx, e->width, e->height);
	e->mlx.pxl = mlx_get_data_addr(e->mlx.img, &e->mlx.bpp,
		&e->mlx.sl, &e->mlx.ed);
}

static void		init_scene(t_env *e)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(e->fd, &line)) > 0 && ft_strcmp("END", line))
	{
		free(line);
		if (!ft_strcmp("camera:", line))
			e->scene.cam = get_cam(e->fd, NULL, NULL);
		if (!ft_strcmp("spheres:", line))
			e->scene.spheres = get_spheres(e->fd, &e->scene);
		if (!ft_strcmp("cylinders:", line))
			e->scene.cyls = get_cylinders(e->fd, &e->scene);
		if (!ft_strcmp("planes:", line))
			e->scene.planes = get_planes(e->fd, &e->scene);
		if (!ft_strcmp("cones:", line))
			e->scene.cones = get_cones(e->fd, &e->scene);
		if (!ft_strcmp("spot:", line))
			e->scene.spot = get_spot(e->fd);
	}
	free(line);
	if (ret == -1)
		ft_error(4);
}

static t_env	*init_env(char *scene)
{
	t_env	*e;

	e = (t_env*)malloc(sizeof(t_env));
	if (e == NULL)
		ft_error(2);
	e->file = scene;
	e->fd = open_file(e->file);
	e->width = WIDTH;
	e->height = HEIGHT;
	init_mlx(e);
	init_scene(e);
	return (e);
}

int				main(int ac, char **av)
{
	t_env *env;

	if (ac != 2)
		ft_error(1);
	env = init_env(av[1]);
	ft_putstr("\x1b[36mStatus : [  ");
	ft_draw(env);
	env->mlx.win = mlx_new_window(env->mlx.mlx, WIDTH, HEIGHT,
			"RTv1");
	mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, env->mlx.img, 0, 0);
	mlx_key_hook(env->mlx.win, key_press, env);
	mlx_hook(env->mlx.win, 17, 0, ft_red, env);
	mlx_loop(env->mlx.mlx);
	return (0);
}
