#include "filler.h"

static void	get_r_piece(t_piece *p)
{
	int		y;
	int		x;

	y = -1;
	p->start.x = p->size.x;
	p->start.y = p->size.y;
	while (++y < p->size.y)
	{
		x = -1;
		while (++x < p->size.x)
			if (p->piece[y][x] == '*')
			{
				if (x < p->start.x)
					p->start.x = x;
				if (x > p->end.x)
					p->end.x = x;
				if (y < p->start.y)
					p->start.y = y;
				if (y > p->start.y)
					p->end.y = y;
			}
	}
	p->r_size.x = (p->end.x - p->start.x) + 1;
	p->r_size.y = (p->end.y - p->start.y) + 1;
}

static void	get_piece(t_piece *p)
{
	int		i;
	char	*line;

	i = 0;
	if (p->piece != NULL)
		free(p->piece);
	p->piece = (char **)malloc(sizeof(char *) * (p->size.y + 1));
	while (i < p->size.y)
	{
		get_next_line(0, &line);
		p->piece[i] = (char *)malloc(sizeof(char *) * (p->size.x + 1));
		p->piece[i] = ft_strcpy(p->piece[i], (const char *)line);
		i++;
		ft_strdel(&line);
	}
	get_r_piece(p);
}

void		get_piece_size(char *line, t_piece *p)
{
	int		i;
	int		tmp;

	i = 0;
	p->size.x = 0;
	p->size.y = 0;
	while (line[i])
	{
		tmp = 0;
		while (is_number(line[i]) == 0 && line[i])
		{
			tmp += line[i] - 48;
			if (is_number(line[i + 1]) == 0)
				tmp *= 10;
			i++;
		}
		if (p->size.y == 0)
			p->size.y = tmp;
		else if (p->size.x == 0)
			p->size.x = tmp;
		i++;
	}
	ft_strdel(&line);
	get_piece(p);
}