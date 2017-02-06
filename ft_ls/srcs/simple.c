/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 11:12:10 by owinckle          #+#    #+#             */
/*   Updated: 2016/04/12 11:12:11 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_current_sz(char *directory, t_env *env)
{
	DIR				*dir;
	struct dirent	*current;
	char			*check;

	env->sz = 0;
	check = NULL;
	dir = opendir(directory);
	if (dir == NULL)
	{
		if (ft_file_exist(directory) == 1)
			return (-1);
		ft_error3(NAME, directory, NO);
	}
	while ((current = readdir(dir)) != NULL)
	{
		check = ft_strdup((char *)current->d_name);
		if (check[0] != '.')
			env->sz++;
	}
	closedir(dir);
	return (env->sz);
}

static char		**ft_current(int sz, char *directory)
{
	DIR				*dir;
	struct dirent	*current;
	char			*check;
	char			**list;
	int				i;

	if (sz == -1)
		return (NULL);
	list = malloc(sizeof(char *) * sz);
	i = 0;
	check = NULL;
	dir = opendir(directory);
	while ((current = readdir(dir)) != NULL)
	{
		check = ft_strdup((char *)current->d_name);
		if (check[0] != '.')
		{
			list[i] = malloc(sizeof(char) * ft_strlen((char*)current->d_name));
			list[i++] = (char *)current->d_name;
		}
	}
	closedir(dir);
	return (list);
}

char		**ft_sort(t_env env)
{
	int		i;
	int		j;
	char	*swp;

	i = 0;
	j = 1;
	swp = ft_strnew(0);
	while (j < env.sz)
	{
		if (ft_strcmp(env.list[i], env.list[j]) > 0)
		{
			swp = ft_strdup(env.list[i]);
			env.list[i] = ft_strdup(env.list[j]);
			env.list[j] = ft_strdup(swp);
			ft_strdel(&swp);
			i = -1;
			j = 0;
		}
		j++;
		i++;
	}
	return (env.list);
}

static void		ft_simple_print(t_env env, char *directory)
{
	int		i;

	i = 0;
	while (i < ft_current_sz(directory, &env))
		ft_putendl(env.list[i++]);
}

void			ft_simple(char *dir, int flag)
{
	t_env	env;

	env.list = ft_current(ft_current_sz(dir, &env), dir);
	if (env.list != NULL)
	{
		env.list = ft_sort(env);
		if (flag == 3)
		{
			ft_all(dir);
		}
		else if (flag == 4)
			ft_reverse(&env);
		else
			ft_simple_print(env, dir);
	}
	else
		ft_putendl(dir);
	(void)flag;

}