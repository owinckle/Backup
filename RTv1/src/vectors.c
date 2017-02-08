/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 08:27:40 by owinckle          #+#    #+#             */
/*   Updated: 2016/10/28 08:27:40 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect	*new_vector(double x, double y, double z)
{
	t_vect	*new;

	new = (t_vect*)malloc(sizeof(t_vect));
	if (new == NULL)
		ft_error(2);
	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}

t_vect	*get_vector(int fd)
{
	double	x;
	double	y;
	double	z;
	char	*line;

	if (get_next_line(fd, &line) < 1)
		ft_error(4);
	free(line);
	x = ft_atodouble(&line);
	y = ft_atodouble(&line);
	z = ft_atodouble(&line);
	return (new_vector(x, y, z));
}

t_vect	*vect_sub(t_vect *v1, t_vect *v2)
{
	return (new_vector(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z));
}

t_vect	*cross_product(t_vect *v1, t_vect *v2)
{
	t_vect	*result;

	result = new_vector(v1->y * v2->z - v1->z * v2->y,
		v1->z * v2->x - v1->x * v2->z,
		v1->x * v2->y - v1->y * v2->x);
	return (result);
}

double	dot_product(t_vect *v1, t_vect *v2)
{
	double dot_product;

	dot_product = (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z);
	return (dot_product);
}
