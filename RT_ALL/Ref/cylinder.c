/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:52:36 by dbirtel           #+#    #+#             */
/*   Updated: 2017/04/09 14:36:51 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_coord	cylinder_normal(t_ob *obj)
{
	t_qt	n;
	t_qt	rot;

	n.a = 0.0;
	n.v = obj->p[1];
	n.v.y = 0.0;
	n.v = vec_norm(n.v);
	rot = inv_qt(obj->rot);
	n = rot_qt(n, rot);
	return (n.v);
}

void	add_cylinder(char *line, int count, t_scene *s)
{
	t_ob	*tmp;
	t_ob	*cylinder;

	count_num(line, 11, count);
	if (!(cylinder = (t_ob *)malloc(sizeof(t_ob))))
		error(ERR_MALLOC);
	cylinder->max_ref = 0;
	cylinder->max_refr = 0;
	cylinder->pos = get_coord(line, 0);
	cylinder->normal = vec_norm(get_coord(line, 4));
	cylinder->rot = compute_rot_qt(cylinder->normal);
	cylinder->color = get_coord(line, 7);
	cylinder->radius = get_num(line, 3);
	cylinder->type = CYLINDER;
	cylinder->num = 0;
	cylinder->next = NULL;
	cylinder->spec = (int)get_num(line, 10);
	if (!s->obj)
		s->obj = cylinder;
	else
	{
		cylinder->num = s->obj->num + 1;
		tmp = s->obj;
		cylinder->next = tmp;
		s->obj = cylinder;
	}
}

double	solve_cylinder(t_ray r, t_ob *obj, int ok)
{
	t_val	v;

	r = move_ray(r, obj);
	v.a = pow(r.vector.x, 2) + pow(r.vector.z, 2);
	v.b = 2.0 * (r.vector.x * r.origin.x) + 2.0 * (r.vector.z * r.origin.z);
	v.c = pow(r.origin.x, 2) + pow(r.origin.z, 2) - pow(obj->radius, 2);
	v.det = v.b * v.b - 4.0 * v.a * v.c;
	if (v.det < 0)
		return (-1);
	v.result = (-v.b + sqrt(v.det)) / (2 * v.a);
	v.second = (-v.b - sqrt(v.det)) / (2 * v.a);
	if (v.second < v.result)
		v.result = v.second;
	if (ok)
		obj->p[1] = \
		translate(r.origin, r.vector, v.result - 0.0000000001);
	return (v.result - FLT_EPSILON);
}
