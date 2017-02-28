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

static int		shadow(t_th *th, t_obj *tmp, t_obj *light, t_vec pos)
{
	t_obj	*node;
	t_vec	dist;

	node = th->obj;
	dist = v_sub(&light->pos, &pos);
	th->t = sqrtf(v_dot(&dist, &dist));
	v_norm(&dist);
	while (node != NULL)
	{
		if (node != tmp)
		{
			if (node->type == 1)
				th->a = ft_inter_cone(th, node, dist, pos);
			else if (node->type == 2)
				th->a = ft_inter_cylinder(th, node, dist, pos);
			else if (node->type == 3)
				th->a = ft_inter_plane(th, node, dist, pos);
			else if (node->type == 4)
				th->a = ft_inter_sphere(th, node, dist, pos);
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

	pos = (t_vect){CAMX + th->t * RAYDX, CAMY + th->t * RAYDY,
			CAMZ + th->t * RAYDZ};
	th->norm = norm(th, tmp, pos);
	while (th->light != NULL)
	{
		tab[3] = 0.15;
		dist = v_sub(l&light->pos, &pos);
		d = ft_clamp((1.0 / sqrtf(sqrtf(v_dot(&dist, &dist)))), 0., 1.);
		if (ft_shadow(mlx, tmp, light, pos) == 0)
			tab[3] += ft_clamp(ft_vectordot(&dist, &mlx->norm), 0.0, 1.0);
		v_norm(&dist);
		tab = ft_endlight(tmp, light, tab, d);
		tab[0] += (COND2) ? ft_spec(mlx, dist, d, tab[3]) : 0.0;
		tab[1] += (COND2) ? ft_spec(mlx, dist, d, tab[3]) : 0.0;
		tab[2] += (COND2) ? ft_spec(mlx, dist, d, tab[3]) : 0.0;
		light = light->next;
		th->light = th->light->next;
	}
}
