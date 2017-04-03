/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 19:21:08 by owinckle          #+#    #+#             */
/*   Updated: 2017/04/03 19:21:09 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_line.h"

static int	buffer(int const fd, char *buf[fd])
{
	char	*swp;
	char	*s;
	int		ret;
	char	*tmp;

	tmp = ft_strnew(GL_BUFF);
	while (!(s = ft_strchr(buf[fd], '\n')) &&
			(ret = read(fd, tmp, GL_BUFF)) > 0)
	{
		tmp[ret] = '\0';
		swp = buf[fd];
		buf[fd] = ft_strjoin(swp, tmp);
		ft_strdel(&swp);
	}
	ft_strdel(&tmp);
	if (ret == -1)
		return (ret);
	if (ret == 0 && !s)
		return (ret);
	return (1);
}

static char	*act(char **line, int const fd, char *buf[fd], char **last)
{
	*line = ft_strsub(buf[fd], 0, (ft_strchr(buf[fd], '\n')) - buf[fd]);
	*last = *line;
	buf[fd] = ft_strdup(ft_strchr(buf[fd], '\n') + 1);
	return (buf[fd]);
}

int			get_next_line(int const fd, char **line)
{
	static char		*buf[256];
	char			*swp;
	int				ret;
	static char		*last = "";

	if (fd < 0 || line == NULL)
		return (-1);
	if (buf[fd] == NULL)
		buf[fd] = ft_strnew(1);
	ret = buffer(fd, &*buf);
	if (ret > 0 && (swp = buf[fd]))
	{
		buf[fd] = act(&*line, fd, &*buf, &last);
		ft_strdel(&swp);
		return (1);
	}
	if (ft_strcmp(buf[fd], last) != 0 && ret == 0 && buf[fd][0] != '\0' &&
			(last = ft_strdup(buf[fd])))
	{
		*line = ft_strdup(buf[fd]);
		return (1);
	}
	if (ret == 0 && (*line = buf[fd]))
		buf[fd] = NULL;
	return (ret);
}
