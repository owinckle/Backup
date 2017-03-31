/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 10:29:02 by owinckle          #+#    #+#             */
/*   Updated: 2017/02/28 10:29:03 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static float	*lighting(t_obj *tmp, t_obj *light, float *tab, float d)
{
	tab[3] = ft_clamp(tab[3] * 4.0 * d, 0.0, 1.0);
	tab[0] += tab[3] * (tmp->color.red / 255) * (light->color.red / 255);
	tab[1] += tab[3] * (tmp->color.green / 255) * (light->color.green / 255);
	tab[2] += tab[3] * (tmp->color.blue / 255) * (light->color.blue / 255);
	return (tab);
}

static int		shadow(t_th *th, t_obj *tmp, t_obj *light, t_vect pos)
{
	t_obj	*node;0hro
	t_vect	dist;

	node = th->obj;
	dist = v_sub(&light->pos, &pos);
	th->t = sqrtf(v_dot(&dist, &dist));
	v_norm(&dist);
	while (node != NULL)
	{
		if (node != tmp)
		{
			if (node->type == 1)
				th->a = inter_cone(th, node, dist, pos);
			else if (node->type == 2)
				th->a = inter_cylinder(th, node, dist, pos);
			else if (node->type == 3)
				th->a = inter_plane(th, node, dist, pos);
			else if (node->type == 4)
				th->a = inter_sphere(th, node, dist, pos);
			if (th->a > 0.0001 && th->a < th->t)
				return (1);
		}
		node = node->next;
	}
	return (0);
}

static t_vect	norm(t_th *th, t_obj *tmp, t_vect pos)
{
	t_vect	norm;
	t_vect	temp;
	t_vect	temp2;

	if (tmp->type == 1 || tmp->type == 2)
	{
		temp = v_scale(&tmp->rot,
			(v_dot(&th->ray_dir, &tmp->rot) * th->t0
			+ v_dot(&th->dist, &tmp->rot)));
		if (tmp->type == 1)
			temp = v_scale(&temp, (1 + pow(tan(tmp->size), 2)));
		temp2 = v_sub(&pos, &tmp->pos);
		norm = v_sub(&temp2, &temp);
	}
	else if (tmp->type == 3)
		norm = tmp->rot;
	if (tmp->type == 4)
		norm = v_sub(&pos, &tmp->pos);
	v_norm(&norm);
	return (norm);
}

float			*lambert(t_th *th, t_obj *tmp, t_obj *light, float *tab)
{
	t_vect		pos;
	t_vect		dist;
	float		d;

	pos = (t_vect){TH_CAMX + th->t * TH_RAYDX, TH_CAMY + th->t * TH_RAYDY,
			TH_CAMZ + th->t * TH_RAYDZ};
	th->norm = norm(th, tmp, pos);
	while (light != NULL)
	{
		tab[3] = 0.15;
		dist = v_sub(&light->pos, &pos);
		d = ft_clamp((1.0 / sqrtf(sqrtf(v_dot(&dist, &dist)))), 0., 1.);
		v_norm(&dist);
		if (shadow(th, tmp, light, pos) == 0)
			tab[3] += ft_clamp(v_dot(&dist, &th->norm), 0.0, 1.0);
		tab = lighting(tmp, light, tab, d);
		light = light->next;
	}
	return (tab);
}
