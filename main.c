/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 05:37:48 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 05:37:49 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int			h_key(int key, t_env *env)
{
	if (key == kVK_RightArrow)
		env->offset_x += 35.0 / ((350.0 / 2.0) / (env->zoom));
	if (key == kVK_LeftArrow)
		env->offset_x -= 35.0 / ((350.0 / 2.0) / (env->zoom));
	if (key == kVK_UpArrow)
		env->offset_y += 35.0 / ((350.0 / 2.0) / (env->zoom));
	if (key == kVK_DownArrow)
		env->offset_y -= 35.0 / ((350.0 / 2.0) / (env->zoom));
	if (key == kVK_Space)
		env->b_mouse *= -1;
	if (key == kVK_ANSI_R)
	{
		env->zoom = 1.f;
		env->offset_x = 0.01;
		env->offset_y = 0.01;
	}
	if (key == kVK_Escape)
		exit(0);
	render_fractal(env);
	return (0);
}

int			h_mouse(int key, int x, int y, t_env *env)
{
	if (key == 5)
		env->zoom *= 1.1;
	if (key == 4)
		env->zoom *= 0.9;
	x = y;
	render_fractal(env);
	return (0);
}

int			h_motion(int x, int y, t_env *env)
{
	if (env->b_mouse == -1 || env->fractal != JULIA)
		return (0);
	if (x < 0 || x > WIN_W || y < 0 || y > WIN_H)
		return (0);
	env->c.r = to_real(new_point((double)x, 0, 0, 0), (-1.0), 1.0, env) /
		env->zoom;
	env->c.i = to_complex(new_point(0, (double)y, 0, 0), (-1.0), 1.0, env) /
		env->zoom;
	render_fractal(env);
	return (0);
}

int			main(int ac, char **arg)
{
	t_env env;

	if (ac != 2)
		die("usage: ./fractol [julia | mandelbrot | burningship]\n");
	init_fractol(&env, arg[1]);
	mlx_hook(env.win, 2, 0, h_key, &env);
	mlx_mouse_hook(env.win, h_mouse, &env);
	mlx_hook(env.win, 6, 0, h_motion, &env);
	mlx_loop(env.mlx);
	return (0);
}
