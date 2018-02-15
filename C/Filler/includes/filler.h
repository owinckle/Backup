#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef	struct		s_v2
{
	int				x;
	int				y;
}					t_v2;

typedef struct		s_map
{
	char			**map;
	char			*enemy;
	char			*player;
	int				p;
	t_v2			map_size;
	t_v2			pos_enemy;
	t_v2			pos_player;
	t_v2			first;
}					t_map;

typedef struct		s_piece
{
	char			**piece;
	int				nb_contact;
	int				contact;
	t_v2			final;
	t_v2			size;
	t_v2			r_size;
	t_v2			start;
	t_v2			end;
	t_v2			tmp;


}					t_piece;

/*
** contact.c
*/
int					count_contact(t_map *map, t_piece *p, int y, int x);
void				get_contact(t_piece *p, t_map *map);
int					contact_l(t_map *map, t_piece *p);
int					contact_h(t_map *map, t_piece *p);

/*
** s_algo.c
*/
int					s_algo_l(t_map *map, t_piece *p);
int					s_algo_h(t_map *map, t_piece *p);
int					s_algo2_l(t_map *map, t_piece *p);
int					s_algo2_h(t_map *map, t_piece *p);

/*
** b_algo.c
*/
int					b_algo_2(int nb_contact, t_piece *p, t_map *map);
int					b_algo(t_map *map, t_piece *p);

/*
** play.c
*/
int					play(t_map *map, t_piece *p);

/*
** piece_parsing.c
*/
void				get_piece_size(char *line, t_piece *p);

/*
** parsing.c
*/
void				get_player(t_map *map);
int					get_ret(t_map *map, t_piece *p);

/*
** assets.c
*/
int					strstart(char *str, char *start);
int					is_number(char c);
void				output_filler(t_piece *p, t_map *map);
int					check_bis(t_piece *p, int count, int i, int i2);
int					check(int y, int x, t_map *map, t_piece *p);

#endif