/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 16:26:17 by owinckle          #+#    #+#             */
/*   Updated: 2016/10/18 16:26:18 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		key_press(int k, t_env *e)
{
	if (k == KEY_ESC)
	{
		mlx_destroy_window(e->mlx.mlx, e->mlx.win);
		ft_bs(9, "\x1b[33m[TERMINATED]", 1);
		exit(0);
	}
	return (0);
}

void	mlx_put_pxl(int x, int y, int color, t_env *e)
{
	unsigned int	new_color;
	int				i;

	new_color = mlx_get_color_value(e->mlx.mlx, color);
	i = x * 4 + y * e->mlx.sl;
	e->mlx.pxl[i] = (new_color & 0xFF);
	e->mlx.pxl[i + 1] = (new_color & 0xFF00) >> 8;
	e->mlx.pxl[i + 2] = (new_color & 0xFF0000) >> 16;
}

double	ft_atodouble(char **str)
{
	double	value;
	int		sign;
	int		i;

	value = 0;
	sign = (**str == '-') ? -1 : 1;
	if (**str == '-' || **str == '+')
		(*str)++;
	while (ft_isdigit(**str))
	{
		value = value * 10 + (**str - '0');
		(*str)++;
	}
	if (**str == '.')
	{
		(*str)++;
		i = 1;
		while (ft_isdigit(**str))
		{
			value += (double)(**str - '0') / pow(10, i++);
			(*str)++;
		}
	}
	*str += 2;
	return (value * sign);
}

int		open_file(char *file)
{
	int		fd;

	fd = open(file, O_DIRECTORY);
	if (fd >= 0)
		ft_error(3);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(3);
	return (fd);
}
