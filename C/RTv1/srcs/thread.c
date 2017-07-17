/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 17:00:05 by owinckle          #+#    #+#             */
/*   Updated: 2017/02/20 17:00:07 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_obj	*th_obj(t_obj *node)
{
	t_obj		*objs;

	if (!(objs = (t_obj*)malloc(sizeof(t_obj))))
		ft_error(MALLOC);
	if (objs && node)
	{
		objs->type = node->type;
		objs->size = node->size;
		objs->rot = (t_vect){node->rot.x, node->rot.y, node->rot.z};
		objs->pos = (t_vect){node->pos.x, node->pos.y, node->pos.z};
		objs->color.red = node->color.red;
		objs->color.green = node->color.green;
		objs->color.blue = node->color.blue;
		objs->next = NULL;
	}
	if (objs && node->next)
		objs->next = th_obj(node->next);
	return (objs);
}

t_th			*init_thread(t_env *e)
{
	t_th		*th;

	if (!(th = (t_th*)malloc(sizeof(t_th))))
		ft_error(MALLOC);
	th->obj = th_obj(e->obj);
	th->light = th_obj(e->light);
	th->cam_dir = (t_vect){CAMDX, CAMDY, CAMDZ};
	th->cam_pos = (t_vect){CAMX, CAMY, CAMZ};
	th->mlx = e->mlx;
	return (th);
}

int				free_lists(t_obj *light, t_obj *obj)
{
	t_ob	*fst;
	t_ob	*tmp;

	fst = obj;
	while (fst != NULL)
	{
		tmp = fst->next;
		free(fst);
		fst = tmp;
	}
	fst = light;
	while (fst != NULL)
	{
		tmp = fst->next;
		free(fst);
		fst = tmp;
	}
	return (-1);
}
