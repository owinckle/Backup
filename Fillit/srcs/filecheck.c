/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 13:28:34 by owinckle          #+#    #+#             */
/*   Updated: 2016/03/04 15:58:59 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static	int				ft_ct(char *m, size_t i)
{
	int j;

	j = 0;
	if (m[i - 1] == '#')
		j++;
	if (m[i - 5] == '#')
		j++;
	if (m[i + 1] == '#')
		j++;
	if (m[i + 5] == '#')
		j++;
	return (j);
}

int						four(char *map)
{
	int	i;
	int	hashtag;
	int test;

	hashtag = 0;
	i = 0;
	test = 0;
	while (map[i])
	{
		if (map[i] == '#')
		{
			hashtag++;
			test += ft_ct(map, i);
			if (test < 6 && hashtag == 4)
				ft_error();
		}
		else if (map[i] != '.' && map[i] != '\n')
			ft_error();
		if (hashtag != 4 && i >= 19)
			ft_error();
		if (i == 19 && hashtag == 4)
			return (1);
		i++;
	}
	return (0);
}

static	t_tetros		*ft_fillit_helper(char *input, t_tetros **liste)
{
	t_tetros	*ptr;
	t_tetros	*new;
	char		*tmp;

	ptr = malloc(sizeof(t_tetros));
	if (!ptr || !input)
		ft_error();
	tmp = ft_strndup(input, 20);
	new = ft_tetro_new(ft_optimize(tmp));
	if (!new || !tmp)
		ft_error();
	if (*liste)
		return (ft_tetr_forceadd(liste, new));
	else
		return (new);
}

int						end(char *map, int col, int line)
{
	(void)map;
	if (col % 5 != 0 || line % 5 != 1)
		ft_error();
	return (1);
}

t_tetros				*norme(char *map, int i, int col, int line)
{
	static	t_tetros	*ret;

	while (*map)
	{
		if (map[i] != '.' && map[i] != '#' && col <= 4 && line <= 4)
			ft_error();
		if (col % 5 == 0 || line % 5 == 0)
		{
			ft_tno(map, i);
			if (col % 5 == 0)
				line++;
			if (line % 5 == 0)
			{
				line++;
				if (end(map, col, line) && four(map))
					ret = ft_fillit_helper(map, &ret);
				map += (i + 2);
				i = -1;
			}
		}
		col++;
		i++;
	}
	ft_dbend(map);
	return (ret);
}
