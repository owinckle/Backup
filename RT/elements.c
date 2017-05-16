/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 00:28:00 by dbirtel           #+#    #+#             */
/*   Updated: 2017/04/10 09:32:20 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	add_cam(char *line, int count, t_scene *s)
{
	count_num(line, 9, count);
	s->cam.pos = get_coord(line, 0);
	s->cam.vector_dir = vec_norm(get_coord(line, 3));
	s->cam.vector_up = vec_norm(get_coord(line, 6));
	s->cam.vector_right = \
	vec_norm(cross(s->cam.vector_up, s->cam.vector_dir));
	s->cam.vector_up = \
	vec_norm(cross(s->cam.vector_right, s->cam.vector_dir));
}

void	add_lights(char *line, int count, t_scene *s)
{
	t_li	*tmp;
	t_li	*light;

	count_num(line, 3, count);
	if (!(light = (t_li *)malloc(sizeof(t_li))))
		error(ERR_MALLOC);
	light->pos = get_coord(line, 0);
	light->next = NULL;
	if (s->spots == NULL)
		s->spots = light;
	else
	{
		tmp = s->spots;
		light->next = tmp;
		s->spots = light;
	}
}

void	add_obj(char *line, int count, t_scene *s)
{
	if (!ft_strncmp(line, "SPHERE", 6))
		add_sphere(line + 6, count, s);
	else if (!ft_strncmp(line, "PLANE", 5))
		add_plane(line + 5, count, s);
	else if (!ft_strncmp(line, "CONE", 4))
		add_cone(line + 4, count, s);
	else if (!ft_strncmp(line, "CYLINDER", 8))
		add_cylinder(line + 8, count, s);
	else
		error_parsing(count, "add_obj, in file add_obj.c\n");
}
