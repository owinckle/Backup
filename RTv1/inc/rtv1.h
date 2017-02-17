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

# include <stdio.h>

# define WIDTH 1080
# define HEIGHT 720
# define KEY_ESC 53

# define ASPR ((double)WIDTH / (double)HEIGHT)
# define ACCURACY 0.00000001
# define ACCURACY2 1
# define AMBIENTLIGHT 0.15
# define DIFFUSELIGHT 0.85
# define DEG_TO_RAD(x)	(x * (M_PI/180))

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

typedef struct		s_vect
{
	double			x;
	double			y;
	double			z;
}					t_vect;

typedef	struct		s_ray
{
	t_vect			*og;
	t_vect			*dir;
}					t_ray;

typedef	struct		s_color
{
	double			red;
	double			green;
	double			blue;
}					t_color;

typedef struct		s_spot
{
	t_vect			*pos;
}					t_spot;

typedef struct		s_camera
{
	t_vect			*pos;
	t_vect			*dir;
	t_vect			*right;
	t_vect			*down;
}					t_camera;

typedef struct		s_plane
{
	t_vect			*og;
	t_color			*color;
	t_vect			*rotate;
	struct s_plane	*next;
}					t_plane;

typedef struct		s_sphere
{
	t_vect			*og;
	double			radius;
	t_color			*color;
	struct s_sphere	*next;
}					t_sphere;

typedef struct		s_cone
{
	t_vect			*og;
	t_color			*color;
	t_vect			*rotate;
	struct s_cone	*next;
}					t_cone;

typedef struct		s_cyl
{
	t_vect			*og;
	double			radius;
	t_color			*color;
	t_vect			*rotate;
	struct s_cyl	*next;
}					t_cyl;

typedef struct		s_scene
{
	t_camera		*cam;
	t_spot			*spot;
	t_plane			*planes;
	t_sphere		*spheres;
	t_cone			*cones;
	t_cyl			*cyls;
	int				c_spheres;
	int				c_planes;
	int				c_cones;
	int				c_cyls;
}					t_scene;

typedef struct		s_inter
{
	t_vect			*normal;
	double			dist;
	t_color			*color;
	t_vect			*point;
}					t_inter;

typedef struct		s_env
{
	struct s_mlx	mlx;
	struct s_scene	scene;
	int				height;
	int				width;
	int				fd;
	char			*file;
}					t_env;

/*
** add.c
*/
void				add_sphere(t_sphere *s, t_sphere *to_add, int limiter);
void				add_plane(t_plane *p, t_plane *to_add, int limiter);
void				add_cylinder(t_cyl *c, t_cyl *to_add, int limiter);
void				add_cone(t_cone *c, t_cone *to_add, int limiter);

/*
** calc.c
*/
double				sphere_inter(t_sphere *s, t_ray *r);
double				plane_inter(t_plane *p, t_ray *r);
double				cylinder_inter(t_cyl *cyl, t_ray *r);
double				cone_inter(t_cone *co, t_ray *r);

/*
** camera.c
*/
t_camera			*get_cam(int fd, t_vect	*look_at, t_vect *diff);

/*
** colors.c
*/
t_color				*color_scalar(double scalar, t_color *c1);
int					get_color_nb(t_color *color);
t_color				*new_color(double r, double g, double b);
t_color				*get_color(int fd);

/*
** draw.c
*/
double				get_x(int x);
double				get_y(int y);
t_color				*get_color_at(t_env *e, int x, int y);
void				ft_draw(t_env *e);

/*
** error.c
*/
void				ft_error(int error);

/*
** f_color.c
*/
t_color				*find_color_at(t_env *e, t_ray *ray);

/*
** functions.c
*/
int					key_press(int k, t_env *e);
void				mlx_put_pxl(int x, int y, int color, t_env *e);
double				ft_atodouble(char **str);
int					open_file(char *file);

/*
** get.c
*/
t_sphere			*get_sphere(int fd);
t_plane				*get_plane(int fd);
t_cyl				*get_cylinder(int fd, t_vect *rot, int ret);
t_cone				*get_cone(int fd);
t_spot				*get_spot(int fd);

/*
** get_objs.c
*/
t_sphere			*get_spheres(int fd, t_scene *scene);
t_plane				*get_planes(int fd, t_scene *scene);
t_cyl				*get_cylinders(int fd, t_scene *scene);
t_cone				*get_cones(int fd, t_scene *scene);

/*
** intersections.c
*/
t_inter				*spheres_inter(t_env *e, t_ray *ray, int limiter,
						t_vect *p);
t_inter				*planes_inter(t_env *e, t_ray *ray, int limiter,
						t_vect *pt);
t_inter				*cylinders_inter(t_env *e, t_ray *ray, int limiter,
						t_vect *p);
t_inter				*cones_inter(t_env *e, t_ray *ray, int limiter, t_vect *p);

/*
** math.c
*/
double				magnitude(t_vect *v1);
t_vect				*normalize(t_vect *v1);
t_vect				*vect_add(t_vect *v1, t_vect *v2);
t_vect				*vect_mult(t_vect *v1, double scalar);
t_vect				*negative(t_vect *v1);

/*
** new.c
*/
t_sphere			*new_sphere(t_vect *og, double radius, t_color *color);
t_plane				*new_plane(t_vect *og, t_color *color, t_vect *rotate);
t_cyl				*new_cylinder(t_vect *og, double radius, t_color *color,
						t_vect *r);
t_cone				*new_cone(t_vect *og, t_color *color, t_vect *rotate);
t_spot				*new_spot(t_vect *pos);

/*
** normalize.c
*/
t_vect				*sphere_normal(t_vect *og, t_vect *point);
t_vect				*cylinder_normal(t_vect *og, t_vect *point);
t_vect				*cone_normal(t_vect *og, t_vect *point);

/*
** ray.c
*/
t_ray				*new_ray(t_vect *og, t_vect *dir);
t_ray				*get_ray(t_env *e, double x, double y);
t_inter				*new_inter(t_vect *normal, double dist, t_color *c,
						t_vect *point);
t_inter				*find_min_inter(t_inter *i1, t_inter *i2);
t_inter				*calc_inter(t_env *e, t_ray *ray);

/*
** rotate.c
*/
t_ray				*rotate_eye(t_ray *ray, t_vect *rot, int stage, t_vect *pos);
t_vect				*rotate_normal(t_vect *normal, t_vect *rot);

/*
** vector.c
*/
t_vect				*new_vector(double x, double y, double z);
t_vect				*get_vector(int fd);
t_vect				*vect_sub(t_vect *v1, t_vect *v2);
t_vect				*cross_product(t_vect *v1, t_vect *v2);
double				dot_product(t_vect *v1, t_vect *v2);

#endif
