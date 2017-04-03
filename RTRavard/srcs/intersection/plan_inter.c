#include "rt.h"

static float	solve(t_env *e, int i)
{
	float	tmp;

	tmp = (e->o->axe[0] * (e->o->ori[0] - e->c->pos[0])
	+ e->o->axe[1] * (e->o->ori[1] - e->c->pos[1])
	+ e->o->axe[2] * (e->o->ori[2] - e->c->pos[2]))
	/ (e->o->axe[0] * e->c->ray[i][0]
	+ e->o->axe[1] * e->c->ray[i][1]
	+ e->o->axe[2] * e->c->ray[i][2]);
	return (tmp);
}

void				plan_inter(t_env *e, int i)
{
	float	sol;

	if (dot_prod(e->o->axe, e->c->ray[i]))
	{
		sol = solve(e, i);
		if (sol >= 0 && sol <= e->c->inter[i])
		{
			e->c->inter[i] = sol;
			e->c->obj[i] = e->o;
		}
	}
}
