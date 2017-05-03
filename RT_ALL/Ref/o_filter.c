/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_filter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 12:14:41 by owinckle          #+#    #+#             */
/*   Updated: 2017/05/02 12:14:41 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_coord		filter(int filter)
{
	t_coord		color;

	color = blacked();
	if (filter == SEPIA)
		color = mult_coord(add_coord(color, (t_coord){112, 66, 20}), 0.5);
	else if (filter == ICE)
		color = mult_coord(add_coord(color, (t_coord){0, 109, 255}), 0.5);
	return (color);
}
