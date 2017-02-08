/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:25:16 by owinckle          #+#    #+#             */
/*   Updated: 2016/12/23 15:25:16 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect		*sphere_normal(t_vect *og, t_vect *point)
{
	t_vect	*v;

	v = normalize(vect_add(point, negative(og)));
	return (v);
}

t_vect		*cylinder_normal(t_vect *og, t_vect *point)
{
	t_vect	*v;

	v = normalize(vect_add(new_vector(point->x, 0, point->z),
		negative(new_vector(og->x, 0, og->z))));
	return (v);
}

t_vect		*cone_normal(t_vect *og, t_vect *point)
{
	t_vect	*v;

	v = normalize(vect_add(new_vector(point->x, 0, point->z),
		negative(new_vector(og->x, 0, og->z))));
	return (v);
}
