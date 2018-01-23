/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:25:56 by owinckle          #+#    #+#             */
/*   Updated: 2018/01/23 14:25:57 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

int		print_args(char *s, int i, t_env *e, int type)
{
	if (type == 1)
		ft_putnbr(va_arg(e->ap, signed int));
	else if (type == 2)
		ft_putstr(va_arg(e->ap, char *));
	else if (type == 4)
		ft_putstr(ft_strjoin("0x10", ft_itoa_base(va_arg(e->ap, int), 16)));
	i = (type == 3) ? print_width(s, i, e) : i;
	return (i);
}