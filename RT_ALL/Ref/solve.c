/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 01:34:56 by dbirtel           #+#    #+#             */
/*   Updated: 2017/04/09 18:22:16 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

double	intersect(t_ray ray, t_ob *obj, int ok)
{
	if (obj->type == SPHERE)
		return (solve_sphere(ray, obj, ok));
	if (obj->type == PLANE)
		return (solve_plane(ray, obj));
	if (obj->type == CONE)
		return (solve_cone(ray, obj, ok));
	if (obj->type == CYLINDER)
		return (solve_cylinder(ray, obj, ok));
	return (-1);
}

t_ob	*find_inter(t_ray ray, t_ob *obj, double *dist, int ok)
{
	t_ob	*tmp;
	t_ob	*new;
	double	inter;

	new = NULL;
	tmp = obj;
	while (tmp)
	{
		inter = intersect(ray, tmp, ok);
		if (inter < *dist && inter > 0)
		{
			*dist = inter;
			new = tmp;
		}
		tmp = tmp->next;
	}
	return (new);
}

t_coord	fix_color(t_coord color)
{
	color.x = color.x > 255 ? 255 : color.x;
	color.y = color.y > 255 ? 255 : color.y;
	color.z = color.z > 255 ? 255 : color.z;
	return (color);
}

t_coord	find_color(t_scene *s, t_ob *obj)
{
	t_coord	color;
	t_ray	shad;
	t_li	*spots;
	double	d;

	spots = s->spots;
	color = filter(s->filter);
	while (spots && obj->spec != 3)
	{
		d = vec_len(sub_coord(obj->p[0], spots->pos));
		shad.origin = obj->p[0];
		shad.vector = vec_norm(sub_coord(spots->pos, obj->p[0]));
		if (!find_inter(shad, s->obj, &d, 0))
		{
			color = add_coord(color, diffuse(shad, obj, d));
			if (obj->spec)
				color = add_coord(color, specular(shad, obj, s->cam, d));
		}
		spots = spots->next;
	}
	if (obj->spec != 3)
		color = add_coord(color, ambient(obj));
	color = fix_color(color);
			

	return (color);
}

t_coord		ref_refr(t_ray ray, t_scene *s, t_ob *obj)
{
	t_coord		c_ref_refr;
	t_coord		c_transparent;

	c_ref_refr = blacked();
	c_transparent = mult_coord(obj->color, 0.15);
	if (obj->spec == 2)
		c_ref_refr = reflection(ray, s, obj);
	if (obj->spec == 3)
		c_ref_refr = refraction(ray, s, obj);
	if (obj->spec == 4)
	{
		ray.origin = obj->p[0];
		c_ref_refr = add_coord(c_transparent, solve(ray, s));
	}
	return (c_ref_refr);
}

t_coord		solve(t_ray ray, t_scene *s)
{
	t_ob	*obj;
	double	dist;
	t_coord	color;

	dist = MAX_DIST;
	if ((obj = find_inter(ray, s->obj, &dist, 1)) == NULL)
		return ((t_coord){0, 0, 0});
	obj->p[0] = translate(ray.origin, ray.vector, dist - 0.001);
	if (obj->spec == 3)
		obj->p[0] = translate(ray.origin, ray.vector, dist - 0.000000000001);
	color = find_color(s, obj);
	if (obj->spec > 1)
		color = fix_color(add_coord(color, ref_refr(ray, s, obj)));
	return (color);
}
