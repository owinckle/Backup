/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_rev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 13:49:33 by owinckle          #+#    #+#             */
/*   Updated: 2016/04/13 13:49:36 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_reverse(t_env *env)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = env->list;
	while (i < env->sz - 1)
	{
		tmp++;
		i++;
	}
	i = 0;
	while (i < env->sz)
	{
		ft_putendl(*tmp--);
		i++;
	}
}

static int	ft_all_sz(char *directory, t_env *env)
{
	DIR				*dir;
	struct dirent	*current;

	env->sz = 0;
	dir = opendir(directory);
	if (dir == NULL)
	{
		if (ft_file_exist(directory) == 1)
			return (-1);
		ft_error3(NAME, directory, NO);
	}
	while ((current = readdir(dir)) != NULL)
			env->sz++;
	closedir(dir);
	return (env->sz);
}

static char	**ft_all_lst(int sz, char *directory)
{
	DIR				*dir;
	struct dirent	*current;
	char			**list;
	int				i;

	if (sz == -1)
		return (NULL);
	list = malloc(sizeof(char *) * sz);
	i = 0;
	dir = opendir(directory);
	while ((current = readdir(dir)) != NULL)
	{
		list[i] = malloc(sizeof(char) * ft_strlen((char*)current->d_name));
		list[i++] = (char *)current->d_name;
	}
	closedir(dir);
	return (list);
}

static void	ft_all_print(t_env env, char *directory)
{
	int		i;

	i = 0;
	while (i < ft_all_sz(directory, &env))
		ft_putendl(env.list[i++]);
}

void		ft_all(char *dir)
{
	t_env	env;

	env.list = ft_all_lst(ft_all_sz(dir, &env), dir);
	env.list = ft_sort(env);
	ft_all_print(env, dir);
}
