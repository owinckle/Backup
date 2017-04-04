#include "rt.h"

void			inter(t_env *e, int i)
{
	t_obj	*begin;

	begin = e->o;
	while (e->o != NULL)
	{
		// if (!ft_strcmp("plan", e->o->name))
		// 	plan_inter(e, i);
		// else if (!ft_strcmp("sphere", e->o->name))
		// 	sphere_inter(e, i);
		// Plus de segfault si tu n'appel pas les fonctions, mais ca veut aussi dire
		// plus de raytracing...
		e->o = e->o->next;
	}
	(void)i; // A enlever
	e->o = begin;
}
