/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 00:39:13 by dbirtel           #+#    #+#             */
/*   Updated: 2017/03/30 00:39:40 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		red_cross(void)
{
	ft_bs(9, "\x1b[31m[TERMINATED]", 1);
	exit(0);
	return (0);
}

int		key_press(int key, t_env *e)
{
	(void)e;
	if (key == ESC)
	{
		ft_bs(9, "\x1b[31m[TERMINATED]", 1);
		exit(0);
	}
	return (0);
}
