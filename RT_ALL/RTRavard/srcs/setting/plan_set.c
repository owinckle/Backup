#include <rt.h>

void	plan_set(t_env *e, float *pos, float *nor, int color)
{
	t_obj	*begin;

	if (e->o == NULL)
	{
		e->o = (t_obj *)malloc(sizeof(t_obj));
		begin = e->o;
	}
	else
	{
		begin = e->o;
		while (e->o->next != NULL)
			e->o = e->o->next;
		e->o->next = (t_obj *)malloc(sizeof(t_obj));
		e->o = e->o->next;
	}
	e->o->name = "plan";
	e->o->ori = vect_set(NULL, pos[0], pos[1], pos[2]);
	e->o->axe = vect_set(NULL, nor[0], nor[1], nor[2]);
	ft_norme(e->o->axe);
	e->o->color = color;
	e->o->next = NULL;
	e->o = begin;
}
