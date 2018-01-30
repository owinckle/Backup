#include "../includes/ft_printf.h"
#include <stdio.h>

void	ftpf_putnb(t_env *e)
{
	intmax_t	n;

	if (e->f & F_LONG || e->f & F_LONG2)
		n = (e->f & F_LONG2) ? ((intmax_t)va_arg(e->ap, long long)) :
			((intmax_t)va_arg(e->ap, long));
	else if (e->f & F_SHORT || e->f & F_SHORT2)
		n = (e->f & F_SHORT2) ? (intmax_t)((char)va_arg(e->ap, int)) :
			(intmax_t)((short)va_arg(e->ap, int));
	else if (e->f & F_INTMAX)
		n = (va_arg(e->ap, intmax_t));
	else if (e->f & F_SIZE_T)
		n = (va_arg(e->ap, ssize_t));
	else
		n = ((intmax_t)va_arg(e->ap, int));
	(e->f & F_ZERO) ? e->precision = e->min_length : 0;
	ftpf_itoa(n, e, 0);

}

void	ftpf_putnb_base(int base, t_env *e)
{
	uintmax_t	n;

	if (e->f & F_LONG || e->f & F_LONG2)
		n = (e->f & F_LONG2) ? ((intmax_t)va_arg(e->ap, unsigned long long)) :
			((intmax_t)va_arg(e->ap, unsigned long));
	else if (e->f & F_SHORT || e->f & F_SHORT2)
		n = (e->f & F_SHORT2) ? (uintmax_t)((unsigned char)va_arg(e->ap, int)) :
			(uintmax_t)((unsigned short)va_arg(e->ap, int));
	else if (e->f & F_INTMAX)
		n = (va_arg(e->ap, uintmax_t));
	else if (e->f & F_SIZE_T)
		n = (uintmax_t)va_arg(e->ap, size_t);
	else
		n = (uintmax_t)va_arg(e->ap, unsigned int);
	ftpf_itoabase(n, base, e);

}

void	ftpf_itoa(intmax_t n, t_env *e, int len)
{
	char		s[21];
	uintmax_t	tmp;

	tmp = ABS(n);
	while (tmp)
	{
		tmp /= 10;
		++len;
	}
	if ((n < 0 || e->f & F_PLUS || e->f & F_SPACE) && e->f & F_ZERO)
		--e->precision;
	e->printed = MAX(len, e->precision);
	if (n < 0 || e->f & F_PLUS || e->f & F_SPACE)
		++e->printed;
	e->padding = (e->printed > e->min_length) ? 0 : e->min_length - e->printed;
	padding(e, 0);
	tmp = ABS(n);
	ftpf_ibasefill(tmp, 10, s, e);
	(e->f & F_SPACE) ? s[0] =  ' ' : 0;
	(n < 0) ? s[0] = '-' : 0;
	(e->f & F_PLUS && n >= 0) ? s[0] = '+' : 0;
	buffer(e, s, e->printed);
	padding(e, 1);
}

void	ftpf_itoabase(uintmax_t n, int b, t_env *e)
{
	uintmax_t	tmp;
	char		s[21];
	int			ext;

	e->printed = 0;
	tmp = n;
	while (tmp && ++e->printed)
		tmp /= b;
	(e->f & F_ZERO) ? e->precision = e->min_length : 0;
	ext = (e->printed >= e->precision) ? 0 : 1;
	e->printed = MAX(e->precision, e->printed);
	((e->f & F_SHARP) && b == 8 && !ext) ? --e->min_length : 0;
	((e->f & F_SHARP) && b == 8 && !n && (e->f & F_APP_PRECI)) ?
		++e->printed : 0;
	((e->f & F_SHARP) && b == 16 && !(e->f & F_ZERO)) ? e->min_length -= 2 : 0;
	e->padding = MAX(0, (e->min_length - e->printed));
	padding(e, 0);
	if ((n || (e->f & F_POINTER))
		&& (e->f & F_SHARP) && ((b == 8 && !ext) || (b == 16)))
		buffer(e, "0", 1);
	if ((n || (e->f & F_POINTER)) && (e->f & F_SHARP) && b == 16)
		buffer(e, (e->f & F_UPCASE) ? "X" : "x", 1);
	ftpf_ibasefill(n, b, s, e);
	buffer(e, s, e->printed);
	padding(e, 1);
}

void	ftpf_ibasefill(uintmax_t tmp, int b, char s[BUF_SIZE], t_env *e)
{
	int		len;

	if (tmp && !(e->f & F_POINTER) && (e->f & F_ZERO) && (e->f & F_SHARP) &&
		b == 16 && !(e->f & F_LONG2) && e->printed > 3)
		e->printed -= 2;
	len = e->printed;
	e->c = 'a' - 10 - ((e->f & F_UPCASE) >> 1);
	while (len--)
	{
		s[len] = tmp % b + ((tmp % b < 10) ? '0' : e->c);
		tmp /= b;
	}
	(e->f & F_APP_PRECI && e->f & F_ZERO) ? s[0] = ' ' : 0;
}