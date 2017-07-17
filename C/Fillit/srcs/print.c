/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 14:06:56 by owinckle          #+#    #+#             */
/*   Updated: 2016/02/12 19:43:58 by opichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static void	ft_putht(t_tetros *new, size_t sz, char **map, char abc)
{
	int		i;
	int		z;
	int		ht;
	char	*tmp;

	i = 0;
	ht = 0;
	tmp = *map;
	while (ht < 4)
	{
		z = ft_abs_i(new, i, 0, sz + 1);
		if (new->str[i] == '#')
		{
			tmp[z] = abc;
			ht++;
		}
		i++;
	}
}

char		*ft_map_r(t_tetros **alst, size_t sz, int i)
{
	char		*map;
	t_tetros	*new;
	char		abc;

	new = *alst;
	abc = 'A';
	map = malloc(((sz + 1) * sz + 1) * sizeof(char));
	if (map)
	{
		map = ft_memset(map, '.', (sz + 1) * sz);
		while (new)
		{
			ft_putht(new, sz, &map, abc);
			new = new->next;
			abc++;
		}
		while (i++ <= (int)sz)
			map[(i + 1) * (sz + 1) - 1] = '\n';
		map[sz * (sz + 1)] = '\0';
		ft_putstr(map);
		free(map);
	}
	return (map);
}
