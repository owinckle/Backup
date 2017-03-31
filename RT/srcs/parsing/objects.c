/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 11:38:38 by owinckle          #+#    #+#             */
/*   Updated: 2017/03/31 11:38:39 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_obj	*col_pos(t_env *e, t_obj *link, int j)
{
	int		i;

	i = 6;
	if (ft_strncmp(e->scene[j + 2], "		col(", 6) != 0 ||
			ft_strncmp(e->scene[j + 3], "		pos(", 6) != 0)
		ft_error(FILE);
	link->color.red = ft_atoin(e->scene[j + 2], &i);
	link->color.green = ft_atoin(e->scene[j + 2], &i);
	link->color.blue = ft_atoin(e->scene[j + 2], &i);
	if (e->scene[j + 2][i] != ')')
		ft_error(FILE);
	i = 6;
	link->pos.x = ft_atoin(e->scene[j + 3], &i);
	link->pos.y = ft_atoin(e->scene[j + 3], &i);
	link->pos.z = ft_atoin(e->scene[j + 3], &i);
	if (e->scene[j + 3][i] != ')')
		ft_error(FILE);
	return (link);
}

t_env			*add_light(t_env *e, int *j, int i)
{
	t_obj		*link;

	if (!(link = (t_obj*)malloc(sizeof(t_obj))))
		ft_error(MALLOC);
	if (ft_strcmp(e->scene[*j + 1], "	{") != 0 ||
			ft_strcmp(e->scene[*j + 4], "	}") != 0)
		ft_error(FILE);
	if (ft_strncmp(e->scene[*j + 2], "		col(", 6) != 0 ||
			ft_strncmp(e->scene[*j + 3], "		pos(", 6) != 0)
		ft_error(FILE);
	link->color.red = ft_atoin(e->scene[*j + 2], &i);
	link->color.green = ft_atoin(e->scene[*j + 2], &i);
	link->color.blue = ft_atoin(e->scene[*j + 2], &i);
	if (e->scene[*j + 2][i] != ')')
		ft_error(FILE);
	i = 6;
	link->pos.x = ft_atoin(e->scene[*j + 3], &i);
	link->pos.y = ft_atoin(e->scene[*j + 3], &i);
	link->pos.z = ft_atoin(e->scene[*j + 3], &i);
	if (e->scene[*j + 3][i] != ')')
		ft_error(FILE);
	link->next = NULL;
	e->light = add_link(e, link, 1);
	*j += 5;
	return (e);
}

t_env			*add_cyclone(t_env *e, int *j, int i, int t)
{
	t_obj		*link;

	if (!(link = (t_obj*)malloc(sizeof(t_obj))))
		ft_error(MALLOC);
	if (ft_strcmp(e->scene[*j + 1], "	{") != 0 ||
			ft_strcmp(e->scene[*j + 6], "	}") != 0 || (link->type = t) != t)
		ft_error(FILE);
	link = col_pos(e, link, *j);
	if (ft_strncmp(e->scene[*j + 4], "		rot(", 6) != 0)
		ft_error(FILE);
	link->rot.x = (float)ft_atoin(e->scene[*j + 4], &i);
	link->rot.y = (float)ft_atoin(e->scene[*j + 4], &i);
	link->rot.z = (float)ft_atoin(e->scene[*j + 4], &i);
	if (e->scene[*j + 4][i] != ')')
		ft_error(FILE);
	if (ft_strncmp(e->scene[*j + 5], "		size(", 7) != 0)
		ft_error(FILE);
	i = 7;
	link->size = ft_atoin(e->scene[*j + 5], &i);
	if (e->scene[*j + 5][i] != ')')
		ft_error(FILE);
	link->next = NULL;
	e->obj = add_link(e, link, 2);
	*j += 7;
	return (e);
}

t_env			*add_plane(t_env *e, int *j, int i)
{
	t_obj		*link;

	if (!(link = (t_obj*)malloc(sizeof(t_obj))))
		ft_error(MALLOC);
	link->type = 3;
	if (ft_strcmp(e->scene[*j + 1], "	{") != 0 ||
			ft_strcmp(e->scene[*j + 5], "	}") != 0)
		ft_error(FILE);
	link = col_pos(e, link, *j);
	if (ft_strncmp(e->scene[*j + 4], "		rot(", 6) != 0)
		ft_error(FILE);
	link->rot.x = (float)ft_atoin(e->scene[*j + 4], &i);
	link->rot.y = (float)ft_atoin(e->scene[*j + 4], &i);
	link->rot.z = (float)ft_atoin(e->scene[*j + 4], &i);
	if (e->scene[*j + 4][i] != ')')
		ft_error(FILE);
	link->next = NULL;
	e->obj = add_link(e, link, 2);
	*j += 6;
	return (e);
}

t_env			*add_sphere(t_env *e, int *j, int i)
{
	t_obj		*link;

	if (!(link = (t_obj*)malloc(sizeof(t_obj))))
		ft_error(MALLOC);
	link->type = 4;
	if (ft_strcmp(e->scene[*j + 1], "	{") != 0 ||
			ft_strcmp(e->scene[*j + 5], "	}") != 0)
		ft_error(FILE);
	link = col_pos(e, link, *j);
	if (ft_strncmp(e->scene[*j + 4], "		size(", 7) != 0)
		ft_error(FILE);
	link->size = ft_atoin(e->scene[*j + 4], &i);
	if (e->scene[*j + 4][i] != ')')
		ft_error(FILE);
	link->next = NULL;
	e->obj = add_link(e, link, 2);
	*j += 6;
	return (e);
}
