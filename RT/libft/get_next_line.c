/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 22:47:32 by dbirtel           #+#    #+#             */
/*   Updated: 2017/02/22 17:39:31 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_line(char **str, char **line)
{
	char	*p;
	int		len;

	if ((p = ft_strchr(*str, '\n')))
	{
		len = ft_strlen(*str) - ft_strlen(p);
		*line = ft_strndup(*str, len);
		p++;
		*str = ft_strcpy(*str, p);
		return (1);
	}
	if (ft_strlen(*str) > 0)
	{
		*line = ft_strdup(*str);
		ft_strclr(*str);
		return (1);
	}
	return (0);
}

static t_list	*initialise(int fd)
{
	t_save	*new;
	t_list	*ini;

	new = (t_save*)malloc(sizeof(t_save));
	new->str = NULL;
	new->fd = fd;
	ini = (t_list*)malloc(sizeof(t_list));
	ini->content = (t_save*)new;
	ini->next = NULL;
	return (ini);
}

static t_list	*get_node(int fd, t_list **list)
{
	t_list	*fake;

	fake = *list;
	while (((t_save*)fake->content)->fd != fd && fake->next)
		fake = fake->next;
	if (((t_save*)fake->content)->fd != fd)
	{
		ft_lstpushback(list, initialise(fd));
		fake = fake->next;
	}
	return (fake);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list = NULL;
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	int				r;
	t_list			*n;

	if (!line || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (!list)
		list = initialise(fd);
	n = get_node(fd, &list);
	while (!ft_strchr(((t_save*)n->content)->str, '\n'))
	{
		if ((r = read(fd, buff, BUFF_SIZE)) < 0)
			return (-1);
		if (r == 0)
			return (get_line(&(((t_save*)n->content)->str), line));
		buff[r] = '\0';
		tmp = ft_strjoin(((t_save*)n->content)->str, buff);
		ft_strdel(&((t_save*)n->content)->str);
		((t_save*)n->content)->str = tmp;
	}
	return (get_line(&(((t_save*)n->content)->str), line));
}
