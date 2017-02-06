/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 16:46:31 by owinckle          #+#    #+#             */
/*   Updated: 2016/03/31 16:46:32 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbrot(t_env env, int x, int y)
{
	register int	i;
	register double	zr;
	register double zi;

	i = -1;
	env.f.pi = env.mod.ymax - (long double)y * env.zy;
	env.f.pr = env.mod.xmin + (long double)x * env.zx;
	env.f.ni = 0;
	env.f.nrl = 0;
	zr = SQUARE(env.f.nrl);
	zi = SQUARE(env.f.ni);
	while (++i < env.iter && (zr + zi) < 4)
	{
		env.f.ni *= env.f.nrl;
		env.f.ni += env.f.ni + env.f.pi;
		env.f.nrl = zr - zi + env.f.pr;
		zr = SQUARE(env.f.nrl);
		zi = SQUARE(env.f.ni);
	}
	return (i);
}

int		julia(t_env env, int x, int y)
{
	register int			i;
	register long double	zr;
	register long double	zi;

	env.f.ni = env.mod.ymax - (long double)y * env.zy;
	env.f.nrl = env.mod.xmin + (long double)x * env.zx;
	zr = SQUARE(env.f.nrl);
	zi = SQUARE(env.f.ni);
	i = -1;
	while (++i < env.iter && (zr + zi) < 4)
	{
		env.f.ni *= env.f.nrl;
		env.f.ni += env.f.ni + env.f.ci;
		env.f.nrl = zr - zi + env.f.cr;
		zr = SQUARE(env.f.nrl);
		zi = SQUARE(env.f.ni);
	}
	return (i);
}

int		burning_ship(t_env env, int x, int y)
{
	register int			i;
	register long double	zr;
	register long double	zi;

	i = -1;
	env.f.pi = env.mod.ymax - (long double)y * env.zy;
	env.f.pr = env.mod.xmin + (long double)x * env.zx;
	env.f.nrl = env.f.pr;
	env.f.ni = env.f.pi;
	zr = SQUARE(env.f.nrl);
	zi = SQUARE(env.f.ni);
	while (++i < env.iter && (zr + zi) < 4)
	{
		env.f.ni = 2 * fabs(env.f.nrl * env.f.ni);
		env.f.ni -= env.f.pi;
		env.f.nrl = zr - zi + env.f.pr;
		zr = SQUARE(env.f.nrl);
		zi = SQUARE(env.f.ni);
	}
	return (i);
}
