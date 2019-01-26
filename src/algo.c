/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/16 18:27:49 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 18:27:49 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../fractol.h"

int				calc_mandel(t_complex cur, int n)
{
	int			i;
	t_complex	z;
	double		tmp;

	i = -1;
	z.r = 0;
	z.i = 0;
	while (++i < n && z.r * z.r + z.i * z.i <= 4)
	{
		tmp = z.r * z.r - z.i * z.i + cur.r;
		z.i = 2 * z.r * z.i + cur.i;
		z.r = tmp;
	}
	return (i + 20);
}

int				calc_julia(t_complex cur, int n, t_env *env)
{
	int			i;
	t_complex	z;
	double		tmp;

	i = -1 - env->fractal + env->fractal;
	z = cur;
	while (++i < n && z.r * z.r + z.i * z.i < 4.0)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + env->c.r;
		z.i = 2 * z.i * tmp + env->c.i;
	}
	return (i + 70);
}

int				calc_burningship(t_complex cur, int n)
{
	int			i;
	t_complex	z;
	double		tmp;

	i = -1;
	z.r = 0;
	z.i = 0;
	while (++i < n && z.r * z.r + z.i * z.i <= 4)
	{
		tmp = z.r * z.r - z.i * z.i + cur.r;
		z.i = 2 * fabsl(z.r * z.i) + cur.i;
		z.r = tmp;
	}
	return (i + 20);
}
