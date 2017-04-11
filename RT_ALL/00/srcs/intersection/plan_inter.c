#include "rt.h"

static float	solve(t_env *e, int i, t_obj *node)
{
	float	tmp;

	tmp = (node->axe[0] * (node->ori[0] - e->c->pos[0])
	+ node->axe[1] * (node->ori[1] - e->c->pos[1])
	+ node->axe[2] * (node->ori[2] - e->c->pos[2]))
	/ (node->axe[0] * e->c->ray[i][0]
	+ node->axe[1] * e->c->ray[i][1]
	+ node->axe[2] * e->c->ray[i][2]);
	return (tmp);
}

void				plan_inter(t_env *e, int i, t_obj *node)
{
	float	sol;

	if (dot_prod(node->axe, e->c->ray[i]))
	{
		sol = solve(e, i, node);
		if (sol >= 0 && sol <= e->c->inter[i])
		{
			e->c->inter[i] = sol;
			e->c->obj[i] = node;
		}
	}
}
