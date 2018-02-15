#include "filler.h"

void		get_player(t_map *map)
{
	char	*line;

	get_next_line(0, &line);
	if (strstart(line, "$$$") && map->p == 0)
	{
		map->p = (ft_strstr(line, "p1")) ? 1 : 2;
		map->enemy = (map->p == 1) ? "Xx" : "Oo";
		map->player = (map->p == 1) ? "Oo" : "Xx";
	}
	ft_strdel(&line);
}

static void	get_strat_pos(t_map *map)
{
	int		x;
	static int	y;

	if (y == map->map_size.y)
		return ;
	y = 0;
	while (++y < map->map_size.y)
	{
		x = 0;
		while (++x < map->map_size.x)
		{
			if ((map->map[y][x] == map->enemy[0] ||
				map->map[y][x] == map->enemy[1]))
			{
				map->pos_enemy.x = x;
				map->pos_enemy.y = y;
			}
			if ((map->map[y][x] == map->player[0] ||
				map->map[y][x] == map->player[1]))
			{
				map->pos_player.x = x;
				map->pos_player.y = y;
			}
		}
	}
}

static void	get_map(t_map *map)
{
	int		i;
	char	*line;

	i = -1;
	get_next_line(0, &line);
	ft_strdel(&line);
	map->map = (char **)malloc(sizeof(char *) * (map->map_size.y + 1));
	while (++i <= (map->map_size.y - 1))
	{
		get_next_line(0, &line);
		map->map[i] = ft_strdup((const char *)(&line[4]));
		ft_strdel(&line);
	}
	get_strat_pos(map);
}

static void	get_map_size(char *line, t_map *map)
{
	int		i;
	int		tmp;

	i = 0;
	map->map_size.x = 0;
	map->map_size.y = 0;
	while(line[i])
	{
		tmp = 0;
		while (is_number(line[i]) == 0 && line[i])
		{
			tmp += line[i] - 48;
			if (is_number(line[i + 1]) == 0)
				tmp *= 10;
			i++;
		}
		if (map->map_size.y == 0)
			map->map_size.y = tmp;
		else if (map->map_size.x == 0)
			map->map_size.x = tmp;
		i++;
	}
	get_map(map);
}

int			get_ret(t_map *map, t_piece *p)
{
	char	*line;

	p->piece = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (strstart(line, "Plateau"))
		{
			get_map_size(line, map);
			ft_strdel(&line);
		}
		else if (strstart(line, "Piece"))
		{
			get_piece_size(line, p);
			return (1);
		}
		else
			ft_strdel(&line);
	}
	return (0);
}