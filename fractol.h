#ifndef FRACTOL_H
#define FRACTOL_H
#include "zGL/zGL.h"

typedef struct s_complex
{
	double r;
	double i;
}               t_complex;

/* Complex funcs */
t_complex   	c_sum(t_complex a, t_complex b);
double			toComplex(t_point pos, t_env *env, double minI, double maxI);
double			toReal(t_point pos, t_env *env, double minR, double maxR);
int				calcMandel(t_complex cur, int n);

#endif
