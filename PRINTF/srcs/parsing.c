#include "../includes/ft_printf.h"
#include <stdio.h>

static void	flags(t_env *e)
{
	while ((e->n = ft_strchri("# +-0*", *e->format, -1)) > -1 && ++e->format)
		e->f |= (1 << e->n);
	((e->f & F_MINUS) && !(e->f & F_WILDCARD)) ? e->f &= ~F_ZERO : 0;
	(e->f & F_PLUS) ? e->f &= ~F_SPACE : 0;
	if (e->f & F_WILDCARD)
	{
		e->f &= ~F_WILDCARD;
		if ((e->n = (int)va_arg(e->ap, int)) < 0)
		{
			e->f |= F_MINUS;
			e->n = -e->n;
		}
		else
			e->f &= ~F_MINUS;
		if (!(e->f & F_APP_PRECI))
			e->min_length = e->n;
		else
		{
			e->precision = (!(e->f & F_MINUS)) ? e->n : 0;
			e->f = (!e->n) ? e->f | F_APP_PRECI : e->f & ~F_APP_PRECI;
		}
	}
}

static void	width_precision(t_env *e)
{
	if (*e->format > 48 && *e->format < 58)
	{
		e->min_length = MAX(1, ft_atoi(e->format));
		while (*e->format > 47 && *e->format < 58)
			++e->format;
	}
	if (*e->format == '.')
	{
		++e->format;
		e->precision = MAX(ft_atoi(e->format), 0);
		while (*e->format > 47 && *e->format < 58)
			++e->format;
		e->f |= F_APP_PRECI;
	}
}

static void	conversion(t_env *e)
{
	e->c = *e->format;
	if (e->c == 's')
		(e->f & F_LONG || e->f & F_LONG2) ? ftpf_putwstr(e) : ftpf_putstr(e);
	else if (ft_strchr("dDi", e->c))
		ftpf_putnb(e);
	else if (e->c == 'c' || e->c == 'C')
		ftpf_character(e, va_arg(e->ap, unsigned));
	else if (e->c == 'S')
		ftpf_putwstr(e);
	else if (e->c == 'p')
		ftpf_pt_address(e);
	else if (ft_strchr("oOuUxX", e->c))
		ftpf_putnb_base(ft_strchri_base("....ou..x", e->c, -1) << 1, e);
	else if (e->c == '%')
		ftpf_character(e, '%');
	else
	{
		if (e->min_length != 0)
		{
			ftpf_character(e, e->c);
			++e->format;
		}
		--e->format;
	}
}

void		parse(t_env *e)
{
	e->f = 0;
	e->min_length = 0;
	e->precision = 1;
	flags(e);
	width_precision(e);
	while (42)
	{
		if (*e->format == 'l')
			e->f |= (e->format[1] == 'l' && ++e->format) ? F_LONG2 : F_LONG;
		else if (*e->format == 'h')
			e->f |= (e->format[1] == 'h' && ++e->format) ? F_SHORT2 : F_SHORT;
		else if (*e->format == 'j')
			e->f |= F_INTMAX;
		else if (*e->format == 'z')
			e->f |= F_SIZE_T;
		else
			break;
		++e->format;
	}
	flags(e);
	(e->f & F_PLUS) ? e->f &= ~F_SPACE : 0;
	if (ft_strchr("CDSUOX", *e->format))
		e->f |= (*e->format != 'X') ? F_LONG : F_UPCASE;
	conversion(e);
}