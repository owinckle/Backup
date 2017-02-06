/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 13:51:45 by owinckle          #+#    #+#             */
/*   Updated: 2016/03/28 13:51:47 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_right(t_env *e, t_coord *p1, t_coord *p2)
{
	int		x;
	double	z;

	x = p1->x - 1;
	z = p1->z;
	while (++x <= p2->x)
	{
		pixel_put(e, x, p1->y + ((p2->y - p1->y) * (x - p1->x)) / \
			(p2->x - p1->x), ft_level(e, z));
		z += e->pasz;
	}
}

void	ft_draw_left(t_env *e, t_coord *p1, t_coord *p2)
{
	int		x;
	double	z;

	x = p2->x - 1;
	z = p2->z;
	while (++x <= p1->x)
	{
		pixel_put(e, x, p2->y + ((p1->y - p2->y) * (x - p2->x)) / \
			(p1->x - p2->x), ft_level(e, z));
		z += e->pasz;
	}
}

void	ft_draw_up(t_env *e, t_coord *p1, t_coord *p2)
{
	int		y;
	double	z;

	y = p2->y - 1;
	z = p2->z;
	while (++y <= p1->y)
	{
		pixel_put(e, p2->x + ((p1->x - p2->x) * (y - p2->y)) / \
			(p1->y - p2->y), y, ft_level(e, z));
		z += e->pasz;
	}
}

void	ft_draw_down(t_env *e, t_coord *p1, t_coord *p2)
{
	int		y;
	double	z;

	y = p1->y - 1;
	z = p1->z;
	while (++y <= p2->y)
	{
		pixel_put(e, p1->x + ((p2->x - p1->x) * (y - p1->y)) / \
			(p2->y - p1->y), y, ft_level(e, z));
		z += e->pasz;
	}
}

void	ft_draw(t_env *e, t_coord *p1, t_coord *p2)
{
	if (fabs(p2->x - p1->x) > fabs(p2->y - p1->y))
		e->pasz = (p2->z - p1->z) / (p2->x - p1->x);
	else
		e->pasz = (p2->z - p1->z) / (p2->y - p1->y);
	if (p1->x <= p2->x && (p2->x - p1->x) >= fabs(p2->y - p1->y))
		ft_draw_right(e, p1, p2);
	else if (p2->x <= p1->x && (p1->x - p2->x) >= fabs(p1->y - p2->y))
		ft_draw_left(e, p1, p2);
	else if (p2->y <= p1->y && (p1->y - p2->y) >= fabs(p1->x - p2->x))
		ft_draw_up(e, p1, p2);
	else if (p1->y <= p2->y && (p2->y - p1->y) >= fabs(p2->x - p1->x))
		ft_draw_down(e, p1, p2);
}
