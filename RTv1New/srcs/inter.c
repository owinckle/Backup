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

double	inter_plane(t_th *th, t_obj *tmp, t_vec ray, t_vec pos)
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
