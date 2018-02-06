#include "filler.h"

int		main(int ac, char **av)
{
	t_env	e;
	char	*line;

	//DEBUG
	e.fd = open("file_debug", O_RDWR);



	//MAIN
	infos(&e);
	update_tab(&e);
	// while (get_next_line(0, &line) > 0)
	// {
	// 	if (strstart(line, "Plateau"))
	// 		update_tab(&e);
	// }



	//DEBUG
	dprintf(e.fd, "Player ID: %d\n", e.p.id);
	dprintf(e.fd, "Size Y: %d\n", e.tab_size.y);
	dprintf(e.fd, "Size X: %d\n\n", e.tab_size.x);
	int x = -1;
	int y = -1;
	while (++y < e.tab_size.y)
	{
		while (++x < e.tab_size.x)
			dprintf(e.fd, "%d", e.tab[y][x]);
		dprintf(e.fd, "\n");
		x = -1;
	}
	return (0);
}