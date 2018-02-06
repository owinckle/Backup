#include "filler.h"

void	tab_init(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	e->tab = (int **)malloc(sizeof(int *) * e->tab_size.y);
	while (++i < e->tab_size.y)
		e->tab[i] = (int *)malloc(sizeof(int) * e->tab_size.x);
	j = -1;
	i = -1;
	while (++i < e->tab_size.y)
	{
		while (++j < e->tab_size.x)
			e->tab[i][j] = 0;
		j = -1;
	}
}

void	declare(t_env *e, char *line)
{
	int		i;

	i = 8;
	if (ft_strstr(line, PLAYER))
		e->p.id = (ft_strstr(line, "p1")) ? 1 : 2;
	else if (strstart(line, "Plateau"))
	{
		e->tab_size.y = ft_atoin(line, &i);
		e->tab_size.x = ft_atoin(line, &i);
		tab_init(e);
	}
}

void	infos(t_env *e)
{
	char	*line;
	char	*buf;

	while (get_next_line(0, &line) > 0)
	{
		if (strstart(line, "$$$"))
			declare(e, line);
		else if (strstart(line, "Plateau"))
		{
			declare(e, line);
			break ;
		}
	}
}