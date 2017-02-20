/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:11:48 by owinckle          #+#    #+#             */
/*   Updated: 2017/02/17 12:11:49 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		open_file(char *file)
{
	int		fd;

	fd = open(file, O_DIRECTORY);
	if (fd >= 0)
		ft_error(FILE);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(FILE);
	return (fd);
}

int		linelen(char *buf, int k)
{
	int		len;

	len = 0;
	while (buf[k] != '\n' && buf[k] != '\0')
	{
		k++;
		len++;
	}
	return (++len);
}

int		key_hook(int k, t_env *e)
{
	if (k == KEY_ESC)
		ft_red(e);
	return (0);
}

void	fzero(float *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		s[i] = 0.0f;
		i++;
	}
}
