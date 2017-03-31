/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_caps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 19:17:50 by owinckle          #+#    #+#             */
/*   Updated: 2016/01/06 15:12:27 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_caps_act(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] >= 'a' && str[i + 1] <= 'z')
			str[i + 1] = str[i + 1] - 32;
		if (str[i] == '.' && str[i + 1] >= 'a' && str[i + 1] <= 'z')
			str[i + 1] = str[i + 1] - 32;
		ft_putchar(str[i]);
		i++;
	}
	return (0);
}

void		str_caps(char *str)
{
	int	min;

	min = 0;
	while (str[min])
	{
		if (str[min] >= 'A' && str[min] <= 'Z')
			str[min] = str[min] + 32;
		min++;
	}
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	str_caps_act(str, 0);
}
