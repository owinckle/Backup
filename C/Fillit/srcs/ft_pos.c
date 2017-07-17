/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 18:30:30 by owinckle          #+#    #+#             */
/*   Updated: 2016/02/12 01:01:06 by opichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

t_tetros		*ft_pos(t_tetros *tet, size_t sz)
{
	int			i;

	i = (tet->pos_y * sz + tet->pos_x) + 1;
	tet->pos_y = i / sz;
	tet->pos_x = i % sz;
	return (tet);
}
