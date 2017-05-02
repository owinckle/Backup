/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 00:34:23 by dbirtel           #+#    #+#             */
/*   Updated: 2017/04/09 14:37:04 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	add_sphere(char *line, int count, t_scene *s)
{
	t_ob	*tmp;
	t_ob	*sphere;

	count_num(line, 11, count);
	if (!(sphere = (t_ob *)malloc(sizeof(t_ob))))
		error(ERR_MALLOC);
	sphere->max_ref = 0;
	sphere->max_refr = 0;
	sphere->pos = get_coord(line, 0);
	sphere->color = get_coord(line, 7);
	sphere->radius = get_num(line, 3);
	sphere->type = SPHERE;
	sphere->num = 0;
	sphere->next = NULL;
	sphere->spec = (int)get_num(line, 10);
	if (!s->obj)
		s->obj = sphere;
	else
	{
		sphere->num = s->obj->num + 1;
		tmp = s->obj;
		sphere->next = tmp;
		s->obj = sphere;
	}
}

double	solve_sphere(t_ray r, t_ob *obj, int ok)
{
	t_val	v;

	r = move_ray(r, obj);
	v.a = r.vector.x * r.vector.x + r.vector.y * \
		r.vector.y + r.vector.z * r.vector.z;
	v.b = 2 * (r.vector.x * r.origin.x + r.vector.y * \
			r.origin.y + r.vector.z * r.origin.z);
	v.c = r.origin.x * r.origin.x + r.origin.y * r.origin.y + \
		r.origin.z * r.origin.z - obj->radius * obj->radius;
	v.det = v.b * v.b - 4 * v.a * v.c;
	if (v.det < 0)
		return (-1);
	v.result = (-v.b + sqrt(v.det)) / (2 * v.a);
	v.second = (-v.b - sqrt(v.det)) / (2 * v.a);
	if (v.second < v.result)
		v.result = v.second;
	if (ok)
		obj->p[1] = translate(r.origin, r.vector, v.result - 0.0000000001);
	return (v.result - FLT_EPSILON);
}
