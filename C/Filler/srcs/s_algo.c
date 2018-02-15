#include "filler.h"

int			s_algo2_l(t_map *map, t_piece *p)
{
	int		y;
	int		x;
	int		ret;

	y = -1;
	p->final.x = 0;
	p->final.y = 0;
	ret	= 0;
	while (++y < map->map_size.y)
	{
		x = map->map_size.x;
		while (--x > 0)
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

int			s_algo2_h(t_map *map, t_piece *p)
{
	int		y;
	int		x;
	int		ret;

	y = -1;
	p->final.x = 0;
	p->final.y = 0;
	ret	= 0;
	while (++y < map->map_size.y)
	{
		x = -1;
		while (++x < map->map_size.x)
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


int			s_algo_l(t_map *map, t_piece *p)
{
	int		y;
	int		x;
	int		ret;

	y = map->map_size.y;
	p->final.x = 0;
	p->final.y = 0;
	ret	= 0;
	while (y > 0)
	{
		x = map->map_size.x;
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

int			s_algo_h(t_map *map, t_piece *p)
{
	int		y;
	int		x;
	int		ret;

	y = map->map_size.y;
	p->final.x = 0;
	p->final.y = 0;
	ret	= 0;
	while (y > 0)
	{
		x = -1;
		while (++x < map->map_size.x)
		{
			ret = check(y, x, map, p);
			if (ret == 0)
			{
				output_filler(p, map);
				return (0);
			}
		}
		y--;
	}
	return (1);	
}