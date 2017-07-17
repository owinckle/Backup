/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 12:08:13 by owinckle          #+#    #+#             */
/*   Updated: 2016/02/12 19:47:24 by opichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUF_SIZE 4096
#include "libft.h"
#include "fillit.h"

t_tetros		*getfile(int fd)
{
	int			ret;
	char		buf[BUF_SIZE + 1];
	t_tetros	*liste;

	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	liste = norme(buf, 0, 1, 1);
	if (!liste)
		ft_error();
	return (liste);
}

int				main(int ac, char **av)
{
	int			fd;
	t_tetros	*liste;
	size_t		sz;

	sz = 2;
	if (ac != 2)
	{
		ft_putendl("usage: ./fillit source_file");
		exit(1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error();
	liste = getfile(fd);
	while (ft_resolve(&liste, liste, sz, 0) == 0)
	{
		ft_reset(&liste);
		sz++;
	}
	if (close(fd) == -1)
		return (ft_error());
	ft_map_r(&liste, sz, -1);
	return (0);
}
