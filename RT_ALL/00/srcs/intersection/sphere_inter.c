#include "rt.h"

static void		set_param(float *param, t_env *e, int i, t_obj *node)
{
	param[0] = pow(e->c->ray[i][0], 2)
		+ pow(e->c->ray[i][1], 2)
		+ pow(e->c->ray[i][2], 2);
	param[1] = 2 * (e->c->ray[i][0]
			* (e->c->pos[0] - node->ori[0])
			+ e->c->ray[i][1] * (e->c->pos[1]
				- node->ori[1]) + e->c->ray[i][2]
			* (e->c->pos[2] - node->ori[2]));
	param[2] = pow(e->c->pos[0]
			- node->ori[0], 2) + pow(e->c->pos[1]
				- node->ori[1], 2) + pow(e->c->pos[2]
					- node->ori[2], 2) - pow(node->rad, 2);
}

static float	solve(float *param)
{
	float	delt;
	float	tmp[2];
	float	sol;

	sol = -42;
	if ((delt = pow(param[1], 2) - 4 * param[0] * param[2]) >= 0)
	{
		tmp[0] = (-param[1] + sqrt(delt)) / (2 * param[0]);
		tmp[1] = (-param[1] - sqrt(delt)) / (2 * param[0]);
		if ((tmp[0] >= 0 && tmp[1] < 0)
				|| (tmp[1] >= 0 && tmp[0] < 0))
			sol = (tmp[0] >= 0) ? tmp[0] : tmp[1];
		else if (tmp[0] >= 0 && tmp[1] >= 0)
			sol = (tmp[0] <= tmp[1]) ? tmp[0] : tmp[1];
	}
	return (sol);
}

void				sphere_inter(t_env *e, int i, t_obj *node)
{
	float	param[3];
	float	sol;

	set_param(param, e, i, node);
	sol = solve(param);
	if (sol >= 0 && sol <= e->c->inter[i])
	{
		e->c->inter[i] = sol;
		e->c->obj[i] = node;
	}
}
