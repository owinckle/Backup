/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 08:20:10 by owinckle          #+#    #+#             */
/*   Updated: 2016/10/28 08:20:10 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_camera	*new_cam(t_vect *pos, t_vect *dir, t_vect *r, t_vect *d)
{
	t_camera	*new;

	new = (t_camera*)malloc(sizeof(t_camera));
	if (new == NULL)
		ft_error(2);
	new->pos = pos;
	new->dir = dir;
	new->right = r;
	new->down = d;
	return (new);
}

t_camera		*get_cam(int fd, t_vect *look_at, t_vect *diff)
{
	char		*line;
	int			ret;
	t_vect		*pos;
	t_vect		*dir;
	t_vect		*r;

	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp("----", line))
	{
		free(line);
		if (!ft_strcmp("pos:", line))
			pos = get_vector(fd);
		if (!ft_strcmp("dir:", line))
			look_at = get_vector(fd);
	}
	free(line);
	if (ret == -1)
		ft_error(4);
	diff = new_vector(pos->x - look_at->x,
			pos->y - look_at->y,
			pos->z - look_at->z);
	dir = normalize(negative(diff));
	r = normalize(cross_product(new_vector(0, 1, 0), dir));
	free(diff);
	free(look_at);
	return (new_cam(pos, dir, r, cross_product(r, dir)));
}
