/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   complex.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 05:30:45 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 05:30:47 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

t_complex	c_sum(t_complex a, t_complex b)
{
	a.r += b.r;
	a.i += b.i;
	return (a);
}

double		to_real(t_point pos, const double minr,
	const double maxr, t_env *env)
{
	return (((pos.x * ((maxr - minr) / WIN_W) + minr) * env->zoom)) +
	env->offset_x;
}

double		to_complex(t_point pos, const double mini,
	const double maxi, t_env *env)
{
	return (((pos.y * ((maxi - mini) / WIN_H) + mini) * env->zoom)) +
	env->offset_y;
}
