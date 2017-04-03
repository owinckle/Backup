/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 10:53:21 by owinckle          #+#    #+#             */
/*   Updated: 2017/03/31 10:53:22 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_obj		*add_link(t_env *e, t_obj *link, int type)
{
	t_obj		*tmp;

	if (type == 0)
	{
		tmp = e->l;
		if (e->l == NULL)
			return (link);
		while (e->l->next != NULL)
			e->l = e->l->next;
		e->l->next = link;
	}
	else
	{
		tmp = e->o;
		if (e->o == NULL)
			return (link);
		while (e->o->next != NULL)
			e->o = e->o->next;
		e->o->next = link;
	}
	return (tmp);
}

static void	check_object(t_env *e, t_obj *tmp)
{
	tmp = e->l;
	while (tmp != NULL)
	{
		if (!(tmp->col.red >= 0 && tmp->col.red <= 255) ||
				!(tmp->col.green >= 0 && tmp->col.green <= 255) ||
				!(tmp->col.blue >= 0 && tmp->col.blue <= 255))
			ft_error(DATA);
		tmp = tmp->next;
	}
	tmp = e->o;
	while (tmp != NULL)
	{
		if (!(tmp->col.red >= 0 && tmp->col.red <= 255) ||
				!(tmp->col.green >= 0 && tmp->col.green <= 255) ||
				!(tmp->col.blue >= 0 && tmp->col.blue <= 255))
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
	if (ft_strcmp(e->scene[1], "{") != 0 || ft_strcmp(e->scene[6], "}") != 0)
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
	if (ft_strlen(e->scene[7]) != 0)
		ft_error(FILE);
	parse_options(e);
}

static void	parse_objs(t_env *e, int j)
{
	while (j < e->lc - 1)
	{
		if (ft_strcmp(e->scene[j], "	object(light)") == 0)
			e = add_light(e, &j, 6);
		else if (ft_strcmp(e->scene[j], "	object(cone)") == 0)
			e = add_cyclone(e, &j, 6, 1);
		else if (ft_strcmp(e->scene[j], "	object(cylinder)") == 0)
			e = add_cyclone(e, &j, 6, 2);
		else if (ft_strcmp(e->scene[j], "	object(plane)") == 0)
			e = add_plane(e, &j, 6);
		else if (ft_strcmp(e->scene[j], "	object(sphere)") == 0)
			e = add_sphere(e, &j, 7);
		else
			ft_error(FILE);
	}
}

t_env		*parse(t_env *e)
{
	parse_scene(e, 9);
	if (ft_strcmp(e->scene[8], "content") != 0 ||
			ft_strcmp(e->scene[9], "{") != 0 ||
				ft_strcmp(e->scene[e->lc - 1], "}") != 0)
		ft_error(FILE);
	parse_objs(e, 10);
	check_object(e, NULL);
	return (e);
}
