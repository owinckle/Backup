#include "filler.h"

int			b_algo_2(int nb_contact, t_piece *p, t_map *map)
{
	if (nb_contact == -1)
		return (0);
	p->final.x = p->tmp.x;
	p->final.y = p->tmp.y;
	output_filler(p, map);
	return (1);
}

int			b_algo(t_map *map, t_piece *p)
{
	int		y;
	int		x;
	int		nb_contact_tmp;
	int		nb_contact;

	nb_contact = -1;
	y = map->map_size.y - (p->size.y - p->end.y);
	p->tmp.x = 0;
	p->tmp.y = 0;
	while (--y >= 0)
	{
		x = map->map_size.x - (p->size.x - p->end.x);
		while (--x >= 0)
			if (check(y, x, map, p) == 0)
			{
				nb_contact_tmp = count_contact(map, p, y, x);
				if (nb_contact_tmp > nb_contact)
				{
					nb_contact = nb_contact_tmp;
					p->tmp.x = x;
					p->tmp.y = y;
				}
			}
	}
	return (b_algo_2(nb_contact, p, map));
}
