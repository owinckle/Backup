/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:22:08 by owinckle          #+#    #+#             */
/*   Updated: 2016/03/28 17:22:10 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*get_lstfile(int fd, int **len)
{
	char	*line;
	t_list	*list;
	int		ret;

	line = NULL;
	list = NULL;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		**len = ft_strlen(line);
		ft_lstpushback(&list, line, ft_strlen(line));
	}
	return (list);
}

int		ft_tablen(char **array)
{
	int		x;

	x = 0;
	while (*(array + x))
		x++;
	return (x);
}

int		*put_array(char **line, int **len)
{
	int		i;
	int		y;
	int		*valueline;

	i = -1;
	y = ft_tablen(line);
	if (y < **len)
		**len = y;
	valueline = malloc(sizeof(int) * y);
	while (++i < y)
		valueline[i] = ft_atoi(line[i]);
	return (valueline);
}

int		**get_array(int fd, int *len, int *width)
{
	int		**array;
	char	**line;
	t_list	*list;
	int		x;

	x = -1;
	list = get_lstfile(fd, &len);
	if (!list)
		ft_error(NO_DATA);
	array = malloc(sizeof(int *) * ft_lstlen(list));
	while (list)
	{
		line = ft_strsplit(list->content, ' ');
		array[++x] = put_array(line, &len);
		list = list->next;
	}
	*width = x + 1;
	return (array);
}
