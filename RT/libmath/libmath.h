/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmath.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 19:32:16 by dbirtel           #+#    #+#             */
/*   Updated: 2017/04/10 09:41:54 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMATH_H
# define LIBMATH_H

# include <math.h>

typedef struct	s_coord
{
	double		x;
	double		y;
	double		z;
}				t_coord;

typedef struct	s_qt
{
	double		a;
	t_coord		v;
}				t_qt;

double			vec_len(t_coord v);
double			dot(t_coord a, t_coord b);
double			magnitude_qt(t_qt q);
t_qt			norm_qt(t_qt q);
t_qt			inv_qt(t_qt q);
t_qt			rot_qt(t_qt v, t_qt r);
t_qt			mult_qt(t_qt a, t_qt b);
t_coord			add_coord(t_coord a, t_coord b);
t_coord			sub_coord(t_coord a, t_coord b);
t_coord			mult_coord(t_coord a, double d);
t_coord			translate(t_coord o, t_coord v, double d);
t_coord			vec_norm(t_coord v);
t_coord			cross(t_coord a, t_coord b);

#endif
