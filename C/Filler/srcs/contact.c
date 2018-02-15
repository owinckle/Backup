#include "filler.h"

int			count_contact(t_map *map, t_piece *p, int y, int x)
{
	int		yy;
	int		xx;
	int		o;

	yy = -1;
	p->nb_contact = 0;
	while (++yy < p->size.y)
	{
		xx = -1;
		while (++xx < p->size.x)
			if (p->piece[yy][xx] == '*')
			{
				o = 0;
				while (++o < 4)
					if ((xx + x + o) < map->map_size.x && (xx + x - o) > 0 &&
						(yy + y + o) < map->map_size.y && (yy + y - o) > 0)
						if (map->map[yy + y][xx + x + o] == map->enemy[0]
							|| map->map[yy + y][xx + x - o] == map->enemy[0]
							|| map->map[yy + y + o][xx + x] == map->enemy[0]
							|| map->map[yy + y - o][xx + x] == map->enemy[0])
							p->nb_contact += (4 - o);
			}
	}
	return (p->nb_contact);
}

void		get_contact(t_piece *p, t_map *map)
{
	int		y;
	int		x;

	y = 2;
	while (++y < map->map_size.y - 3)
	{
		x = 2;
		while (++x < map->map_size.x - 3)
		{
			if (map->map[y][x] == map->player[0] ||
				map->map[y][x] == map->player[1])
				if (map->map[y][x + 3] == map->enemy[0]
					|| map->map[y][x - 3] == map->enemy[0]
					|| map->map[y + 3][x] == map->enemy[0]
					|| map->map[y - 3][x] == map->enemy[0]
					|| map->map[y][x + 3] == map->enemy[1]
					|| map->map[y][x - 3] == map->enemy[1]
					|| map->map[y + 3][x] == map->enemy[1]
					|| map->map[y - 3][x] == map->enemy[1])
				{
					p->contact = 1;
					return ;
				}
		}
	}
}

int			contact_l(t_map *map, t_piece *p)
{
	int		y;
	int		x;
	int		ret;

	y = map->map_size.y - 1;
	p->final.x = 0;
	p->final.y = 0;
	ret = 0;
	while (y > 0)
	{
		x = map->map_size.x - 1;
		while (x > 0)
		{
			ret = check(y, x, map, p);
			if (ret == 0)
			{
				output_filler(p, map);
				return (0);
			}
			x--;
		}
		y--;
	}
	return (1);
}

int			contact_h(t_map *map, t_piece *p)
{
	int		y;
	int		x;
	int		ret;

	y = - 1;
	p->final.x = 0;
	p->final.y = 0;
	ret = 0;
	while (++y < map->map_size.y - 1)
	{
		x = - 1;
		while (++x < map->map_size.x - 1)
		{
			ret = check(y, x, map, p);
			if (ret == 0)
			{
				output_filler(p, map);
				return (0);
			}
		}
	}
	return (1);
}