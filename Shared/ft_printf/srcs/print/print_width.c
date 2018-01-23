/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:24:16 by owinckle          #+#    #+#             */
/*   Updated: 2018/01/23 15:24:16 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

int		print_width(char *s, int i, t_env *e)
{
	int count[2];

	count[0] = 1;
	count[1] = ft_atoi(&s[i++]);
	if (count[1] > 0)
	{
		while (count[0]++ < count[1])
		ft_putchar(' ');
		if (s[i] == 'd' || s[i] == 'D')
			i = print_args(s, i, e, 1);
		if (s[i] == 's' || s[i] == 'S')
			i = print_args(s, i, e, 2);
	}
	else if (count[1] < 0)
	{
		i += 1;
		if (s[i] == 'd' || s[i] == 'D')
			i = print_args(s, i, e, 1);
		if (s[i] == 's' || s[i] == 'S')
			i = print_args(s, i, e, 2);
		count[0] -= 2;
		while (count[1]++ < count[0])
		ft_putchar(' ');
	}
	return(i);
}