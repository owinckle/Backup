/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 22:57:34 by dbirtel           #+#    #+#             */
/*   Updated: 2017/04/06 01:25:32 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	is_fd_valid(int fd)
{
	char	*buffer;
	int		r;

	buffer = NULL;
	if (fd < 0)
		error(ERR_FD);
	r = read(fd, buffer, 1);
	if (r == 0)
		error(ERR_VOID);
}

void	error_parsing(int line, char *str)
{
	ft_putstr("Parsing error on line ");
	ft_putstr(ft_itoa(line));
	ft_putstr(" found in function ");
	ft_putstr(str);
	exit(0);
}

void	error(char *str)
{
	ft_putstr(str);
	exit(0);
}
