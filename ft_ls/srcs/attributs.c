/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attributs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 11:33:13 by owinckle          #+#    #+#             */
/*   Updated: 2016/04/13 11:33:14 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_att_check(char f)
{
	if (f == 'l')
		return (1);
	else if (f == 'R')
		return (2);
	else if (f == 'a')
		return (3);
	else if (f == 'r')
		return (4);
	else if (f == 't')
		return (5);
	else if (f == '\0')
		return (0);
	else
		ft_error2(ILLEGAL, f, USAGE);
	return (0);
}

int			ft_attributs(char *flag)
{
	int		f;

	f = 0;
	if (flag[0] == '-')
		f = ft_att_check(flag[1]);
	return (f);
}