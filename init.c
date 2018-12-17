/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/17 11:44:49 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 11:44:51 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static inline int	get_fract(char *arg)
{
	int				i;
	char			list[2][10];

	i = -1;
	ft_strcpy(list[0], "julia");
	ft_strcpy(list[1], "mandelbrot");
	while (++i < 2)
		if (ft_strcmp(list[i], arg) == 0)
			return (1);
	return (0);
}

void				init_main(char *arg)
{
	if (get_fract(arg) == 0)
		kill("usage: ./fractol [julia || mandelbrot]");
}
