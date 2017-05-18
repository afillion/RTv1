#include "rt.h"

t_matrix	*multiple_mat(t_matrix *m1, t_matrix *m2)
{
	t_matrix	*m3;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			m3->m[i][j] = (m1->m[i][0] * m2->m[0][j]) + (m1->m[i][1] * m2->m[1][j]);
			m3->m[i][j] += (m1->m[i][2] * m2->m[2][j]) + (m1->m[i][3] * m2->m[3][j]);
			j++;
		}
		i++;
	}
	return (m3);
}

t_ptn	*multiple_ptn_mat(t_ptn *ptn, t_matrix *m)
{
	t_ptn	*ret;
	double	w;

	ret->x = (ptn->x * m->m[0][0]) + (ptn->y * m->m[1][0]) + (ptn->z * m->[2][0]);
	ret->x += m->m[3][0];
	ret->y = (ptn->x * m->m[0][1]) + (ptn->y * m->m[1][1]) + (ptn->z * m->m[2][1]);
	ret->y += m->m[3][1];
	ret->z = (ptn->x * m->m[0][2]) + (ptn->y * m->m[1][2]) + (ptn->z * m->m[2][2]);
	ret->z += m->m[3][2];
	w = (ptn->x * m->m[0][3]) + (ptn->y * m->m[1][3]) + (ptn->z * m->m[2][3]);
	w += m->m[3][3];
	if (w != 1 && w != 0)
	{
		ret->x /= w;
		ret->y /= w;
		ret->z /= w;
	}
	return (ret);
}

t_vec	*multiple_vec_mat(t_vec *vec, t_matrix *m)
{
	t_vec	*ret;

	ret->x = (vec->x * m->m[0][0]) + (vec->y * m->m[1][0]) + (vec->z * m->[2][0]);
	ret->y = (vec->x * m->m[0][1]) + (vec->y * m->m[1][1]) + (vec->z * m->m[2][1]);
	ret->z = (vec->x * m->m[0][2]) + (vec->y * m->m[1][2]) + (vec->z * m->m[2][2]);
	return (ret);
}
