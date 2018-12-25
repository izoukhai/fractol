#ifndef FRACTOL_H
#define FRACTOL_H
#include "zGL/zGL.h"

enum e_fracts
{
	MANDELBROT,
	JULIA
};

/* Core funcs */
void			init_fractol(t_env *env, char *arg);

/* Complex funcs */
t_complex   	c_sum(t_complex a, t_complex b);
double			toComplex(t_point pos, t_env *env, double minI, double maxI);
double			toReal(t_point pos, t_env *env, double minR, double maxR);
int				calcMandel(t_complex cur, int n);

/* Fractals */
void			julia(t_env *env);
void			mandelbrot(t_env *env);

#endif
