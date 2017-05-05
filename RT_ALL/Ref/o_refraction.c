/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_refraction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:53:57 by owinckle          #+#    #+#             */
/*   Updated: 2017/05/02 16:53:58 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_coord		vect_refr(t_coord normal, t_coord dir)
{
	double	calc[3];
	double	n[3];
	t_coord ref;

	calc[0] = dot(normal, dir);
	if (calc[0] > 0)
	{
		n[1] = 0.5;
		n[2] = 0;
		mult_coord(normal, -1.0);
	}
	else
	{
		n[2] = 0.5;
		n[1] = 0;
		calc[0] = -calc[0];
	}
	n[0] = n[1] / n[2];
	calc[2] = n[0] * n[0] * (1.0 - calc[0] * calc[0]);
	calc[1] = sqrt(1.0 - calc[2]);
	ref = add_coord(mult_coord(dir, n[0]), mult_coord(normal, (n[0] * calc[0] - calc[1])));
	ref = vec_norm(ref);
	return (ref);
}

t_coord		refraction(t_ray ray, t_scene *s, t_ob *obj)
{
	t_coord		color;
	t_coord		normal;

	color = blacked();
	if (obj->max_refr < 1)
	{
		obj->max_refr++;
		normal = vec_norm(get_normal(obj));
		ray.origin = obj->p[0];
		ray.vector = vect_refr(normal, ray.vector);
		color = add_coord(color, solve(ray, s));
		color = mult_coord(color, 1);
	}
	if (obj->max_refr == 1)
		obj->max_refr = 0;
	return (color);
}