/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opichou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 20:15:36 by opichou           #+#    #+#             */
/*   Updated: 2016/02/12 01:56:09 by opichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static	int			ft_bk_col(char *src)
{
	size_t i;

	i = 0;
	while (i <= 3)
	{
		if (src[i * 5] != '.')
			return (0);
		i++;
	}
	return (1);
}

static	int			ft_bk_line(char *src)
{
	size_t i;

	i = 0;
	while (i <= 3)
	{
		if (src[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

static	char		*ft_optimize_col(char *src)
{
	size_t	i;
	size_t	c;

	c = 0;
	while (ft_bk_col(src) == 1)
	{
		i = 0;
		while (i <= 18)
		{
			if (src[i + 1] == '\n')
				src[i] = '.';
			else if (src[i] != '\n')
				src[i] = src[i + 1];
			i++;
		}
	}
	return (src);
}

static	char		*ft_optimize_line(char *src)
{
	size_t	i;
	size_t	c;

	c = 0;
	while (ft_bk_line(src))
	{
		i = 0;
		while (i <= 18)
		{
			if (i < 14 && src[i] != '\n')
				src[i] = src[i + 5];
			else if (src[i] != '\n')
				src[i] = '.';
			i++;
		}
	}
	return (src);
}

char				*ft_optimize(char *src)
{
	src = ft_optimize_col(src);
	src = ft_optimize_line(src);
	return (src);
}
