#include "../includes/ft_printf.h"

void	ftpf_pt_address(t_env *e)
{
	void	*pt;

	pt = va_arg(e->ap, void *);
	e->f &= ~F_SHARP;
	e->min_length -= (e->f & F_ZERO ? 2 : 0);
	e->padding = (e->printed > e->min_length - 3) ? 0 :
		e->min_length - 3 - e->printed;
	e->f |= F_SHARP;
	e->f |= F_POINTER;
	ftpf_itoabase((uintmax_t)pt, 16, e);
}