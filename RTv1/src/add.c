/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:09:07 by owinckle          #+#    #+#             */
/*   Updated: 2016/12/23 15:09:09 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	add_sphere(t_sphere *s, t_sphere *to_add, int limiter)
{
	while (s->next != NULL && limiter-- != 2)
		s = s->next;
	s->next = to_add;
}

void	add_plane(t_plane *p, t_plane *to_add, int limiter)
{
	while (p->next != NULL && limiter-- != 2)
		p = p->next;
	p->next = to_add;
}

void	add_cylinder(t_cyl *c, t_cyl *to_add, int limiter)
{
	while (c->next != NULL && limiter-- != 2)
		c = c->next;
	c->next = to_add;
}

void	add_cone(t_cone *c, t_cone *to_add, int limiter)
{
	while (c->next != NULL && limiter-- != 2)
		c = c->next;
	c->next = to_add;
}
