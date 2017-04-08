/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 11:17:01 by owinckle          #+#    #+#             */
/*   Updated: 2017/03/31 11:17:01 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			parse_options(t_env *e)
{
	int		i;

	if (ft_strncmp(e->scene[4], "	lighting(", 10) != 0)
		ft_error(FILE);
	i = 10;
	LIGHT = (float)ft_atoin(e->scene[4], &i);
	if (e->scene[4][i] != ')')
		ft_error(FILE);
	if (ft_strncmp(e->scene[5], "	antialiasing(", 14) != 0)
		ft_error(FILE);
	i = 14;
	e->antialiasing = (float)ft_atoin(e->scene[5], &i);
	if (e->scene[5][i] != ')')
		ft_error(FILE);
}

static t_obj	*effect_2(t_obj *link, int j, int i, t_env *e)
{
	if (ft_strncmp(e->scene[j + 4], "		transparent(", 14) != 0)
		ft_error(FILE);
	link->transparent = ft_atoin(e->scene[j + 4], &i);
	if (e->scene[j + 4][i] != ')')
		ft_error(FILE);
	return (link);
}

t_obj			*parse_effects(t_obj *link, int j, int i, t_env *e)
{
	if (ft_strncmp(e->scene[j], "		shine(", 8) != 0)
		ft_error(FILE);
	link->shine = ft_atoin(e->scene[j], &i);
	if (e->scene[j][i] != ')')
		ft_error(FILE);
	if (ft_strncmp(e->scene[j + 1], "		reflection(", 13) != 0)
		ft_error(FILE);
	i = 13;
	link->reflection = ft_atoin(e->scene[j + 1], &i);
	if (e->scene[j + 1][i] != ')')
		ft_error(FILE);
	if (ft_strncmp(e->scene[j + 2], "		negative(", 11) != 0)
		ft_error(FILE);
	i = 11;
	link->negative = ft_atoin(e->scene[j + 2], &i);
	if (e->scene[j + 2][i] != ')')
		ft_error(FILE);
	if (ft_strncmp(e->scene[j + 3], "		cel_shading(", 14) != 0)
		ft_error(FILE);
	i = 14;
	link->cel_shading = ft_atoin(e->scene[j + 3], &i);
	if (e->scene[j + 3][i] != ')')
		ft_error(FILE);
	return (effect_2(link, j, 14, e));
}
