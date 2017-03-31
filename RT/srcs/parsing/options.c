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

void		parse_options(t_env *e)
{
	int		i;

	if (ft_strncmp(e->scene[4], "	lighting(", 10) != 0)
		ft_error(FILE);
	i = 10;
	LIGHT = (float)ft_atoin(e->scene[4], &i);
	if (e->scene[4][i] != ')')
		ft_error(FILE);
}
