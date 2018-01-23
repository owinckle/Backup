/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_qt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:49:59 by dbirtel           #+#    #+#             */
/*   Updated: 2017/04/01 00:14:49 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_qt	norm_qt(t_qt q)
{
	float	mag;

	mag = magnitude_qt(q);
	q.a /= mag;
	q.v.x /= mag;
	q.v.y /= mag;
	q.v.z /= mag;
	return (q);
}