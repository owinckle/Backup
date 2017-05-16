/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 05:18:17 by dbirtel           #+#    #+#             */
/*   Updated: 2017/04/09 15:44:56 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_coord		blacked(void)
{
	t_coord	black;

	black.x = 0.0;
	black.y = 0.0;
	black.z = 0.0;
	return (black);
}

t_coord		get_normal(t_ob *obj)
{
	if (obj->type == SPHERE)
		return (vec_norm(obj->p[1]));
	if (obj->type == CYLINDER)
		return (cylinder_normal(obj));
	if (obj->type == CONE)
		return (cone_normal(obj));
	return (obj->normal);
}
