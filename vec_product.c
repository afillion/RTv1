#include "rt.h"

double	distance(t_vec *vec)
{
	return (sqrt((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z)));
}

void	normalized(t_vec *vec)
{
	double	dist;
	double	inv_dist;

	dist = (vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z);

	if (dist > 0)
	{	
		inv_dist = 1 / (sqrt(dist));
		vec->x *= inv_dist;
		vec->y *= inv_dist;
		vec->z *= inv_dist;
	}
}

double	dot_product(t_vec *a, t_vec *b)
{
	return ((a->x * b->x) + (a->y * b->y) + (a->z * b->z));
}

t_vec	*cross_product(t_vec *a, t_vec *b)
{
	t_vec	*c;

	c->x = (a->y * b->z) - (a->z * b->y);
	c->y = (a->z * b->x) - (a->x * b->z);
	c->z = (a->x * b->y) - (a->y * b->x);

	return (c);
}