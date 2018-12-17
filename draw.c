/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/17 11:34:30 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 11:34:33 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void				img_put_pixel(t_env *env, t_dot pos, int color)
{
	if ((pos.x > 0 && pos.x < W) && (pos.y > 0 && pos.y < H))
		env->img.image[((int)pos.y * W + (int)pos.x)] = color;
}

static inline void	set_line(t_dot *step, t_dot *src, t_dot *dst)
{
	(*step).x = (*dst).x - (*src).x;
	(*step).y = (*dst).y - (*src).y;
}

void				draw_line(t_env *env, t_dot src, t_dot dst, int color)
{
	t_dot			step;
	int				n;
	int				i;
	t_dot			pos;

	i = -1;
	set_line(&step, &src, &dst);
	if (ABS(step.x) > ABS(step.y))
	{
		n = ABS(step.x);
		step.y /= ABS(step.x);
		step.x /= ABS(step.x);
	}
	else
	{
		n = ABS(step.y);
		step.x /= ABS(step.y);
		step.y /= ABS(step.y);
	}
	while (++i < n)
	{
		new_point(&pos, src, i, step);
		if ((pos.x >= 0 && pos.x <= W) && (pos.y >= 0 && pos.y <= H))
			img_put_pixel(env, pos, color);
	}
}
