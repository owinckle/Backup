/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 10:28:18 by owinckle          #+#    #+#             */
/*   Updated: 2017/03/31 10:28:19 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

/*
** TMP !!!!! REMOVE !!!!!
*/
# include <stdio.h>

/*
** HEADERS
*/
# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>

/*
** PARAMS
*/
# define WIDTH		800
# define HEIGHT		800

/*
** ALIASES
*/
# define CAMX			e->cam_pos.x
# define CAMY			e->cam_pos.y
# define CAMZ			e->cam_pos.z
# define CAMDX			e->cam_dir.x
# define CAMDY			e->cam_dir.y
# define CAMDZ			e->cam_dir.z
# define LIGHT			e->lighting

/*
** ERRORS
*/
# define ARG		1
# define MALLOC		2
# define FILE		3
# define DATA		4

/*
** STRUCTURES
*/
typedef struct		s_vect
{
	float			x;
	float			y;
	float			z;
}					t_vect;

typedef	struct		s_color
{
	float			red;
	float			green;
	float			blue;
}					t_color;

typedef struct		s_obj
{
	int				type;
	float			size;
	t_vect			rot;
	t_vect			pos;
	t_color			color;
	struct s_obj	*next;
}					t_obj;

typedef	struct		s_env
{
	t_obj			*obj;
	t_obj			*light;
	t_vect			cam_pos;
	t_vect			cam_dir;
	float			lighting;
	char			**scene;
	char			*file;
	int				lc;
	int				fd;
	int				width;
	int				height;
}					t_env;

/*
** parsing/objects.c
*/
t_env				*add_light(t_env *e, int *j, int i);
t_env				*add_cyclone(t_env *e, int *j, int i, int t);
t_env				*add_plane(t_env *e, int *j, int i);
t_env				*add_sphere(t_env *e, int *j, int i);

/*
** parsing/options.c
*/
void				parse_options(t_env *e);

/*
** parsing/parse.c
*/
t_obj				*add_link(t_env *e, t_obj *link, int type);
t_env				*parse(t_env *e);

/*
** utils/error.c
*/
void				ft_error(int error);

/*
** utils/utils.c
*/
int					open_file(char *file);
int					linelen(char *buf, int k);

#endif
