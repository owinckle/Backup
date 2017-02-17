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

	y = v->y;
	rot = DEG_TO_RAD(rot * stage);
	v->y = v->y * cos(rot) + v->z * -sin(rot);
	v->z = y * sin(rot) + v->z * cos(rot);
	return (v);
}

static t_vect	*y(t_vect *v, double rot, int stage)
{
	double		x;

	x = v->x;
	rot = DEG_TO_RAD(rot * stage);
	v->x = v->x * cos(rot) + v->z * sin(rot);
	v->z = x * -sin(rot) + v->z * cos(rot);
	return (v);
}

static t_vect	*z(t_vect *v, double rot, int stage)
{
	double		x;

	x = v->x;
	rot = DEG_TO_RAD(rot * stage);
	v->x = v->x * cos(rot) + v->y * -sin(rot);
	v->y = x * sin(rot) + v->y * cos(rot);
	return (v);
}

t_ray			*rotate_eye(t_ray *ray, t_vect *rot, int stage, t_vect *pos)
{
	t_vect		*og;
	t_vect		*dir;
	
	dir = ray->dir;
	if (stage == 1 && (og = ray->og))
	{
		ray->og = x(og, rot->x, stage);
		ray->og = y(og, rot->y, stage);
		ray->og = z(og, rot->z, stage);
		ray->dir = x(dir, rot->x, stage);
		ray->dir = y(dir, rot->y, stage);
		ray->dir = z(dir, rot->z, stage);
	}
	if (rot->x != 0 || rot->y != 0 || rot->z != 0)
	{
		ray->og->x += stage * pos->x;
		ray->og->y += stage * pos->y;
		ray->og->z += stage * pos->z;
	}
	if (stage == -1 && (og = ray->og))
	{
		ray->og = z(og, rot->z, stage);
		ray->og = y(og, rot->y, stage);
		ray->og = x(og, rot->x, stage);
		ray->dir = z(dir, rot->z, stage);
		ray->dir = y(dir, rot->y, stage);
		ray->dir = x(dir, rot->x, stage);
	}
	return (ray);
}

t_vect			*rotate_normal(t_vect *normal, t_vect *rot)
{
	normal = x(normal, rot->x, -1);
	normal = y(normal, rot->y, -1);
	normal = z(normal, rot->z, -1);
	return (normal);
}
