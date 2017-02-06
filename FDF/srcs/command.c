/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 13:51:13 by owinckle          #+#    #+#             */
/*   Updated: 2016/03/28 13:51:16 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*ft_putcolor(int a, int b, int c)
{
	int		*color;

	color = malloc(sizeof(int) * 3);
	color[0] = a;
	color[1] = b;
	color[2] = c;
	return (color);
}

int		**getcolor(char **av, int ac)
{
	int		**color;

	color = malloc(sizeof(int *) * 5);
	if (ac > 4)
	{
		color[0] = malloc(sizeof(int *) * 3);
		color[0][0] = ft_atoi(av[2]);
		color[0][1] = ft_atoi(av[3]);
		color[0][2] = ft_atoi(av[4]);
	}
	else
		color[0] = ft_putcolor(0x000000, 0x808080, 0xFFFFFF);
	color[1] = ft_putcolor(0x0070e0, 0x42c6ff, 0xf3d85e);
	color[2] = ft_putcolor(0xb9280e, 0x3d231a, 0x27160c);
	color[3] = ft_putcolor(0x124511, 0x1a0f0f, 0x888181);
	color[4] = ft_putcolor(0x0000ff, 0x00ff00, 0xff0000);
	return (color);
}

int		**ft_tabmalloc(int x, int y)
{
	int		i;
	int		**array;

	i = -1;
	array = malloc(sizeof(int *) * x);
	while (++i < x)
		array[i] = malloc(sizeof(int *) * y);
	return (array);
}

t_env	*ft_revarray(t_env *e, int sens)
{
	int		i;
	int		j;
	int		**newtab;

	newtab = ft_tabmalloc(e->length, e->width);
	i = -1;
	while (++i < e->width)
	{
		j = -1;
		while (++j < e->length)
		{
			if (sens == 1)
				newtab[e->length - (j + 1)][i] = e->array[i][j];
			else
				newtab[j][e->width - (i + 1)] = e->array[i][j];
		}
	}
	i = e->width;
	e->width = e->length;
	e->length = i;
	free(e->array);
	e->array = newtab;
	return (e);
}
