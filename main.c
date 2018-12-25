#include "fractol.h"

void		mandelbrot(t_env *env)
{
	t_point 	pos;
	t_complex 	cur;
	int			n;

	n = 2 + 1;
	pos = new_point(0, 0, 0, 0);
	while (++pos.y < env->win_size.y)
	{
		pos.x = 0;
		while (++pos.x < env->win_size.x)
		{
			cur.r = toReal(pos, env, env->fractal.min.r, env->fractal.max.r);
			cur.i = toComplex(pos, env, env->fractal.min.i, env->fractal.max.i);
			n = calcMandel(cur, env->fractal.iter);
			put_pixel(env, new_point(pos.x, pos.y, 0, 0), RGB(255 % n, 255 % n, 255 % n));
		}
	}
}

int			main(int ac, char **arg)
{
	t_env env;
	
	if (ac != 2)
		die("usage: ./fractol [julia | mandelbrot]\n");
	init_fractol(&env, arg[1]);
	mlx_loop(env.mlx);
	return (0);
}