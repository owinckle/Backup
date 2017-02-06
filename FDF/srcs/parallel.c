/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 13:52:41 by owinckle          #+#    #+#             */
/*   Updated: 2016/03/28 13:52:42 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord		get_parallelpoint(int x, int y, int z, t_env *e)
{
	t_coord		p;

	x *= e->scale;
	y *= e->scale;
	p.y = (x + e->y_offset) + e->cte1 * -z + e->y_origin;
	p.x = (y + e->x_offset) + e->cte3 * (-z * e->height) + e->x_origin;
	p.z = z;
	return (p);
}

void		parallel(t_env *e)
{
	int			i;
	int			j;
	t_coord		p1;
	t_coord		p2;

	i = -1;
	while (++i < e->width)
	{
		j = e->length;
		while (--j >= 0)
		{
			p1 = get_parallelpoint(i, j, e->array[i][j], e);
			if (i < e->width - 1)
			{
				p2 = get_parallelpoint(i + 1, j, e->array[i + 1][j], e);
				ft_draw(e, &p1, &p2);
			}
			if (j < e->length - 1)
			{
				p2 = get_parallelpoint(i, j + 1, e->array[i][j + 1], e);
				ft_draw(e, &p1, &p2);
			}
		}
	}
}
