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
	//Check up/down/right/left
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
			check_space(y, x, e);
		}
		x = -1;
	} 	
}