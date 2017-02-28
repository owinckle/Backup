/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 18:28:25 by owinckle          #+#    #+#             */
/*   Updated: 2017/02/20 18:28:26 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	inter_cylinder(t_th *th, t_obj *tmp, t_vect ray, t_vect pos)
{
	double disc;

	th->dist = v_sub(&pos, &tmp->pos);
	v_norm(&tmp->rot);
	th->a = v_dot(&ray, &ray) - pow(v_dot(&ray, &tmp->rot), 2);
	th->b = 2 * (v_dot(&ray, &th->dist) -
		(v_dot(&ray, &tmp->rot) * v_dot(&th->dist, &tmp->rot)));
	th->c = v_dot(&th->dist, &th->dist) -
		pow(v_dot(&th->dist, &tmp->rot), 2) - pow(tmp->size, 2);
	disc = th->b * th->b - 4 * th->a * th->c;
	if (disc < 0)
		return (-1);
	th->t0 = (-th->b + sqrtf(disc)) / (2 * th->a);
	th->t1 = (-th->b - sqrtf(disc)) / (2 * th->a);
	if (th->t0 > th->t1)
		th->t0 = th->t1;
	return (th->t0);
}

double	inter_cone(t_th *th, t_obj *tmp, t_vect ray, t_vect pos)
{
	double	disc;

	th->dist = v_sub(&pos, &tmp->pos);
	v_norm(&tmp->rot);
	th->a = v_dot(&ray, &ray) - (1 + pow(tan(tmp->size), 2)) *
		pow(v_dot(&ray, &tmp->rot), 2);
	th->b = 2 * (v_dot(&ray, &th->dist) - (1 + pow(tan(tmp->size), 2))
		* v_dot(&ray, &tmp->rot) * v_dot(&th->dist, &tmp->rot));
	th->c = v_dot(&th->dist, &th->dist) - (1 +
		pow(tan(tmp->size), 2)) * pow(v_dot(&th->dist, &tmp->rot), 2);
	disc = th->b * th->b - 4 * th->a * th->c;
	if (disc < 0)
		return (-1);
	th->t0 = (-th->b + sqrtf(disc)) / (2 * th->a);
	th->t1 = (-th->b - sqrtf(disc)) / (2 * th->a);
	if (th->t0 > th->t1)
		th->t0 = th->t1;
	return (th->t0);
}

double	inter_sphere(t_th *th, t_obj *tmp, t_vect ray, t_vect pos)
{
	double disc;

	th->dist = v_sub(&pos, &tmp->pos);
	th->a = v_dot(&ray, &ray);
	th->b = 2 * v_dot(&ray, &th->dist);
	th->c = v_dot(&th->dist, &th->dist) - (tmp->size * tmp->size);
	disc = th->b * th->b - 4 * th->a * th->c;
	if (disc < 0)
		return (-1);
	th->t0 = (-th->b + sqrtf(disc)) / (2 * th->a);
	th->t1 = (-th->b - sqrtf(disc)) / (2 * th->a);
	if (th->t0 > th->t1)
		th->t0 = th->t1;
	return (th->t0);
}

double	inter_plane(t_th *th, t_obj *tmp, t_vect ray, t_vect pos)
{
	th->t0 = ((v_dot(&tmp->rot, &tmp->pos) -
				v_dot(&tmp->rot, &pos)) / v_dot(&tmp->rot, &ray));
	if (th->t0 < 0.0001)
		return (-1);
	return (th->t0);
}

t_obj			*inter(t_th *th, t_obj *node, t_vect ray, t_vect pos)
{
	t_obj		*tmp;
	double		dist;

	tmp = NULL;
	th->t = 8000;
	while (node != NULL)
	{
		if (node->type == 1)
			dist = inter_cone(th, node, ray, pos);
		else if (node->type == 2)
			dist = inter_cylinder(th, node, ray, pos);
		else if (node->type == 3)
			dist = inter_plane(th, node, ray, pos);
		else if (node->type == 4)
			dist = inter_sphere(th, node, ray, pos);
		if (dist > 0.0001 && dist < th->t)
		{
			tmp = node;
			th->t = dist;
		}
		node = node->next;
	}
	return (tmp);
}
