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

#endif