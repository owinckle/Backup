/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 21:40:48 by dbirtel           #+#    #+#             */
/*   Updated: 2017/04/09 14:37:15 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	add_plane(char *line, int count, t_scene *s)
{
	t_ob	*tmp;
	t_ob	*plane;

	count_num(line, 11, count);
	if (!(plane = (t_ob *)malloc(sizeof(t_ob))))
		error(ERR_MALLOC);
	plane->pos = get_coord(line, 0);
	plane->pos = mult_coord(plane->pos, 0.5);
	plane->normal = vec_norm(get_coord(line, 4));
	plane->rot = compute_rot_qt(plane->normal);
	plane->color = get_coord(line, 7);
	plane->type = PLANE;
	plane->num = 0;
	plane->next = NULL;
	plane->spec = (int)get_num(line, 10);
	if (!s->obj)
		s->obj = plane;
	else
	{
		plane->num = s->obj->num + 1;
		tmp = s->obj;
		plane->next = tmp;
		s->obj = plane;
	}
}

double	solve_plane(t_ray ray, t_ob *obj)
{
	double	result;

	result = -((obj->normal.x * (ray.origin.x - obj->pos.x) + \
	obj->normal.y * (ray.origin.y - obj->pos.y) + obj->normal.z * \
	(ray.origin.z - obj->pos.z) + vec_len(obj->pos)) / \
	(obj->normal.x * ray.vector.x + obj->normal.y * \
	ray.vector.y + obj->normal.z * ray.vector.z));
	return (result);
}
