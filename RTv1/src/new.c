/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:10:38 by owinckle          #+#    #+#             */
/*   Updated: 2016/12/23 15:10:40 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere	*new_sphere(t_vect *og, double radius, t_color *color)
{
	t_sphere	*new;

	new = (t_sphere*)malloc(sizeof(t_sphere));
	if (new == NULL)
		ft_error(2);
	new->og = og;
	new->radius = radius;
	new->color = color;
	return (new);
}

t_plane		*new_plane(t_vect *og, t_color *color, t_vect *rotate)
{
	t_plane		*new;

	new = (t_plane*)malloc(sizeof(t_plane));
	if (new == NULL)
		ft_error(2);
	new->og = og;
	new->color = color;
	new->rotate = rotate;
	return (new);
}

t_cyl		*new_cylinder(t_vect *og, double radius, t_color *color, t_vect *r)
{
	t_cyl	*new;

	new = (t_cyl*)malloc(sizeof(t_cyl));
	if (new == NULL)
		ft_error(2);
	new->og = og;
	new->rotate = r;
	new->radius = radius;
	new->color = color;
	return (new);
}

t_cone		*new_cone(t_vect *og, t_color *color, t_vect *rotate)
{
	t_cone		*new;

	new = (t_cone*)malloc(sizeof(t_cone));
	if (new == NULL)
		ft_error(2);
	new->og = og;
	new->rotate = rotate;
	new->color = color;
	return (new);
}

t_spot		*new_spot(t_vect *pos)
{
	t_spot		*new;

	new = (t_spot*)malloc(sizeof(t_spot));
	if (new == NULL)
		ft_error(2);
	new->pos = pos;
	return (new);
}
