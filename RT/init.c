/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 23:04:20 by dbirtel           #+#    #+#             */
/*   Updated: 2017/04/10 09:37:01 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_env(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Rt_v1");
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->add = (int *)mlx_get_data_addr(e->img, &e->e, &e->s, &e->l);
}

void	init_scene(char *path, t_scene *s)
{
	int		gnl;
	int		count;
	int		balise;
	int		fd;
	char	*line;

	balise = B_VOID;
	count = 0;
	s->spots = NULL;
	s->obj = NULL;
	fd = open(path, O_RDONLY);
	is_fd_valid(fd);
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		++count;
		if (ft_strlen(line))
			check_valid(line, &balise, count, s);
		free(line);
	}
	close(fd);
	if (gnl == -1)
		error(ERR_DIR);
}
