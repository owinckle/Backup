/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inv_col.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 12:34:50 by owinckle          #+#    #+#             */
/*   Updated: 2017/05/22 12:34:50 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vect		col_inv(t_vect color)
{
	t_vect	new;

	new.x = 255 - color.x;
	new.y = 255 - color.y;
	new.z = 255 - color.z;
	return (new);
}
