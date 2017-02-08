/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:07:22 by owinckle          #+#    #+#             */
/*   Updated: 2016/12/05 11:07:23 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_ray		*new_ray(t_vect *og, t_vect *dir)
{
	t_ray	*new;

	new = (t_ray*)malloc(sizeof(t_ray));
	if (new == NULL)
		ft_error(4);
	new->og = og;
	new->dir = dir;
	return (new);
}

t_ray		*get_ray(t_env *e, double x, double y)
{
	t_vect	*v1;
	t_vect	*v2;
	t_ray	*result;

	v1 = vect_mult(e->scene.cam->right, x - 0.5);
	v2 = vect_mult(e->scene.cam->down, y - 0.5);
	v1 = vect_add(v1, v2);
	v1 = vect_add(e->scene.cam->dir, v1);
	v1 = normalize(v1);
	result = new_ray(e->scene.cam->pos, v1);
	return (result);
}

t_inter		*new_inter(t_vect *normal, double dist, t_color *c, t_vect *point)
{
	t_inter		*new;

	new = (t_inter*)malloc(sizeof(t_inter));
	if (new == NULL)
		ft_error(4);
	new->normal = normal;
	new->dist = dist;
	new->color = c;
	new->point = point;
	return (new);
}

t_inter		*find_min_inter(t_inter *i1, t_inter *i2)
{
	if (i2 == NULL)
		return (i1);
	if (i1 == NULL)
		return (i2);
	if ((i2->dist < i1->dist || i1->dist == -1) && i2->dist > ACCURACY)
		return (i2);
	return (i1);
}

t_inter		*calc_inter(t_env *e, t_ray *ray)
{
	t_inter	*min;

	min = new_inter(NULL, -1, NULL, NULL);
	min = find_min_inter(min, spheres_inter(e, ray, e->scene.c_spheres, NULL));
	min = find_min_inter(min, planes_inter(e, ray, e->scene.c_planes, NULL));
	min = find_min_inter(min, cylinders_inter(e, ray, e->scene.c_cyls, NULL));
	min = find_min_inter(min, cones_inter(e, ray, e->scene.c_cones, NULL));
	return (min);
}
