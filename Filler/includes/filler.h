#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>

typedef	struct		s_v2
{
	int				x;
	int				y;
}					t_v2;

typedef struct		s_player
{
	t_v2			start;
	int				id;

}					t_player;

typedef struct		s_env
{
	t_player		p;
}					t_env;

/*
** assets.c
*/
int					strstart(char *str, char *start);

#endif