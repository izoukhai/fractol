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

#include "../zgl.h"

void				put_pixel(t_env *env, t_point pos, int color)
{
	if ((pos.x > 0 && pos.x < env->win_size.x) &&
		(pos.y > 0 && pos.y < env->win_size.y))
		env->img.image[((int)pos.y * env->win_size.x + (int)pos.x)] = color;
}
