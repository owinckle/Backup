/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 11:53:11 by owinckle          #+#    #+#             */
/*   Updated: 2016/03/31 11:53:15 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env	*ft_reset(t_env *env)
{
	env->mod.xmax = 2.0;
	env->mod.xmin = -2.0;
	env->mod.ymin = -2.0;
	env->mod.ymax = 1.5;
	env->f.cr = -0.8;
	env->f.ci = 0.156;
	env->f.mx = 0.0;
	env->f.my = 0.0;
	env->f.nrl = 0.0;
	env->f.ni = 0.0;
	env->freq = 0.1;
	env->iter = 16;
	env->color = 2;
	env->zx = ((env->mod.xmax - env->mod.xmin) / (W - 1));
	env->zy = ((env->mod.ymax - env->mod.ymin) / (H - 1));
	return (env);
}

int		ft_type(char *f)
{
	if (ft_strcmp(f, "Mandelbrot") == 0 || ft_strcmp(f, "mandelbrot") == 0)
		return (1);
	if (ft_strcmp(f, "Julia") == 0 || ft_strcmp(f, "julia") == 0)
		return (2);
	if (ft_strcmp(f, "Ship") == 0 || ft_strcmp(f, "ship") == 0)
		return (3);
	return (ft_error(UNK_FRACTAL));
}

void	ft_init_mod(t_env *env)
{
	env->mod.xmax = 2.0;
	env->mod.xmin = -2.0;
	env->mod.ymin = -2.0;
	env->mod.ymax = 1.5;
}

void	ft_init_fract(t_env *env)
{
	env->f.cr = -0.8;
	env->f.ci = 0.156;
	env->f.mx = 0.0;
	env->f.my = 0.0;
	env->f.nrl = 0.0;
	env->f.ni = 0.0;
}

t_env	ft_init_env(char *type)
{
	t_env	env;

	ft_init_fract(&env);
	ft_init_mod(&env);
	env.zx = ((env.mod.xmax - env.mod.xmin) / (W - 1));
	env.zy = ((env.mod.ymax - env.mod.ymin) / (H - 1));
	env.type = ft_type(type);
	env.img.width = W;
	env.img.height = H;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, W, H, "Fract'ol");
	env.img.ptr = mlx_new_image(env.mlx, env.img.width, env.img.height);
	env.img.img = mlx_get_data_addr(env.img.ptr, \
					&env.img.bpp, &env.img.ls, &env.img.endian);
	env.iter = 16;
	env.freq = 0.1;
	env.color = 2;
	env.motion = 1;
	return (env);
}
