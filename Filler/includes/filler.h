#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

# define PLAYER		"owinckle.filler"

typedef	struct		s_v2
{
	int				x;
	int				y;
}					t_v2;

typedef struct		s_player
{
	t_v2			og;
	int				id;

}					t_player;

typedef struct		s_env
{
	t_player		p;
	t_v2			tab_size;
	int				fd;
	int				**tab;
}					t_env;

/*
** assets.c
*/
int					strstart(char *str, char *start);

/*
** init.c
*/
void				tab_init(t_env *e);
void				declare(t_env *e, char *line);
void				infos(t_env *e);

/*
** update.c
*/
void				update_tab(t_env *e);

#endif