/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_pt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 12:48:11 by owinckle          #+#    #+#             */
/*   Updated: 2018/01/31 12:48:12 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ftpf_pt_address(t_env *e)
{
	void	*pt;

	pt = va_arg(e->ap, void *);
	e->f &= ~F_SHARP;
	e->min_length -= (e->f & F_ZERO ? 2 : 0);
	e->padding = (e->printed > e->min_length - 3) ? 0 :
		e->min_length - 3 - e->printed;
	e->f |= F_SHARP;
	e->f |= F_POINTER;
	ftpf_itoabase((uintmax_t)pt, 16, e);
}
