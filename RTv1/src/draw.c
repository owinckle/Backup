/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 10:54:12 by owinckle          #+#    #+#             */
/*   Updated: 2016/10/28 10:54:13 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	get_x(int x)
{
	double	rslt;

	if (WIDTH > HEIGHT)
		rslt = ((x + 0.5) / WIDTH) * ASPR - (((WIDTH - HEIGHT) /
		(double)HEIGHT) / 2);
	else
		rslt = (x + 0.5) / (double)WIDTH;
	return (rslt);
}

double	get_y(int y)
{
	double	rslt;

	if (HEIGHT > WIDTH)
		rslt = ((y + 0.5) / HEIGHT) / ASPR - (((HEIGHT - WIDTH) /
		(double)WIDTH) / 2);
	else
		rslt = (y + 0.5) / HEIGHT;
	return (rslt);
}

t_color	*get_color_at(t_env *e, int x, int y)
{
	t_color		*color;
	double		xamnt;
	double		yamnt;
	t_ray		*ray;

	xamnt = get_x(x);
	yamnt = get_y(y);
	ray = get_ray(e, xamnt, yamnt);
	color = find_color_at(e, ray);
	return (color);
}

void	ft_draw(t_env *e)
{
	int			x;
	int			y;
	t_color		*color;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			color = get_color_at(e, x, y);
			mlx_put_pxl(x, y, get_color_nb(color), e);
			y++;
		}
		if (x % 2 == 0)
			ft_bs(3, "\x1b[31m[x]", 0);
		else
			ft_bs(3, "\x1b[31m[+]", 0);
		x++;
	}
	ft_bs(3, "\x1b[32m[RUNNING]", 0);
}
