/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 16:09:47 by owinckle          #+#    #+#             */
/*   Updated: 2016/03/31 16:09:49 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put(t_env env, int x, int y, int clr)
{
	int		pos;

	if (x >= 0 && x < W && y >= 0 && y < H)
	{
		pos = (x * env.img.bpp / 8) + (y * env.img.ls);
		env.img.img[pos] = clr % 256;
		env.img.img[pos + 1] = (clr >> 8) % 256;
		env.img.img[pos + 2] = (clr >> 16) % 256;
	}
}

int		clr_get(int i, t_env env)
{
	register double	c;
	register int	r;
	register int	g;
	register int	b;

	if (i == env.iter)
		return (0);
	c = env.freq * (i);
	r = cos(c) * 127 + 128;
	g = cos(c + env.color) * 127 + 128;
	b = cos(c + env.color + env.color) * 127 + 128;
	return ((r << 16) + (b << 8) + g);
}

void	ft_display_menu(void)
{
	ft_putstr("\x1b[36m\
_____________________________________\n\
\x1b[31mCONTROLS:\n\
\x1b[32mMouvements: \x1b[33mMandelbrot & Julia\x1b[34m\n\
	\x1b[34mY : Arrow: \x1b[35mUP\x1b[34m, \x1b[35mDOWN\n\
	\x1b[34mX : Arrow: \x1b[35mLEFT\x1b[34m, \x1b[35mRIGHT\n\
\n\
\x1b[32mZoom:\x1b[34m\n\
	\x1b[34mIN: MOUSE: \x1b[35mMB1\n\
	\x1b[34mOUT: MOUSE: \x1b[35mMB2\n\
	\x1b[34mIN: WHEEL: \x1b[35mUP\n\
	\x1b[34mOUT: WHEEL: \x1b[35mDOWN\n\
\n\
\x1b[32mVisual:\x1b[34m\n\
	\x1b[34mITERATIONS: Keypad \x1b[35m+\x1b[34m,\x1b[35m-\n\
	\x1b[34mFREQUENCE: Keyboard: \x1b[35m+ \x1b[34m, \x1b[35m-\n\
	\x1b[34mCOLOR: Keyboard: \x1b[35mC\n\
	\x1b[34mMOTION: Keyboard: \x1b[35m TAB \x1b[33mJulia\n\
\x1b[36m_____________________________________\n\
	\n");
}
