/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractals.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 05:12:38 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 05:12:38 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void			mandelbrot(t_env *env)
{
	t_point		pos;
	t_complex	cur;
	int			n;

	pos = new_point(0, 0, 0, 0);
	while (++pos.y < WIN_H)
	{
		pos.x = 0;
		while (++pos.x < WIN_W)
		{
			cur.r = to_real(pos, env->lim.i, env->lim.r, env);
			cur.i = to_complex(pos, env->lim.i, env->lim.r, env);
			n = calc_mandel(cur, env->iter);
			put_pixel(env, new_point(pos.x, pos.y, 0, 0),
				RGB(100 % n, 255 % n, 255 % n));
		}
	}
}

void			julia(t_env *env)
{
	t_point		pos;
	t_complex	cur;
	int			n;

	pos = new_point(0, 0, 0, 0);
	while (++pos.y < WIN_H)
	{
		pos.x = 0;
		while (++pos.x < WIN_W)
		{
			cur.r = to_real(pos, env->lim.i, env->lim.r, env);
			cur.i = to_complex(pos, env->lim.i, env->lim.r, env);
			n = calc_julia(cur, env->iter, env);
			put_pixel(env, new_point(pos.x, pos.y, 0, 0),
				RGB(140 % n, 255 % n, 255 % n));
		}
	}
}

void			burningship(t_env *env)
{
	t_point		pos;
	t_complex	cur;
	int			n;

	pos = new_point(0, 0, 0, 0);
	while (++pos.y < WIN_H)
	{
		pos.x = 0;
		while (++pos.x < WIN_W)
		{
			cur.r = to_real(pos, env->lim.i, env->lim.r, env);
			cur.i = to_complex(pos, env->lim.i, env->lim.r, env);
			n = calc_burningship(cur, env->iter);
			put_pixel(env, new_point(pos.x, pos.y, 0, 0),
				RGB(170 % n, 25 % n, 0 % n));
		}
	}
}
