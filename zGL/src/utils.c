/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 18:07:01 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 18:07:02 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../zGL.h"

t_point		new_point(float x, float y, float z, int color)
{
    t_point res;

    res.x = x;
    res.y = y;
    res.z = z;
    res.color = color;
    return (res);
}

void        die(char *msg)
{
    ft_putstr_fd(msg, 2);
    exit(1);
}
