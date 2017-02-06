/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:27:19 by owinckle          #+#    #+#             */
/*   Updated: 2016/12/23 15:27:20 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_inter	*spheres_inter(t_env *e, t_ray *ray, int limiter, t_vect *p)
{
	double		mininter;
	double		inter;
	t_vect		*normal;
	t_color		*c;
	t_sphere	*s;

	s = e->scene.spheres;
	mininter = -1;
	while (s != NULL && limiter-- != 0)
	{
		inter = sphere_inter(s, ray);
		if (inter > ACCURACY && (inter < mininter || mininter == -1))
		{
			mininter = inter;
			p = vect_add(ray->og, vect_mult(ray->dir, inter));
			normal = sphere_normal(s->og, p);
			c = s->color;
		}
		s = s->next;
	}
	return (new_inter(normal, mininter, c, p));
}

t_inter	*planes_inter(t_env *e, t_ray *ray, int limiter, t_vect *pt)
{
	double	mininter;
	double	inter;
	t_vect	*normal;
	t_color	*c;
	t_plane	*p;

	p = e->scene.planes;
	mininter = -1;
	while (p != NULL && limiter-- != 0)
	{
		inter = plane_inter(p, ray);
		if (inter > ACCURACY && (inter < mininter || mininter == -1))
		{
			mininter = inter;
			normal = p->og;
			pt = vect_add(ray->og, vect_mult(ray->dir, inter));
			c = p->color;
		}
		p = p->next;
	}
	return (new_inter(normal, mininter, c, pt));
}

t_inter	*cylinders_inter(t_env *e, t_ray *ray, int limiter, t_vect *p)
{
	double		mininter;
	double		inter;
	t_vect		*normal;
	t_color		*c;
	t_cyl		*cyl;

	cyl = e->scene.cyls;
	mininter = -1;
	while (cyl != NULL && limiter-- != 0)
	{
		ray = rotate_eye(ray, cyl->rotate, -1);
		inter = cylinder_inter(cyl, ray);
		ray = rotate_eye(ray, cyl->rotate, 1);
		if (inter > ACCURACY && (inter < mininter || mininter == -1))
		{
			mininter = inter;
			ray = rotate_eye(ray, cyl->rotate, -1);
			p = vect_add(ray->og, vect_mult(ray->dir, inter));
			ray = rotate_eye(ray, cyl->rotate, 1);
			normal = rotate_normal(cylinder_normal(cyl->og, p), cyl->rotate);
			c = cyl->color;
		}
		cyl = cyl->next;
	}
	return (new_inter(normal, mininter, c, p));
}

t_inter	*cones_inter(t_env *e, t_ray *ray, int limiter, t_vect *p)
{
	double		mininter;
	double		inter;
	t_cone		*co;
	t_color		*color;
	t_vect		*normal;

	co = e->scene.cones;
	mininter = -1;
	while (co != NULL && limiter-- != 0)
	{
		ray = rotate_eye(ray, co->rotate, -1);
		inter = cone_inter(co, ray);
		ray = rotate_eye(ray, co->rotate, 1);
		if (inter > ACCURACY && (inter < mininter || mininter == -1))
		{
			mininter = inter;
			ray = rotate_eye(ray, co->rotate, -1);
			p = vect_add(ray->og, vect_mult(ray->dir, inter));
			ray = rotate_eye(ray, co->rotate, 1);
			normal = rotate_normal(cone_normal(co->og, p), co->rotate);
			color = co->color;
		}
		co = co->next;
	}
	return (new_inter(normal, mininter, color, p));
}
