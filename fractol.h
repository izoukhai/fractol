/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/17 11:22:59 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 11:23:00 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "minilib/mlx.h"
# include "libft/includes/get_next_line.h"
# define W 2560
# define H 1440

typedef struct			s_dot
{
	float				x;
	float				y;
}						t_dot;

typedef struct			s_index
{
	int					i;
	int					j;
}						t_index;

typedef struct			s_axe
{
	t_dot				x;
	t_dot				y;
	t_dot				i;
	t_dot				j;
	t_dot				k;
	t_index				i_off;
	t_index				j_off;
	t_index				k_off;
}						t_axe;

typedef struct			s_map
{
	t_dot				**coord;
	t_axe				axes;
	t_index				size;
}						t_map;

typedef struct			s_cam
{
	float				x;
	float				y;
	float				zoom;
}						t_cam;

typedef struct			s_img
{
	void				*ptr;
	int					*image;
	int					bpp;
	int					szl;
	int					endian;
}						t_img;

typedef struct			s_env
{
	void				*mlx;
	void				*wim;
	t_map				map;
	t_img				img;
	int					type;
}						t_env;

void					kill(char *msg)

#endif
