/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 09:31:03 by owinckle          #+#    #+#             */
/*   Updated: 2016/10/28 09:31:03 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		*color_scalar(double scalar, t_color *c1)
{
	t_color	*c2;

	c2 = new_color(c1->red * scalar, c1->green * scalar,
		c1->blue * scalar);
	return (c2);
}

int			get_color_nb(t_color *color)
{
	int		color_nb;

	color_nb = color->red;
	color_nb = (color_nb << 8) + color->green;
	color_nb = (color_nb << 8) + color->blue;
	return (color_nb);
}

t_color		*new_color(double r, double g, double b)
{
	t_color	*new;

	new = (t_color*)malloc(sizeof(t_color));
	if (new == NULL)
		ft_error(2);
	new->red = r;
	new->green = g;
	new->blue = b;
	return (new);
}

t_color		*get_color(int fd)
{
	double	r;
	double	g;
	double	b;
	char	*line;

	if (get_next_line(fd, &line) < 1)
		ft_error(4);
	free(line);
	r = ft_atodouble(&line);
	g = ft_atodouble(&line);
	b = ft_atodouble(&line);
	return (new_color(r, g, b));
}
