/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 13:30:43 by owinckle          #+#    #+#             */
/*   Updated: 2016/02/12 19:40:01 by opichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int			ft_error(void)
{
	ft_putendl("error");
	exit(1);
}

void		ft_tno(char *map, int i)
{
	if (map[i] != '\n')
		ft_error();
}

void		ft_dbend(char *map)
{
	if (*(map - 1) == '\n' && *(map - 2) == '\n')
		ft_error();
}
