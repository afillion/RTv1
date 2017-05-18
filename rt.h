#ifndef RT_H
#define RT_H

#include <math.h>
#define WIDTH 600
#define HEIGHT 800

typedef	struct 	s_ptn
{
	double		x;
	double		y;
	double		z;
}				t_ptn;

typedef struct 	s_view
{
	double		width;
	double		height;
	double		dist;
}				t_view;

typedef struct 	s_cam
{
	t_pos		ptn;
	t_plan		view;
}				t_cam;

typedef struct 	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

typedef struct	s_matrix
{
	double		m[4][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}}; //initialized with the matrix identity
}				t_matrix;

t_vec		*addition_vec(t_vec *a, t_vec *b);
t_vec		*substract_vec(t_vec *a, t_vec *b);
t_vec		*multiple_vec(t_vec *a, t_vec *b);
double		distance(t_vec *a, t_vec *b);
void		normalized(t_vec *vec);
double		dot_product(t_vec *a, t_vec *b);
t_vec		*cross_product(t_vec *a, t_vec *b);
t_matrix	*multiple_mat(t_matrix *m1, t_matrix *m2);
t_ptn		*multiple_ptn_mat(t_ptn *ptn, t_matrix *m);
t_vec		*multiple_vec_mat(t_vec *vec, t_matrix *m);

#endif