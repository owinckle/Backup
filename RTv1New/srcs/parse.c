/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 13:54:34 by owinckle          #+#    #+#             */
/*   Updated: 2017/02/17 13:54:35 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_obj		*add_link(t_env *e, t_obj *link, int type)
{
	t_obj		*tmp;

	if (type == 1)
	{
		tmp = e->light;
		if (e->light == NULL)
			return (link);
		while (e->light->next != NULL)
			e->light = e->light->next;
		e->light->next = link;
	}
	else
	{
		tmp = e->obj;
		if (e->obj == NULL)
			return (link);
		while (e->obj->next != NULL)
			e->obj = e->obj->next;
		e->obj->next = link;
	}
	return (tmp);
}

static void	check_object(t_env *e, t_obj *tmp)
{
	tmp = e->light;
	while (tmp != NULL)
	{
		if (!(tmp->color.red >= 0 && tmp->color.red <= 255) ||
				!(tmp->color.green >= 0 && tmp->color.green <= 255) ||
				!(tmp->color.blue >= 0 && tmp->color.blue <= 255))
			ft_error(DATA);
		tmp = tmp->next;
	}
	tmp = e->obj;
	while (tmp != NULL)
	{
		if (!(tmp->color.red >= 0 && tmp->color.red <= 255) ||
				!(tmp->color.green >= 0 && tmp->color.green <= 255) ||
				!(tmp->color.blue >= 0 && tmp->color.blue <= 255))
		{
			ft_error(DATA);
			if (tmp->type != 3 && tmp->size < 0)
				ft_error(DATA);
		}
		tmp = tmp->next;
	}
}

static void	parse_scene(t_env *e, int i)
{
	if (ft_strcmp(e->scene[0], "scene") != 0)
		ft_error(FILE);
	if (ft_strcmp(e->scene[1], "{") != 0 || ft_strcmp(e->scene[4], "}") != 0)
		ft_error(FILE);
	if (ft_strncmp(e->scene[2], "	cam_pos(", 9) != 0)
		ft_error(FILE);
	CAMX = (float)ft_atoin(e->scene[2], &i);
	CAMY = (float)ft_atoin(e->scene[2], &i);
	CAMZ = (float)ft_atoin(e->scene[2], &i);
	if (e->scene[2][i] != ')')
		ft_error(FILE);
	if (ft_strncmp(e->scene[3], "	cam_dir(", 9) != 0)
		ft_error(FILE);
	i = 9;
	CAMDX = (float)ft_atoin(e->scene[3], &i);
	CAMDY = (float)ft_atoin(e->scene[3], &i);
	CAMDZ = (float)ft_atoin(e->scene[3], &i);
	if (e->scene[3][i] != ')')
		ft_error(FILE);
	if (ft_strlen(e->scene[5]) != 0)
		ft_error(FILE);
}

static void	parse_objs(t_env *e, int j)
{
	while (j < e->lc - 1)
	{
		if (ft_strcmp(e->scene[j], "	object(light)") == 0)
			e = add_light(e, &j, 6);
		else if (ft_strcmp(e->scene[j], "	object(cone)") == 0)
			e = add_cyclone(e, &j, 7, 1);
		else if (ft_strcmp(e->scene[j], "	object(cylinder)") == 0)
			e = add_cyclone(e, &j, 7, 2);
		else if (ft_strcmp(e->scene[j], "	object(plane)") == 0)
			e = add_plane(e, &j, 6);
		else if (ft_strcmp(e->scene[j], "	object(sphere)") == 0)
			e = add_sphere(e, &j, 7);
	}
}

t_env		*parse(t_env *e)
{
	parse_scene(e, 9);
	if (ft_strcmp(e->scene[6], "content") != 0 ||
			ft_strcmp(e->scene[7], "{") != 0 ||
				ft_strcmp(e->scene[e->lc - 1], "}") != 0)
		ft_error(FILE);
	parse_objs(e, 8);
	check_object(e, NULL);
	return (e);
}
