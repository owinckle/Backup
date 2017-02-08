/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:06:26 by owinckle          #+#    #+#             */
/*   Updated: 2016/12/23 15:06:27 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere	*get_sphere(int fd)
{
	t_vect		*og;
	double		radius;
	t_color		*color;
	int			ret;
	char		*line;

	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp("----", line))
	{
		free(line);
		if (!ft_strcmp("pos:", line))
			og = get_vector(fd);
		if (!ft_strcmp("radius:", line))
		{
			ret = get_next_line(fd, &line);
			free(line);
			radius = ft_atodouble(&line);
		}
		if (!ft_strcmp("color:", line))
			color = get_color(fd);
	}
	free(line);
	if (ret == -1)
		ft_error(4);
	return (new_sphere(og, radius, color));
}

t_plane		*get_plane(int fd)
{
	t_vect		*og;
	t_vect		*rot;
	t_color		*color;
	int			ret;
	char		*line;

	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp("----", line))
	{
		free(line);
		if (!ft_strcmp("pos:", line))
			og = get_vector(fd);
		if (!ft_strcmp("rotate:", line))
			rot = get_vector(fd);
		if (!ft_strcmp("color:", line))
			color = get_color(fd);
	}
	free(line);
	if (ret == -1)
		ft_error(4);
	return (new_plane(og, color, rot));
}

t_cyl		*get_cylinder(int fd, t_vect *rot, int ret)
{
	t_vect	*og;
	double	radius;
	t_color	*color;
	char	*line;

	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp("----", line))
	{
		free(line);
		if (!ft_strcmp("pos:", line))
			og = get_vector(fd);
		if (!ft_strcmp("radius:", line))
		{
			ret = get_next_line(fd, &line);
			free(line);
			radius = ft_atodouble(&line);
		}
		if (!ft_strcmp("rotate:", line))
			rot = get_vector(fd);
		if (!ft_strcmp("color:", line))
			color = get_color(fd);
	}
	free(line);
	if (ret == -1)
		ft_error(4);
	return (new_cylinder(og, radius, color, rot));
}

t_cone		*get_cone(int fd)
{
	t_vect		*og;
	t_vect		*rot;
	t_color		*color;
	int			ret;
	char		*line;

	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp("----", line))
	{
		free(line);
		if (!ft_strcmp("pos:", line))
			og = get_vector(fd);
		if (!ft_strcmp("rotate:", line))
			rot = get_vector(fd);
		if (!ft_strcmp("color:", line))
			color = get_color(fd);
	}
	free(line);
	if (ret == -1)
		ft_error(4);
	return (new_cone(og, color, rot));
}

t_spot		*get_spot(int fd)
{
	t_spot		*s;
	int			ret;
	char		*line;
	t_vect		*pos;

	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp("----", line))
	{
		free(line);
		if (!ft_strcmp("pos:", line))
			pos = get_vector(fd);
	}
	if (ret == -1)
		ft_error(4);
	free(line);
	s = new_spot(pos);
	return (s);
}
