/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 05:39:54 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 05:39:55 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "zGL/zgl.h"
# define WIN_W 700.0
# define WIN_H 700.0

enum			e_fracts
{
	MANDELBROT,
	JULIA,
	BURNINGSHIP
};

void			init_fractol(t_env *env, char *arg);
void			render_fractal(t_env *env);

t_complex		c_sum(t_complex a, t_complex b);
double			to_complex(t_point pos, const double mini,
				const double maxi, t_env *env);
double			to_real(t_point pos, const double minr, const double maxr,
				t_env *env);

void			julia(t_env *env);
void			mandelbrot(t_env *env);
void			burningship(t_env *env);
int				calc_mandel(t_complex cur, int n);
int				calc_julia(t_complex cur, int n, t_env *env);
int				calc_burningship(t_complex cur, int n);

#endif
