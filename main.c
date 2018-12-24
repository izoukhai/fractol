#include "fractol.h"

t_complex min = {-1.5, -1};
t_complex max = {0.7, 1};
int			iter = 155;
float zoom = 1;
void		julia(t_env *env)
{
	t_point 	pos;
	t_complex 	cur;
	int			n;

	pos = new_point(0, 0, 0, 0);
	while (++pos.y < env->win_size.y)
	{
		pos.x = 0;
		while (++pos.x < env->win_size.x)
		{
			cur.r = toReal(pos, env, min.r, max.r);
			cur.i = toComplex(pos, env, min.i, max.i);
			n = calcMandel(cur, 255);
			put_pixel(env, new_point(pos.x, pos.y, 0, 0), RGB(255 % n, 255 % n, 255 % n));
		}
	}
}

int hook(int key, t_env *env)
{
	if (key == 61)
	{
		/*min.r += 0.1;
		min.i += 0.1;*/
		max.r -= 0.1;
		max.i -= 0.1;
		clear(env);
		julia(env);
		render(env);
	}	
	env->file.path = "ddd";
	//printf("%d\n", key);
	return (0);
}

int			main()
{
	t_env env;
	//t_complex a = {7, 6};
	init_zgl(&env, 1000, 1000, "s");
	julia(&env);
	render(&env);
	mlx_key_hook(env.win, &hook, &env);
	mlx_loop(env.mlx);
	return (0);
}