#include "filler.h"

void	save_piece(t_env *e, char *line)
{
	int		i;
	i = 6;
	e->piece.y = ft_atoin(line, &i);
	e->piece.x = ft_atoin(line, &i);
}

static void	check_space(int y, int x, t_env *e)
{
	int		i;
	int		tmp;	
	// if (e->piece.y > 1)
	// {
	// 	//Check Up/Down
	// }
	if (e->piece.x > 1 && (i = x))
	{
		if (e->tab_size.x >= e->piece.x + x)
		{	
			while (++i < e->piece.x + x)
			{
				if (e->tab[y][i] != 0)
					tmp = -42;
			}
			if (tmp != -42)
			{
				dprintf(e->fd, "pos: %d %d\n", y, x);
				printf("%d %d\n", y, x);
			}
		}
	}
}

void	play(t_env *e)
{
	int		y;
	int		x;

	y = -1;
	x = -1;
	while (++y < e->tab_size.y)
	{
		while(++x < e->tab_size.x)
		{
			if (e->tab[y][x] == e->p.id)
				check_space(y, x, e);
		}
		x = -1;
	}
}