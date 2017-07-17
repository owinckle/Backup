/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventkey.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 13:52:16 by owinckle          #+#    #+#             */
/*   Updated: 2016/03/28 13:52:17 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_eventkey2(t_env *e, int keycode)
{
	if (keycode == 65361)
		e->cnum -= (e->cnum == 0 ? -4 : 1);
	else if (keycode == T_THEME)
		e->cnum += (e->cnum == 4 ? -4 : 1);
	else if (keycode == P_PROJECT)
		e->tpro += (e->tpro == 1 ? -1 : 1);
	else if (keycode == F_WIRES)
		e->wire = (e->wire == 1 ? 0 : 1);
	e->cte3 = e->cte1 / 2.0;
	e->cte4 = e->cte2 / 2.0;
}

int		ft_eventkey(t_env *e, int keycode)
{
	if (keycode == LEFT_KEY || keycode == D_KEY)
		e->x_offset -= 100;
	else if (keycode == RIGHT_KEY || keycode == A_KEY)
		e->x_offset += 100;
	else if (keycode == UP_KEY || keycode == S_KEY)
		e->y_offset -= 100;
	else if (keycode == DOWN_KEY || keycode == W_KEY)
		e->y_offset += 100;
	else if (keycode == IN_ZOOM && e->scale < 150)
		e->scale *= 1.5;
	else if (keycode == OUT_ZOOM && e->scale / 1.5 > 0.5)
		e->scale /= 1.5;
	else if (keycode == FOUR_LOW)
		e->height -= 1.0;
	else if (keycode == SIX_HIGH)
		e->height += 1.0;
	else if (keycode == NINE_ROTATE_RIGHT)
		e = ft_revarray(e, 1);
	else if (keycode == SEVEN_ROTATE_LEFT)
		e = ft_revarray(e, -1);
	else
		ft_eventkey2(e, keycode);
	return (0);
}
