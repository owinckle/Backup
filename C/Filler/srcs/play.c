#include "filler.h"

static int	big(t_map *map, t_piece *p)
{
	int		ret;

	get_contact(p, map);
	if (p->contact == 0)
	{
		if (map->pos_player.y < map->pos_enemy.y)
		{
			if (contact_l(map, p) == 1)
				return (1);
		}
		else if (map->pos_player.y >= map->pos_enemy.y)
		{
			if (contact_h(map, p) == 1)
				return (1);
		}
	}
	else
	{
		ret = b_algo(map, p);
		if (ret == 0)
			return (1);
	}
	return (0);
}

static int	small(t_map *map, t_piece *p)
{
	if (map->pos_player.y < (map->map_size.y / 2))
	{
		if (map->pos_player.x < (map->map_size.x / 2))
		{
			if (s_algo_l(map, p) == 1)
				return (1);
		}
		else if (map->pos_player.x >= (map->map_size.x / 2))
			if (s_algo_h(map, p) == 1)
				return (1);
	}
	else if (map->pos_player.y >= (map->map_size.y / 2))
	{
		if (map->pos_player.x < (map->map_size.x / 2))
		{
			if (s_algo2_l(map, p) == 1)
				return (1);
		}
		else if (map->pos_player.x >= (map->map_size.x / 2))
			if (s_algo2_h(map, p) == 1)
				return (1);
	}
	return (0);
}

int			play(t_map *map, t_piece *p)
{
	if (map->map_size.y < 20)
		return (small(map, p));
	if (map->map_size.y >= 20)
		return (big(map, p));
	return (0);
}