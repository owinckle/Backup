/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 09:36:03 by owinckle          #+#    #+#             */
/*   Updated: 2016/04/06 09:36:07 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <stdio.h> //DEBUG

# define ILLEGAL	"ft_ls: illegal option -- "
# define USAGE		"ft_ls [-lRart] [file ...]"
# define NO			": No such file or directory"
# define NAME		"ft_ls: "

typedef struct		s_env
{
	char			**list;
	char			flag;
	int				sz;
}					t_env;

void		ft_simple(char *dir, int flag);
int			ft_file_exist(const char *file);
int			ft_error(char *error);
int			ft_error2(char *error, char c, char *error2);
int			ft_error3(char *error, char *error2, char *error3);
int			ft_attributs(char *flag);
void		ft_reverse(t_env *env);
char		**ft_sort(t_env env);
void		ft_all(char *dir);

#endif
