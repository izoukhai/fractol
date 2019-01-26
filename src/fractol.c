/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 05:34:59 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 05:35:11 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../fractol.h"

static inline char	*to_lower(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		str[i] = ft_tolower(str[i]);
	return (str);
}

static inline void	get_fractal(t_env *env, char *arg)
{
	if (ft_strcmp(arg, "mandelbrot") == 0)
		env->fractal = MANDELBROT;
	else if (ft_strcmp(arg, "julia") == 0)
		env->fractal = JULIA;
	else if (ft_strcmp(arg, "burningship") == 0)
		env->fractal = BURNINGSHIP;
	else
		die("usage: ./fractol [julia | mandelbrot | burningship]\n");
	env->iter = 90;
	env->zoom = 1.f;
	env->b_mouse = -1;
	env->offset_x = 0.1f / env->zoom;
	env->offset_y = 0.1f / env->zoom;
	env->c.r = -1.27;
	env->c.i = 0.8;
}

void				init_fractol(t_env *env, char *arg)
{
	get_fractal(env, to_lower(arg));
	init_zgl(env, WIN_W, WIN_H, "Fract'ol");
	env->lim.r = 5;
	env->lim.i = -5;
	if (env->fractal == MANDELBROT)
		render(env, mandelbrot, 0);
	if (env->fractal == JULIA)
		render(env, julia, 0);
	if (env->fractal == BURNINGSHIP)
		render(env, burningship, 0);
}

void				render_fractal(t_env *env)
{
	if (env->fractal == MANDELBROT)
		render(env, mandelbrot, 1);
	if (env->fractal == JULIA)
		render(env, julia, 1);
	if (env->fractal == BURNINGSHIP)
		render(env, burningship, 1);
}
