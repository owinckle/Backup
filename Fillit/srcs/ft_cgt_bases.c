/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cgt_bases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opichou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 15:17:18 by opichou           #+#    #+#             */
/*   Updated: 2016/02/12 18:27:42 by opichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int				ft_abs_i(t_tetros *src, size_t i, int o, size_t sz)
{
	return (sz * ((i / 5) + src->pos_y - (o / sz)) + ((i % 5) + \
				src->pos_x - (o % sz)));
}

int				ft_rel_i(t_tetros *dst, size_t abs_i, int o, size_t sz)
{
	int			i;
	int			j;

	(void)o;
	i = ((abs_i % sz) - dst->pos_x);
	j = ((abs_i / sz) - dst->pos_y);
	if (i < 4 && i >= 0 && j >= 0 && j < 4)
		return (i + j * 5);
	else
		return (-1);
}

void			ft_reset(t_tetros **lst)
{
	t_tetros	*tmp;

	tmp = *lst;
	while (tmp)
	{
		tmp->pos_x = 0;
		tmp->pos_y = 0;
		tmp = tmp->next;
	}
}

int				ft_max_dz(t_tetros *src)
{
	size_t		i;
	size_t		j;
	size_t		ht;
	size_t		dz;

	i = 0;
	j = 0;
	ht = 0;
	dz = 0;
	while (ht < 4)
	{
		if (src->str[i] == '#')
		{
			if (dz < (i % 5))
				dz = (i % 5);
			if (j < (i / 5))
				j = (i / 5);
			ht++;
		}
		i++;
	}
	return (j * 5 + dz);
}
