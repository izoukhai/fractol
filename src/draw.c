/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 17:30:45 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 17:30:46 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../zGL.h"

void				put_pixel(t_env *env, t_point pos, int color)
{
	if ((pos.x > 0 && pos.x < env->win_size.x) &&
		(pos.y > 0 && pos.y < env->win_size.y))
			env->img.image[((int)pos.y * env->win_size.x + (int)pos.x)] = color;
}

void                put_rect(t_env *env, t_point pos, t_point size, t_byte fill, int color)
{
	t_point cur;

	cur.x = pos.x + size.x;
	cur.y = pos.y + size.y;
	if (fill == 0)
	{
		put_line(env, pos, new_point(cur.x, pos.y, pos.z, pos.color),
				color);
		put_line(env, pos, new_point(pos.x, pos.y + size.y, pos.z, pos.color),
				color); 
		put_line(env, cur, new_point(cur.x - size.x - 1, cur.y, 0, 0), color);
		put_line(env, cur, new_point(cur.x, cur.y - size.y - 1, 0, 0), color);
	}
	else
		while (pos.y < cur.y + 1)
		{
			put_line(env, pos, new_point(cur.x + 1, pos.y, 0, 0), color);
			pos.y++;
		}
}
