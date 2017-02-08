/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 10:38:16 by owinckle          #+#    #+#             */
/*   Updated: 2016/10/28 10:38:17 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	magnitude(t_vect *v1)
{
	return (sqrt((v1->x * v1->x) + (v1->y * v1->y) + (v1->z * v1->z)));
}

t_vect	*normalize(t_vect *v1)
{
	double	mag;

	mag = magnitude(v1);
	return (new_vector(v1->x / mag, v1->y / mag, v1->z / mag));
}

t_vect	*vect_add(t_vect *v1, t_vect *v2)
{
	return (new_vector(v1->x + v2->x, v1->y + v2->y, v1->z + v2->z));
}

t_vect	*vect_mult(t_vect *v1, double scalar)
{
	return (new_vector(v1->x * scalar, v1->y * scalar, v1->z * scalar));
}

t_vect	*negative(t_vect *v1)
{
	return (new_vector(v1->x * -1, v1->y * -1, v1->z * -1));
}
