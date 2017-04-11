#include "rt.h"

void			inter(t_env *e, int i, t_obj *node)
{
	t_obj	*begin;

	begin = node;
	while (node != NULL)
	{
		if (!ft_strcmp("plan", node->name))
			plan_inter(e, i, node);
		else if (!ft_strcmp("sphere", node->name))
			sphere_inter(e, i, node);
		node = node->next;
	}
	node = begin;
}
