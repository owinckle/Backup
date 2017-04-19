/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 20:39:18 by dbirtel           #+#    #+#             */
/*   Updated: 2017/04/10 09:42:14 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libft/libft.h"
# include "libmath/libmath.h"
# include <fcntl.h>
# include <mlx.h>
# include <pthread.h>

# define WIDTH 1200.0
# define HEIGHT 800.0
# define THREAD 8

# define MAX_DIST 200.0

# define BACKGROUND_COLOR 0x000000

# define AMBIENT 0.1
# define DIFFUSE 0.3

# define SPHERE 0
# define PLANE 1
# define CONE 2
# define CYLINDER 3

# define B_VOID -1
# define B_MAIN 100
# define B_CAM 110
# define B_LIGHT 120
# define B_OBJ 130

# define ESC 53

# define ERR_DIR "Argument must be a file, not a directory !\n"
# define ERR_AC "Wrong number of arguments !\n"
# define ERR_FD "Couldn't open file !\n"
# define ERR_VOID "Can't read file !\n"
# define ERR_MALLOC "Malloc failed miserably !\n"

/*
**		--- STRUCTURES ---
*/

typedef struct	s_val
{
	double		det;
	double		result;
	double		second;
	double		dist;
	double		a;
	double		b;
	double		c;
}				t_val;

typedef	struct	s_cam
{
	t_coord		pos;
	t_coord		vector_dir;
	t_coord		vector_up;
	t_coord		vector_right;
}				t_cam;

typedef struct	s_ob
{
	t_coord		pos;
	t_coord		normal;
	t_coord		color;
	t_coord		p[2];
	t_qt		rot;
	int			spec;
	double		radius;
	double		alpha;
	int			type;
	int			num;
	struct s_ob	*next;
}				t_ob;

typedef struct	s_li
{
	t_coord		pos;
	struct s_li	*next;
}				t_li;

typedef struct	s_ray
{
	t_coord		origin;
	t_coord		vector;
}				t_ray;

typedef struct	s_scene
{
	t_cam		cam;
	t_li		*spots;
	t_ob		*obj;
}				t_scene;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*add;
	int			e;
	int			s;
	int			l;
}				t_env;

typedef struct		s_th_tab
{
	t_env			*e;
	t_scene			*s;
	int				i;
}					t_th_tab;

/*
**		--- FUNCTIONS ---
*/

void			error(char *str);
void			is_fd_valid(int fd);
void			error_parsing(int line, char *str);

void			init_scene(char *path, t_scene *s);
void			init_env(t_env *e);

void			check_valid(char *line, int *balise, int count, t_scene *s);

void			add_obj(char *line, int count, t_scene *s);

void			count_num(char *line, int num, int count);
t_coord			get_coord(char *line, int start);
double			get_num(char *line, int pass);

int				red_cross(void);
int				key_press(int key, t_env *e);

void			add_cam(char *line, int count, t_scene *s);
void			add_lights(char *line, int count, t_scene *s);
void			add_sphere(char *line, int count, t_scene *s);
void			add_cylinder(char *line, int count, t_scene *s);
void			add_plane(char *line, int count, t_scene *s);
void			add_cone(char *line, int count, t_scene *s);

t_coord			get_pinhole(t_cam cam, int i, int j);
t_ray			compute_ray(t_coord pos, t_coord pinhole);
t_ray			move_ray(t_ray ray, t_ob *obj);
t_qt			compute_rot_qt(t_coord dir);

int				solve(t_ray ray, t_scene *s);
double			solve_sphere(t_ray ray, t_ob *obj, int ok);
double			solve_cylinder(t_ray r, t_ob *obj, int ok);
double			solve_plane(t_ray ray, t_ob *obj);
double			solve_cone(t_ray r, t_ob *obj, int ok);

t_coord			ambient(t_ob *obj);
t_coord			diffuse(t_ray light, t_ob *obj, double dist);
t_coord			specular(t_ray light, t_ob *obj, t_cam cam, double dist);

t_coord			blacked(void);
t_coord			get_normal(t_ob *obj);
t_coord			cylinder_normal(t_ob *obj);
t_coord			cone_normal(t_ob *obj);

#endif
