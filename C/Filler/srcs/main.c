#include "filler.h"

static void	struct_init(t_map *map, t_piece *p)
{
	map->map = NULL;
	map->p = 0;
	map->map_size.x = 0;
	map->map_size.y = 0;
	map->pos_enemy.x = 0;
	map->pos_enemy.y = 0;
	map->pos_player.x = 0;
	map->pos_player.y = 0;
	p->final.x = 0;
	p->final.y = 0;
	p->size.x = 0;
	p->size.y = 0;
	p->start.x = 0;
	p->start.y = 0;
	p->end.x = 0;
	p->end.y = 0;
	p->contact = 0;
}

static int	last(t_map *map, t_piece *p)
{
	int		y;
	int		x;
	int		ret;

	y = -1;
	p->final.y = 0;
	p->final.x = 0;
	ret = 0;
	while (++y < map->map_size.y - 1)
	{
		x = -1;
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

int			main(void)
{
	t_map	*map;
	t_piece *p;


	map = (t_map *)malloc(sizeof(*map));
	p = (t_piece *)malloc(sizeof(*p));
	struct_init(map, p);
	get_player(map);
	while (42)
	{
		get_ret(map, p);
		if (play(map, p) == 1)
		{
			if (last(map, p) == 1)
			{
				output_filler(p, map);
				exit(1);
			}
		}
	}
	free(p->piece);
	free(map);
	free(p);
	return (0);
}
