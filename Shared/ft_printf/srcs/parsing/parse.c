/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:24:11 by owinckle          #+#    #+#             */
/*   Updated: 2018/01/23 12:24:17 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

void	parse(char *s, int i, t_env e)
{
	while (s[i] != '\0')
	{
		i = parse_att(s, i);
		if (s[i] == '%')
			ft_putchar('%');
		else if (s[i] == 'd' || s[i] == 'D' || s[i] == 'i')
			i = print_args(s, i, &e, 1);
		else if (s[i] == 's' || s[i] == 'S')
			i = print_args(s, i, &e, 2);
		else if ((s[i] >= 49 && s[i] <= 57) || s[i] == '-')
			i = print_args(s, i, &e, 3);
		else if (s[i] == 'p')
			i = print_args(s, i, &e, 4);
		else if (i == -1)
			break ;
		i++;
	}
}

int		parse_att(char *s, int i)
{
	while (s[i] != '\0')
	{
		if (s[i] == '%')
			return (i + 1);
		ft_putchar(s[i]);
		i++;
	}
	return (-1);
}