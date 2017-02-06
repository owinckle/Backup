/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:18:01 by owinckle          #+#    #+#             */
/*   Updated: 2016/12/23 15:47:52 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_vect	*x(t_vect *v, double rot, int stage)
{
	double		y;
	double		z;

	y = v->y;
	z = v->z;
	rot = DEG_TO_RAD(rot * stage);
	v->y = y * cos(rot) + z * -sin(rot);
	v->z = y * sin(rot) + z * cos(rot);
	return (v);
}

static t_vect	*y(t_vect *v, double rot, int stage)
{
	double		x;
	double		z;

	x = v->x;
	z = v->z;
	rot = DEG_TO_RAD(rot * stage);
	v->x = x * cos(rot) + z * sin(rot);
	v->z = x * -sin(rot) + z * cos(rot);
	return (v);
}

static t_vect	*z(t_vect *v, double rot, int stage)
{

	double		x;
	double		y;

	x = v->x;
	y = v->y;
	rot = DEG_TO_RAD(rot * stage);
	v->x = x * cos(rot) + y * -sin(rot);
	v->y = x * sin(rot) + y * cos(rot);
	return (v);
}

t_ray			*rotate_eye(t_ray *ray, t_vect *rot, int stage)
{
	ray->og = x(ray->og, rot->z, stage);
	ray->og = y(ray->og, rot->y, stage);
	ray->og = z(ray->og, rot->x, stage);
	ray->dir = x(ray->dir, rot->z, stage);
	ray->dir = y(ray->dir, rot->y, stage);
	ray->dir = z(ray->dir, rot->x, stage);
	return (ray);
}

t_vect			*rotate_normal(t_vect *normal, t_vect *rot)
{
	normal = x(normal, rot->z, -1);
	normal = y(normal, rot->y, -1);
	normal = z(normal, rot->x, -1);
	return (normal);
}
