/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 01:32:17 by dbirtel           #+#    #+#             */
/*   Updated: 2017/04/08 09:06:23 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_coord	get_pinhole(t_cam cam, int i, int j)
{
	t_coord	pinhole;
	double	x_ind;
	double	y_ind;

	x_ind = 0.5 / WIDTH * (WIDTH / HEIGHT);
	y_ind = 0.5 / HEIGHT;
	pinhole = translate(cam.pos, cam.vector_dir, 1);
	pinhole = \
	translate(pinhole, cam.vector_up, ((j * y_ind) - (HEIGHT / 2 * y_ind)));
	pinhole = \
	translate(pinhole, cam.vector_right, ((i * x_ind) - (WIDTH / 2 * x_ind)));
	return (pinhole);
}

t_ray	compute_ray(t_coord pos, t_coord pinhole)
{
	t_ray	ray;

	ray.origin.x = pinhole.x;
	ray.origin.y = pinhole.y;
	ray.origin.z = pinhole.z;
	ray.vector = sub_coord(pinhole, pos);
	ray.vector = vec_norm(ray.vector);
	return (ray);
}

t_qt	compute_rot_qt(t_coord dir)
{
	t_qt	rot;
	t_coord	n;
	t_coord	axis;
	double	det;
	double	dotp;

	axis.x = 0.0000000001;
	axis.y = 1.0;
	axis.z = 0.0000000001;
	n = vec_norm(cross(dir, axis));
	dotp = dot(axis, dir);
	det = axis.x * dir.y * n.z + dir.x * n.y * axis.z + n.x * axis.y * dir.z \
		- axis.z * dir.y * n.x - dir.z * n.y * axis.x - n.z * axis.y * dir.x;
	rot.a = atan2(det, dotp) / 2.0;
	rot.v = n;
	return (rot);
}

t_ray	move_ray(t_ray ray, t_ob *obj)
{
	t_qt	pos;
	t_qt	vec;

	ft_putnbr(ray.origin.x);
	ray.origin = sub_coord(ray.origin, obj->pos);
	if (obj->type == SPHERE)
		return (ray);
	pos.a = 0.0f;
	pos.v = ray.origin;
	pos = rot_qt(pos, obj->rot);
	ray.origin = pos.v;
	vec.a = 0.0f;
	vec.v = ray.vector;
	vec = rot_qt(vec, obj->rot);
	ray.vector = vec.v;
	return (ray);
}
