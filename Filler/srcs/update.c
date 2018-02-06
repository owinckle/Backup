#include "filler.h"

void	update_tab(t_env *e)
{
	int		i;
	int		j;
	int		tmp;
	char	*line;

	j = -1;
	i = -1;
	while (get_next_line(0, &line) > 0 && ++i < e->tab_size.y + 1)
	{
		dprintf(e->fd, "%s\n", line);
	}
}