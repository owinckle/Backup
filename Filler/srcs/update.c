#include "filler.h"

void	player(t_env *e)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (strstart(line, "Plateau"))
		{
			player_init(e);
			play();
		}
	}
}