/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 15:11:10 by owinckle          #+#    #+#             */
/*   Updated: 2016/03/29 15:11:11 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>

# define TITLE			"Fract'ol - "
# define USAGE			"Usage: ./fractol [Mandelbrot | Julia | Ship]"
# define UNK_FRACTAL	"Available Fractals :\n- Mandlebrot\n- Julia\n- Ship"
# define SQUARE(x) x * x
# define W					512
# define H					512
# define ESC_KEY			53
# define MOTION				48
# define INCERASE_ITER		69
# define DECREASE_ITER		78
# define KEYBOARD_MAX_FREQ	24
# define KEYBOARD_MIN_FREQ	27
# define KEY_UP				126
# define KEY_DOWN			125
# define KEY_RIGHT			124
# define KEY_LEFT			123
# define NEXT_FRACT			49
# define ENTER_RESET		36
# define MB1				1
# define MB2				2
# define MWU				5
# define MWD				4
# define C					8

typedef struct		s_mod
{
	double			xmin;
	double			xmax;
	double			ymin;
	double			ymax;
	double			omx;
	double			omy;
}					t_mod;

typedef struct		s_img
{
	void			*ptr;
	char			*img;
	int				bpp;
	int				ls;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef struct		s_fract
{
	double			cr;
	double			ci;
	double			pr;
	double			pi;
	double			nrl;
	double			ni;
	double			orl;
	double			oi;
	double			zoom;
	double			mx;
	double			my;
}					t_fract;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				type;
	int				motion;
	int				iter;
	int				color;
	double			freq;
	double			zx;
	double			zy;
	t_mod			mod;
	t_img			img;
	t_fract			f;
}					t_env;

int					ft_error(char *error);
t_env				ft_init_env(char *type);
int					ft_type(char *f);
int					ft_keyhook(int keycode, t_env *env);
int					ft_expose_hook(t_env *e);
int					ft_fractal(t_env env, int x, int y);
int					clr_get(int i, t_env env);
void				pixel_put(t_env env, int x, int y, int clr);
int					ft_draw_fract(t_env env);
int					mandelbrot(t_env env, int x, int y);
int					julia(t_env env, int x, int y);
int					burning_ship(t_env env, int x, int y);
int					ft_eventkey(int keycode, t_env *env);
t_env				*ft_reset(t_env *env);
int					ft_mousehook(int button, int x, int y, t_env *env);
int					ft_motionhook(int x, int y, t_env *env);
void				ft_display_menu(void);

#endif
