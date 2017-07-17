/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 10:18:18 by owinckle          #+#    #+#             */
/*   Updated: 2016/04/06 10:18:19 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_error(char *error)
{
	ft_putendl(error);
	exit(1);
}

int		ft_error2(char *error, char c, char *error2)
{
	ft_putstr(error);
	ft_putcharn(c);
	ft_putendl(error2);
	exit(1);
}

int		ft_error3(char *error, char *error2, char *error3)
{
	ft_putstr(error);
	ft_putstr(error2);
	ft_putendl(error3);
	exit(1);
}