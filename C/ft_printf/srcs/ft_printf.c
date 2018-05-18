/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 08:24:57 by owinckle          #+#    #+#             */
/*   Updated: 2018/02/01 08:24:59 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void		padding(t_env *e, int n)
{
	if (e->padding < 0)
		return ;
	e->c = 32 | (e->f & F_ZERO);
	if (!n && !(e->f & F_MINUS))
		while (e->padding--)
			buffer(e, &e->c, 1);
	else if (n && (e->f & F_MINUS))
		while (e->padding--)
			buffer(e, &e->c, 1);
}

void		buffer(t_env *e, void *new, size_t size)
{
	int			diff;
	long long	new_i;

	new_i = 0;
	while (BUF_SIZE - e->buffer_index < (int)size)
	{
		diff = BUF_SIZE - e->buffer_index;
		ft_memcpy(&(e->buff[e->buffer_index]), (new + new_i), diff);
		size -= diff;
		new_i += diff;
		e->buffer_index += diff;
		e->len += diff;
		write(1, e->buff, e->buffer_index);
		e->buffer_index = 0;
	}
	ft_memcpy(&(e->buff[e->buffer_index]), (new + new_i), size);
	e->buffer_index += size;
	e->len += size;
}

int			ft_printf(const char *restrict format, ...)
{
	t_env e;

	e.format = (char *)format;
	e.len = 0;
	e.buffer_index = 0;
	va_start(e.ap, format);
	while (*e.format)
	{
		if (*e.format == '%')
		{
			++e.format;
			if (!*e.format)
				break ;
			parse(&e);
		}
		else
			buffer(&e, e.format, 1);
		++e.format;
	}
	write(1, e.buff, e.buffer_index);
	va_end(e.ap);
	return (e.len);
}
