/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 03:33:24 by dbirtel           #+#    #+#             */
/*   Updated: 2017/04/09 14:36:36 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_coord	cone_normal(t_ob *obj)
{
	t_qt	rot;
	t_qt	n;

	n.a = 0.0;
	n.v = obj->p[1];
	rot = inv_qt(obj->rot);
	if (n.v.y < 0)
		n.v.y += (vec_len(obj->p[1]) / cos(obj->radius));
	else
		n.v.y -= (vec_len(obj->p[1]) / cos(obj->radius));
	n.v = vec_norm(n.v);
	n = rot_qt(n, rot);
	return (n.v);
}

void	add_cone(char *line, int count, t_scene *s)
{
	t_ob	*tmp;
	t_ob	*cone;

	count_num(line, 11, count);
	if (!(cone = (t_ob *)malloc(sizeof(t_ob))))
		error(ERR_MALLOC);
	cone->max_ref = 0;
	cone->max_refr = 0;
	cone->pos = get_coord(line, 0);
	cone->radius = (get_num(line, 3) / 180 * M_PI);
	cone->normal = vec_norm(get_coord(line, 4));
	cone->rot = compute_rot_qt(cone->normal);
	cone->color = get_coord(line, 7);
	cone->type = CONE;
	cone->num = 0;
	cone->next = NULL;
	cone->spec = (int)get_num(line, 10);
	if (!s->obj)
		s->obj = cone;
	else
	{
		cone->num = s->obj->num + 1;
		tmp = s->obj;
		cone->next = tmp;
		s->obj = cone;
	}
}

double	solve_cone(t_ray r, t_ob *obj, int ok)
{
	t_val	v;
	double	a;

	r = move_ray(r, obj);
	a = tan(obj->radius);
	v.a = pow(r.vector.x, 2) + pow(r.vector.z, 2) - \
		pow(r.vector.y, 2) * a;
	v.b = 2 * r.vector.x * r.origin.x + 2 * r.vector.z * r.origin.z \
		- 2 * r.vector.y * r.origin.y * a;
	v.c = pow(r.origin.x, 2) + pow(r.origin.z, 2) - \
		pow(r.origin.y, 2) * a;
	v.det = v.b * v.b - 4 * v.a * v.c;
	if (v.det < 0)
		return (-1);
	v.result = (-v.b + sqrt(v.det)) / (2 * v.a);
	v.second = (-v.b - sqrt(v.det)) / (2 * v.a);
	if (v.second < v.result && v.second > 0)
		v.result = v.second;
	if (ok)
		obj->p[1] = \
		translate(r.origin, vec_norm(r.vector), v.result - 0.0000000001);
	return (v.result - FLT_EPSILON);
}
