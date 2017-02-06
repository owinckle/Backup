/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_orgn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:03:27 by owinckle          #+#    #+#             */
/*   Updated: 2016/02/09 16:48:30 by opichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int	ft_orgn(t_tetros **lst, size_t sz, size_t step)
{
	t_tetros	*orgn;
	int			x;
	int			y;

	orgn = *lst;
	x = orgn->pos_x;
	y = orgn->pos_y;
	orgn = orgn->next;
	while (step > 0 && orgn)
	{
		if (x > orgn->pos_x)
			x = orgn->pos_x;
		if (y > orgn->pos_x)
			y = orgn->pos_x;
		step--;
		orgn = orgn->next;
	}
	return (x + (y * (sz)));
}
