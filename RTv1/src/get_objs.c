/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:52:21 by owinckle          #+#    #+#             */
/*   Updated: 2016/12/23 15:52:22 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere	*get_spheres(int fd, t_scene *scene)
{
	t_sphere	*s;
	int			ret;
	char		*line;
	int			limiter;

	limiter = 0;
	s = NULL;
	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp("----", line))
	{
		free(line);
		limiter++;
		if (!ft_strcmp("new:", line))
		{
			if (s == NULL)
				s = get_sphere(fd);
			else
				add_sphere(s, get_sphere(fd), limiter);
		}
	}
	free(line);
	if (ret == -1)
		ft_error(4);
	scene->c_spheres = limiter;
	return (s);
}

t_plane		*get_planes(int fd, t_scene *scene)
{
	t_plane		*p;
	int			ret;
	char		*line;
	int			limiter;

	limiter = 0;
	p = NULL;
	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp("----", line))
	{
		free(line);
		if (!ft_strcmp("new:", line))
		{
			limiter++;
			if (p == NULL)
				p = get_plane(fd);
			else
				add_plane(p, get_plane(fd), limiter);
		}
	}
	free(line);
	if (ret == -1)
		ft_error(4);
	scene->c_planes = limiter;
	return (p);
}

t_cyl		*get_cylinders(int fd, t_scene *scene)
{
	t_cyl	*c;
	int		ret;
	char	*line;
	int		limiter;

	limiter = 0;
	c = NULL;
	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp("----", line))
	{
		free(line);
		if (!ft_strcmp("new:", line))
		{
			limiter++;
			if (c == NULL)
				c = get_cylinder(fd, NULL, 0);
			else
				add_cylinder(c, get_cylinder(fd, NULL, 0), limiter);
		}
	}
	free(line);
	if (ret == -1)
		ft_error(4);
	scene->c_cyls = limiter;
	return (c);
}

t_cone		*get_cones(int fd, t_scene *scene)
{
	t_cone		*c;
	int			ret;
	char		*line;
	int			limiter;

	limiter = 0;
	c = NULL;
	while ((ret = get_next_line(fd, &line)) > 0 && ft_strcmp("----", line))
	{
		free(line);
		if (!ft_strcmp("new:", line))
		{
			limiter++;
			if (c == NULL)
				c = get_cone(fd);
			else
				add_cone(c, get_cone(fd), limiter);
		}
	}
	free(line);
	if (ret == -1)
		ft_error(4);
	scene->c_cones = limiter;
	return (c);
}
