/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 11:09:08 by owinckle          #+#    #+#             */
/*   Updated: 2016/04/12 11:09:09 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


int		ft_file_exist(const char *file)
{
	struct stat	buffer;
	int			exist;

	exist = stat(file, &buffer);
	if (exist == 0)
		return (1);
	else
		return (-1);
}

int		main(int ac, char **av)
{
	int		flag;

	flag = 0;
	if (ac == 1)
		ft_simple("./", flag);
	else if (ac == 2)
	{
		flag = ft_attributs(av[1]);
		if (flag == 0)
			ft_simple(av[1], flag);
		else
			ft_simple("./", flag);
	}
	(void)av;
	return (0);
}