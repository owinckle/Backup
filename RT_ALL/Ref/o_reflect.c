/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_reflect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 18:10:49 by owinckle          #+#    #+#             */
/*   Updated: 2017/04/28 18:11:04 by owinckle         ###   ########.fr       */
/*                                                                            */
/* *******************************************0******************************* */

#include "rtv1.h"

t_coord		vect_ref(t_coord v, t_coord n)
{
	t_coord	ref;

	ref = mult_coord(n, -2.0 * dot(v, n));
	ref = add_coord(ref, v);
	return (ref);
}

t_coord		reflection(t_ray ray, t_scene *s, t_ob *obj)
{
	t_coord	color;
	t_coord	normal;

	color = (t_coord){0, 0, 0};
	if (obj->max_ref < 1)
	{
		obj->max_ref++;
		normal = vec_norm(get_normal(obj));
		ray.origin = obj->p[0];
		ray.vector = vect_ref(ray.vector, normal);
		color = add_coord(color, solve(ray, s));
		color = mult_coord(color, 0.5);
	}
	if (obj->max_ref == 1)
		obj->max_ref = 0;
	return(color);
}