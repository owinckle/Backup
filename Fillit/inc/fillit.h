/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 12:52:58 by owinckle          #+#    #+#             */
/*   Updated: 2016/02/12 19:39:51 by opichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

typedef	struct			s_tetros
{
	char				*str;
	int					pos_x;
	int					pos_y;
	struct s_tetros		*next;
}						t_tetros;

t_tetros				*getfile(int fd);
int						ft_error();
void					ft_tno(char *map, int i);
void					ft_dbend(char *map);
t_tetros				*norme(char *map, int i, int col, int line);
int						four(char *map);
int						end(char *map, int col, int line);
t_tetros				*ft_tetr_forceadd(t_tetros **alst, t_tetros *new);
char					*ft_strndup(const char *src, size_t size);
t_tetros				*ft_tetro_new(char *str);
char					*ft_optimize(char	*src);
int						ft_noconflict(char *map, t_tetros *new, size_t sz);
char					*ft_map_r(t_tetros **alst, size_t sz, int i);
int						ft_orgn(t_tetros **lst, size_t sz, size_t step);
int						ft_resolve(t_tetros **lst, t_tetros *src, \
		size_t sz, size_t step);
t_tetros				*ft_pos(t_tetros *tet, size_t sz);
int						ft_abs_i(t_tetros *src, size_t i, int o, size_t sz);
int						ft_rel_i(t_tetros *dst, size_t abs_i, int o, size_t sz);
int						ft_max_dz(t_tetros *src);
void					ft_reset(t_tetros **lst);
#endif
