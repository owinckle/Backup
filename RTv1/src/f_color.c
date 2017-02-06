/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_color.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:24:56 by owinckle          #+#    #+#             */
/*   Updated: 2016/12/05 11:24:57 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	shadows(t_env *e, t_inter *inter)
{
	t_ray		*iray;
	t_vect		*v;
	t_vect		*l;

	l = e->scene.spot->pos;
	v = new_vector(l->x - inter->point->x, l->y - inter->point->y,
		l->z - inter->point->z);
	iray = new_ray(inter->point, l);
	return (calc_inter(e, iray)->dist);
}

t_color			*find_color_at(t_env *e, t_ray *ray)
{
	t_color		*result;
	t_inter		*mininter;
	t_vect		*dist_l;
	double		shade;

	mininter = calc_inter(e, ray);
	if (mininter->dist > ACCURACY)
	{
		dist_l = normalize(vect_add(e->scene.spot->pos, negative(ray->og)));
		shade = dot_product(dist_l, mininter->normal);
		if (shadows(e, mininter) > ACCURACY)
			result = color_scalar(AMBIENTLIGHT * shadows(e, mininter),
				mininter->color);
		else
			result = shade < 0 ? color_scalar(AMBIENTLIGHT + DIFFUSELIGHT *
				0, mininter->color) : color_scalar(AMBIENTLIGHT +
				DIFFUSELIGHT * shade, mininter->color);
	}
	else
		result = new_color(0, 0, 0);
	return (result);
}
