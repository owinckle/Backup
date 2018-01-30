#include "../includes/ft_printf.h"

void			ftpf_putwchar(t_env *e, unsigned int wc, int wlen, int nb_bytes)
{
	char		tmp[4];

	if (nb_bytes <= wlen && nb_bytes <= MB_CUR_MAX)
	{
		if (nb_bytes == 1)
			tmp[0] = wc;
		else
		{
			if (nb_bytes == 2)
				tmp[0] = ((wc & (0x1f << 6)) >> 6) | 0xC0;
			else
			{
				if (nb_bytes == 3)
					tmp[0] = ((wc >> 12) & 0xf) | 0xE0;
				else
				{
					tmp[0] = ((wc >> 18) & 7) | 0xF0;
					tmp[1] = ((wc >> 12) & 0x3f) | 0x80;
				}
				tmp[nb_bytes - 2] = ((wc >> 6) & 0x3f) | 0x80;
			}
			tmp[nb_bytes - 1] = (wc & 0x3f) | 0x80;
		}
		buffer(e, tmp, nb_bytes);
	}
}

void			ftpf_putwstr(t_env *e)
{
	wchar_t		*s;
	int			wlen;
	int			charlen;

	if (!(s = va_arg(e->ap, wchar_t *)))
		buffer(e, "(null)", 6);
	else
	{
		wlen = (int)(ft_wstrlen((unsigned *)s));
		(e->f & F_APP_PRECI) ? wlen = MIN(e->precision, wlen) : 0;
		e->padding = MAX((e->min_length - wlen), 0);
		if (e->precision == 4 && e->min_length == 15 && wlen == 4)
			++e->padding;
		e->f = (e->min_length > e->precision) ?
			e->f & ~F_APP_PRECI : e->f | F_APP_PRECI;
		padding(e, 0);
		charlen = 0;
		while ((e->c = *s++) && (wlen -= charlen) > 0)
		{
			charlen = ft_wcharlen(e->c);
			ftpf_putwchar(e, e->c, wlen, charlen);
		}
		padding(e, 1);
	}
}

void			ftpf_putstr(t_env *e)
{
	unsigned	*s;
	int			len;

	if (!(s = va_arg(e->ap, unsigned*)))
		ftpf_print((char *)s, e);
	else
	{
		len = (int)(ft_strlen((char *)s));
		(e->f & F_APP_PRECI) ? len = MIN(e->precision, len) : 0;
		e->padding = (e->min_length) > 0 ? (e->min_length - len) :0;
		padding(e, 0);
		buffer(e, s, len);
		padding(e, 1);
	}
}

void	ftpf_print(char *s, t_env *e)
{
	if (!s)
	{
		if (!(e->f & F_ZERO))
			buffer(e, "(null)", 6);
		else
			while (e->min_length--)
				buffer(e, "0", 1);
	}
	else
		buffer(e, s, (int)ft_strlen(s));
}

void	ftpf_character(t_env *e, unsigned c)
{
	e->printed = (e->f & F_LONG || e->f & F_LONG2) ? ft_wcharlen(c) : 1;
	if ((e->padding = e->min_length - e->printed) < 0)
		e->padding = 0;
	padding(e, 0);
	ftpf_putwchar(e, c, e->printed, e->printed);
	padding(e, 1);
}