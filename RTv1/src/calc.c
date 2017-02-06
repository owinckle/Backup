/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:28:15 by owinckle          #+#    #+#             */
/*   Updated: 2016/12/23 15:28:16 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	sphere_inter(t_sphere *s, t_ray *r)
{
	double		a;
	double		b;
	double		c;
	double		d;
	double		t;

	a = dot_product(r->dir, r->dir);
	b = dot_product(r->dir, vect_mult(vect_sub(r->og, s->og), 2));
	c = dot_product(s->og, s->og) +
		dot_product(r->og, r->og) -
		2 * dot_product(r->og, s->og) -
		s->radius * s->radius;
	d = b * b + (-4) * a * c;
	if (d < 0)
		return (-1);
	d = sqrt(d);
	t = (-0.5) * (b + d) / a;
	if (t > 0)
		return (t);
	else
		return (-1);
}

double	plane_inter(t_plane *p, t_ray *r)
{
	double	a;
	double	b;

	a = dot_product(p->og, r->dir);
	if (a == 0)
		return (-1);
	else
	{
		b = dot_product(p->og, vect_add(r->og,
			negative(p->og)));
		return (-b / a);
	}
}

double	cylinder_inter(t_cyl *cyl, t_ray *r)
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	t;

	a = pow(r->dir->x, 2) +
		pow(r->dir->z, 2);
	b = (2 * (r->dir->x * (r->og->x - cyl->og->x))) +
		(2 * (r->dir->z * (r->og->z - cyl->og->z)));
	c = pow(r->og->x - cyl->og->x, 2) +
		pow(r->og->z - cyl->og->z, 2) -
		cyl->radius * cyl->radius;
	d = b * b - 4 * a * c;
	if (d < 0)
		return (-1);
	d = sqrt(d);
	t = (-0.5) * (b + d) / a;
	if (t > 0)
		return (t);
	else
		return (-1);
}

double	cone_inter(t_cone *co, t_ray *r)
{
	double		t;
	double		a;
	double		b;
	double		c;
	double		d;

	a = pow(r->dir->x, 2) -
		pow(r->dir->y, 2) +
		pow(r->dir->z, 2);
	b = (2 * (r->dir->x * (r->og->x - co->og->x))) -
		(2 * (r->dir->y * (r->og->y - co->og->y))) +
		(2 * (r->dir->z * (r->og->z - co->og->z)));
	c = pow(r->og->x - co->og->x, 2) -
		pow(r->og->y - co->og->y, 2) +
		pow(r->og->z - co->og->z, 2);
	d = b * b - 4 * a * c;
	if (a < 0)
		return (-1);
	d = sqrt(d);
	t = (-0.5) * (b + d) / a;
	if (t > 0)
		return (t);
	else
		return (-1);
}
