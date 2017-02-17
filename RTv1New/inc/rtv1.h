/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 10:53:24 by owinckle          #+#    #+#             */
/*   Updated: 2016/10/18 10:53:25 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libft.h"
# include "get_next_line.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>

# define WIDTH		800
# define HEIGHT		800

# define KEY_ESC	53

# define ARG		1
# define MALLOC		2
# define FILE		3
# define PARSE		4
# define DATA		5

# define CAMX		e->cam_pos.x
# define CAMY		e->cam_pos.y
# define CAMZ		e->cam_pos.z
# define CAMDX		e->cam_dir.x
# define CAMDY		e->cam_dir.y
# define CAMDZ		e->cam_dir.z

typedef struct		s_vect
{
	float			x;
	float			y;
	float			z;
}					t_vect;

typedef struct		s_color
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

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*pxl;
	int				bpp;
	int				sl;
	int				ed;
}					t_mlx;

typedef struct		s_env
{
	t_mlx			mlx;
	t_obj			*obj;
	t_obj			*light;
	t_vect			cam_pos;
	t_vect			cam_dir;
	char			**scene;
	char			*file;
	int				lc;
	int				fd;
	int				width;
	int				height;
}					t_env;

/*
** error.c
*/
void				ft_error(int error);

/*
** functions.c
*/
int					linelen(char *buf, int k);
int					open_file(char *file);

/*
** objects.c
*/
t_env				*add_light(t_env *e, int *j, int i);
t_env				*add_cyclone(t_env *e, int *j, int i, int t);
t_env				*add_plane(t_env *e, int *j, int i);
t_env				*add_sphere(t_env *e, int *j, int i);

/*
** parse.c
*/
t_env				*parse(t_env *e);
t_obj				*add_link(t_env *e, t_obj *link, int type);	

#endif
