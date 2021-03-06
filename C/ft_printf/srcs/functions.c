/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 08:25:06 by owinckle          #+#    #+#             */
/*   Updated: 2018/02/01 08:25:07 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t			ft_wcharlen(unsigned wc)
{
	if (wc < 0x80)
		return (1);
	else if (wc < 0x800)
		return (2);
	else if (wc < 0x10000)
		return (3);
	return (4);
}

void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *s;
	char *d;

	s = (char *)src;
	d = (char *)dest;
	while (n--)
		d[n] = s[n];
	return (dest);
}

int				ft_strchri(char *s, int c, int i)
{
	while (s[++i])
		if (s[i] == c)
			return (i);
	return (-1);
}

char			*ft_strchr(const char *s, int c)
{
	char	*str;
	char	d;
	int		i;

	str = (char *)s;
	d = (char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == d)
			return (str + i);
		else
			i++;
	}
	if (str[i] == '\0' && d == '\0')
		return (str + i);
	else
		return (NULL);
}

int				ft_atoi(char *s)
{
	long	r;
	short	sign;

	r = 0;
	sign = 1;
	if (*s == '-' || *s == '+')
		sign = 44 - *s++;
	while (*s >= '0' && *s <= '9')
		r = r * 10 + *s++ - '0';
	return (sign * (int)r);
}
