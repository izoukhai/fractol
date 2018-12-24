#include "fractol.h"

t_complex   c_sum(t_complex a, t_complex b)
{
    a.r += b.r;
    a.i += b.i;
    return(a);
}

double		toReal(t_point pos, t_env *env, double minR, double maxR)
{
	double dist;

	dist = maxR - minR;
	return (pos.x * (dist / env->win_size.x) + minR);
}

double		toComplex(t_point pos, t_env *env, double minI, double maxI)
{
	double dist;

	dist = maxI - minI;
	return (pos.y * (dist / env->win_size.y) + minI);
}

int			calcMandel(t_complex cur, int n)
{
	int		i;
	t_complex z;
	double	tmp;

	i = -1;;
	z.r = 0;
	z.i = 0;
	while (++i < n && z.r * z.r + z.i * z.i < 4)
	{
		tmp = z.r * z.r - z.i * z.i + cur.r;
		z.i = 2 * z.r * z.i + cur.i;
		z.r = tmp;
	}
	return (i);
}