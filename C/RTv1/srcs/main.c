/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:47:38 by owinckle          #+#    #+#             */
/*   Updated: 2017/02/17 11:47:40 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				ft_red(t_env *e)
{
	mlx_destroy_window(e->mlx.mlx, e->mlx.win);
	ft_bs(9, "\x1b[33m[TERMINATED]", 1);
	exit(0);
}

static char		*get_buf(int *lc, int fd)
{
	char		*line;
	char		*buf;

	buf = ft_strnew(1);
	while (get_next_line(fd, &line) > 0 && (*lc)++ > -1)
		buf = ft_strjoint(buf, ft_strjoint(line, "\n", 'L'), 'B');
	if (close(fd) == -1)
		ft_error(FILE);
	free(line);
	return (buf);
}

static char		**get_scene(char *buf, int lc, int j)
{
	int			i;
	int			k;
	char		**scene;

	k = 0;
	if (!buf)
		ft_error(FILE);
	if (!(scene = (char**)malloc(sizeof(char*) * (lc + 1))))
		ft_error(MALLOC);
	while (buf[k] != '\0' && j < lc)
	{
		i = 0;
		if (!(scene[j] = (char*)malloc(sizeof(char) * linelen(buf, k))))
			ft_error(MALLOC);
		while (buf[k] != '\0' && buf[k] != '\n')
			scene[j][i++] = buf[k++];
		scene[j][i] = '\0';
		j++;
		k++;
	}
	free(buf);
	return (scene);
}

static t_env	*init_env(char *file)
{
	t_env		*e;
	char		*buf;

	if (!(e = (t_env*)malloc(sizeof(t_env))))
		ft_error(MALLOC);
	e->width = WIDTH;
	e->height = HEIGHT;
	e->file = file;
	e->fd = open_file(file);
	e->mlx.mlx = mlx_init();
	e->mlx.img = mlx_new_image(e->mlx.mlx, e->width, e->height);
	e->mlx.pxl = mlx_get_data_addr(e->mlx.img, &e->mlx.bpp,
		&e->mlx.sl, &e->mlx.ed);
	e->mlx.win = mlx_new_window(e->mlx.mlx, WIDTH, HEIGHT, "RTv1");
	e->lc = 0;
	buf = get_buf(&(e->lc), e->fd);
	e->scene = get_scene(buf, e->lc, 0);
	e->light = NULL;
	e->obj = NULL;
	e = parse(e);
	return (e);
}

int				main(int ac, char **av)
{
	t_env		*e;

	ft_putstr("\x1b[36mStatus : [  ");
	if (ac != 2)
		ft_error(ARG);
	e = init_env(av[1]);
	if (e->obj != NULL && e->light != NULL)
		draw(e);
	ft_bs(3, "\x1b[33m[RUNNING]", 0);
	mlx_key_hook(e->mlx.win, key_hook, e);
	mlx_hook(e->mlx.win, 17, 0, ft_red, e);
	mlx_loop(e->mlx.mlx);
	return (0);
}
