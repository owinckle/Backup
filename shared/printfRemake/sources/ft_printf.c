#include "../includes/ft_printf.h"
#include <stdio.h>

void	padding(t_env *e, int n)
{
	if (!e->padding)
		return ;
	e->c = 32 | (e->f & F_ZERO);
	if (!n && !(e->f & F_MINUS))
		while (e->padding--)
			buffer(e, &e->c, 1);
		else if (n && (e->f & F_MINUS))
			while (e->padding--)
				buffer(e, &e->c, 1);
}

void	buffer(t_env *e, void *new, size_t size)
{
	int			diff;
	long long	new_i;

	new_i = 0;
	while (BUF_SIZE - e->buffer_index < (int)size)
	{
		diff = BUF_SIZE - e->buffer_index;
		ft_memcpy(&(e->buff[e->buffer_index]), &(new[new_i]), diff);
		size -= diff;
		new_i += diff;
		e->buffer_index += diff;
		e->len += diff;
		write(1, e->buff, e->buffer_index);
		e->buffer_index = 0;
	}
	ft_memcpy(&(e->buff[e->buffer_index]), &(new[new_i]), size);
	e->buffer_index += size;
	e->len += size;
}

int		ft_printf(const char * restrict format, ...)
{
	t_env	e;

	e.format = (char *)format;	
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

int	 main(int ac, char **av)
{
	//Bug sur e.len (nombre de char affichés :
	//Toujours 1 en trop, et met des nombres random si y'a plus de 3 parametres)
	int i = ft_printf("J'aime les %s et le %c! Address : %p et %p\n", "chats", 'c', "fdp", 1);
	int n = printf("J'aime les %s et le %c! Address : %p et %p\n", "chats", 'c', "fdp", 1);

	printf("Ft :[%d]\n", i);
	printf("LibC :[%d]\n", n);
	return (0);
}