/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_testing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opichou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 10:56:21 by opichou           #+#    #+#             */
/*   Updated: 2016/02/12 18:26:15 by opichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static	int		ft_conflict(t_tetros *dst, int abs_i, int o, size_t sz)
{
	int			i;

	i = ft_rel_i(dst, abs_i, o, sz);
	if (i >= 0 && i < 20 && dst->str[i] == '#')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

static	int		fit_map(t_tetros *src, int o, size_t sz)
{
	size_t		i;

	(void)o;
	i = ft_max_dz(src);
	if ((i % 5 + src->pos_x) < sz && (i / 5 + src->pos_y) < sz)
		return (1);
	else
		return (0);
}

static	int		ft_test_map(t_tetros *src, t_tetros *dst, int o, size_t sz)
{
	size_t		dz;
	size_t		i;

	dz = 0;
	i = 0;
	while (dz < 4)
	{
		if (src->str[i] == '#')
		{
			dz++;
			if (ft_conflict(dst, ft_abs_i(src, i, o, sz), o, sz))
				return (0);
		}
		i++;
	}
	return (1);
}

static	int		ft_ts(t_tetros **lst, t_tetros *src, size_t step, size_t sz)
{
	int			o;
	t_tetros	*dst;

	dst = *lst;
	o = 1;
	while ((size_t)o++ < step)
		dst = dst->next;
	o = 0;
	if (fit_map(src, o, sz))
	{
		if (step != 0)
		{
			if (ft_test_map(src, dst, o, sz))
				return (ft_ts(lst, src, step - 1, sz));
			else
				return (0);
		}
		else
			return (1);
	}
	else
		return (0);
}

int				ft_resolve(t_tetros **lst, t_tetros *src, \
		size_t sz, size_t step)
{
	if (!src)
		return (1);
	while (src->pos_y < (int)sz - 1 || (src->pos_y == \
				(int)sz - 1 && src->pos_x < (int)sz))
	{
		if (ft_ts(lst, src, step, sz))
		{
			if (ft_resolve(lst, src->next, sz, step + 1))
				return (1);
		}
		src = ft_pos(src, sz);
		if (src->next)
			ft_reset(&(src->next));
	}
	return (0);
}
