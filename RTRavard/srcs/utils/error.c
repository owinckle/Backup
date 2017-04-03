/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 11:29:23 by owinckle          #+#    #+#             */
/*   Updated: 2016/10/18 11:29:23 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	error_malloc(void)
{
	write(1, "Malloc Error\n", 13);
	exit(-1);
}

static void	error_arg(void)
{
	write(1, "Usage: ./rtv1 [file]\n", 21);
	exit(-1);
}

static void	error_file(void)
{
	write(1, "File Error\n", 11);
	exit(-1);
}

static void	error_data(void)
{
	write(1, "Data Error\n", 11);
	exit(-1);
}

void		ft_error(int error)
{
	if (error == 1)
		error_arg();
	if (error == 2)
		error_malloc();
	if (error == 3)
		error_file();
	if (error == 4)
		error_data();
}
