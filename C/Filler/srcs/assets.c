#include "filler.h"

int		strstart(char *str, char *start)
{
	int		i;

	i = 0;
	while(str[i] && start[i])
	{
		if (start[i] != str[i])
			return (0);
		i++;
	}
	if (start[i])
		return (0);
	return (1);
}

int		is_number(char c)
{
	if (c >= 48 && c <= 57)
		return (0);
	return (1);
}

void	output_filler(t_piece *p, t_map *map)
{
	ft_putnbr(p->final.y);
	ft_putchar(' ');
	ft_putnbr(p->final.x);
	ft_putchar('\n');
	map->pos_player.x = p->final.x;
	map->pos_player.y = p->final.y;
}

int		check_bis(t_piece *p, int count, int i, int i2)
{
	if (count == 1)
	{
		p->final.x = i2;
		p->final.y = i;
		return (0);
	}
	return (1);
}


int		check(int y, int x, t_map *map, t_piece *p)
{
	int		yy;
	int		xx;
	int		count;

	yy = -1;
	count = 0;
	if (y + p->size.y > map->map_size.y || x + p->size.x > map->map_size.x)
		return (1);
	while (++yy <= (p->size.y - 1))
	{
		xx = -1;
		while (++xx <= (p->size.x - 1))
		{
			if (p->piece[yy][xx] == '*' && (map->map[y + yy][x + xx] ==
				map->enemy[0] || map->map[y + yy][x + xx] ==
				map->enemy[0] - 32))
				return (1);
			if (p->piece[yy][xx] == '*' && (map->map[y + yy][x + xx] ==
				map->player[0] || map->map[y + yy][x + xx] ==
				map->player[0] - 32))
				count++;
		}
	}
	if (check_bis(p, count, y, x) == 0)
		return (0);
	return (1);
}