/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 13:52:35 by owinckle          #+#    #+#             */
/*   Updated: 2016/03/28 13:52:36 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	int		fd;
	int		**array;
	int		len;
	int		width;
	int		**color;

	len = 0;
	width = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			ft_error(ft_strjoin(NO_FILE, av[1]));
		array = get_array(fd, &len, &width);
		close(fd);
		color = getcolor(av, ac);
		if (array)
			ft_display_tab(array, len, width, color);
		return (0);
	}
	if (ac != 2)
		ft_error(USAGE);
	return (-1);
}
