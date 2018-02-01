#include "filler.h"

//Player 1 = O
//Player 2 = X

void	p_declare(t_env *e, char *line)
{
	if (ft_strstr(line, "owinckle.filler"))
		e->p.id = (ft_strstr("p1", line)) ? 1 : 2;

}

void	infos(t_env *e)
{
	char	*line;
	char	*buf;

	while (get_next_line(0, &line) > 0)
	{
		if (strstart(line, "$$$"))
			p_declare(e, line);
	}
}

int		main(int ac, char **av)
{
	t_env	e;

	infos(&e);
	return (0);
}