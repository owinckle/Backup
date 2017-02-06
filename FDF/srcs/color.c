/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 13:50:57 by owinckle          #+#    #+#             */
/*   Updated: 2016/03/28 13:51:06 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_find_color(t_color *color, int z, int z_min, int z_max)
{
	int		t1;
	int		t2;
	int		v;

	if (z <= z_min)
		return (color->color1);
	if (z >= z_max)
		return (color->color2);
	t1 = color->color1 / 256 / 256;
	t2 = color->color2 / 256 / 256;
	v = ((((z - abs(z_min)) * (t2 - t1)) / \
		(z_max - abs(z_min))) + t1) * 256 * 256;
	t1 = color->color1 / 256 % 256;
	t2 = color->color2 / 256 % 256;
	v += ((((z - abs(z_min)) * (t2 - t1)) / (z_max - abs(z_min))) + t1) * 256;
	t1 = color->color1 % 256;
	t2 = color->color2 % 256;
	v += ((((z - abs(z_min)) * (t2 - t1)) / (z_max - abs(z_min))) + t1);
	return (v);
}

int		ft_level(t_env *e, double z)
{
	t_color		color;

	if (z < e->z_min || z > e->z_max)
		return (0);
	if (z <= e->z_mid && z >= e->z_min)
	{
		color.color1 = e->color[e->cnum][0];
		color.color2 = e->color[e->cnum][1];
		return (ft_find_color(&color, z, e->z_min, e->z_mid));
	}
	else if (z <= e->z_max && z >= e->z_mid)
	{
		color.color1 = e->color[e->cnum][1];
		color.color2 = e->color[e->cnum][2];
		return (ft_find_color(&color, z, e->z_mid, e->z_max));
	}
	return (0);
}
