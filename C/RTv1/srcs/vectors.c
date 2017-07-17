/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 17:44:06 by owinckle          #+#    #+#             */
/*   Updated: 2017/02/20 17:44:07 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect	v_sub(t_vect *v1, t_vect *v2)
{
	t_vect	sub;

	sub.x = v1->x - v2->x;
	sub.y = v1->y - v2->y;
	sub.z = v1->z - v2->z;
	return (sub);
}

t_vect	v_cross(t_vect *v1, t_vect *v2)
{
	t_vect	v;

	v.x = v1->y * v2->z - v1->z * v2->y;
	v.y = v1->z * v2->x - v1->x * v2->z;
	v.z = v1->x * v2->y - v1->y * v2->x;
	return (v);
}

void	v_norm(t_vect *v)
{
	double	n;

	n = 1.0 / sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
	v->x *= n;
	v->y *= n;
	v->z *= n;
}

float	v_dot(t_vect *v1, t_vect *v2)
{
	float	res;

	res = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
	return (res);
}

t_vect	v_scale(t_vect *v, float n)
{
	t_vect	res;

	res.x = v->x * n;
	res.y = v->y * n;
	res.z = v->z * n;
	return (res);
}
