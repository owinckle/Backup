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

t_coord		transparent(t_ray ray, t_scene *s, t_ob *obj, t_coord col)
{
	t_coord		color;

	color = mult_coord(col, 0.1);
	if (obj->max_ref < 1)
	{
		obj->max_ref++;
		ray.origin = obj->p[1];
		color = add_coord(color, solve(ray, s));
	}
	if (obj->max_ref == 1)
		obj->max_ref = 0;
	return (color);
}
