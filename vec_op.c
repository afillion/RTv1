#include "rt.h"

t_vec	*addition_vec(t_vec *a, t_vec *b)
{
	t_vec	*c;

	c->x = a->x + b->x;
	c->y = a->y + b->y;
	c->z = a->z + b->z;

	return (c);
}

t_vec	*substract_vec(t_vec *a, t_vec *b)
{
	t_vec	*c;

	c->x = a->x - b->x;
	c->y = a->y - b->y;
	c->z = a->z - b->z;

	return (c);
}

t_vec	*multiple_vec(t_vec *a, t_vec *b)
{
	t_vec *c;

	c->x = a->x * b->x;
	c->y = a->y * b->y;
	c->z = a->z * b->z;

	return (c);
}