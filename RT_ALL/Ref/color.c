/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 11:10:16 by dbirtel           #+#    #+#             */
/*   Updated: 2017/04/09 18:21:45 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_coord	mix_color(t_coord first, t_coord second, t_coord third)
{
	t_coord		new;

	new.x = (first.x + second.x + third.x) / 3.0;
	new.y = (first.y + second.y + third.y) / 3.0;
	new.z = (first.z + second.z + third.z) / 3.0;
	return (new);
}

t_coord	scale_color(int scale, t_coord base, t_coord added)
{
	t_coord		new;

	new.x = (scale * base.x + added.x) / (scale + 1.0);
	new.y = (scale * base.y + added.y) / (scale + 1.0);
	new.z = (scale * base.z + added.z) / (scale + 1.0);
	return (new);
}

t_coord	ambient(t_ob *obj)
{
	t_coord	color;

	color.x = AMBIENT * obj->color.x;
	color.y = AMBIENT * obj->color.y;
	color.z = AMBIENT * obj->color.z;
	return (color);
}

t_coord	diffuse(t_ray light, t_ob *obj, double dist)
{
	t_coord	color;
	double	angle;

	angle = dot(get_normal(obj), light.vector);
	color.x = (DIFFUSE * (obj->color.x * angle) - 0.0001) * \
		(1 / (0.5 + 0.0005 * dist + 0.0005 * dist * dist));
	color.y = (DIFFUSE * (obj->color.y * angle) - 0.0001) * \
		(1 / (0.5 + 0.0005 * dist + 0.0005 * dist * dist));
	color.z = (DIFFUSE * (obj->color.z * angle) - 0.0001) * \
		(1 / (0.5 + 0.0005 * dist + 0.0005 * dist * dist));
	return (color);
}

t_coord	specular(t_ray light, t_ob *obj, t_cam cam, double dist)
{
	t_coord	r;
	t_coord	normal;
	t_coord	color;
	t_coord	cam_vec;
	double	angle;

	normal = get_normal(obj);
	r = mult_coord(normal, 2.0);
	r = mult_coord(r, dot(light.vector, normal));
	r = vec_norm(sub_coord(r, light.vector));
	cam_vec = vec_norm(sub_coord(light.origin, cam.pos));
	angle = dot(r, cam_vec);
	if (vec_len(add_coord(cam_vec, r)) > (vec_len(cam_vec)))
		return (blacked());
	color.x = (10 + obj->color.x) * \
		pow(angle, 16.0) * (1 / (0.5 + 0.001 * dist + 0.001 * dist * dist));
	color.y = (10 + obj->color.y) * \
		pow(angle, 16.0) * (1 / (0.5 + 0.001 * dist + 0.001 * dist * dist));
	color.z = (10 + obj->color.z) * \
		pow(angle, 16.0) * (1 / (0.5 + 0.001 * dist + 0.001 * dist * dist));
	return (color);
}
