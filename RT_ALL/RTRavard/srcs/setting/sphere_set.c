#include <rt.h>

void	sphere_set(t_env *e, float *pos, float rayon, int color)
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
	e->o->name = "sphere";
	e->o->ori = vect_set(NULL, pos[0], pos[1], pos[2]);
	e->o->rad = rayon;
	e->o->color = color;
	e->o->next = NULL;
	e->o = begin;
}
