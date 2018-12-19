/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/08 03:16:11 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/08 08:07:07 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ZGL_H
# define ZGL_H

# include "minilib/mlx.h"
# include "libft/includes/get_next_line.h"
# include "math.h"
# define W 2560
# define H 1440
# define RGB(r,g,b) (r) * 65536 + (g) * 256 + (b)

typedef unsigned char t_byte;

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
	int				color;
}					t_point;

typedef struct		s_index
{
	int				x;
	int				y;
}					t_index;

typedef struct		s_cam
{
	t_point			pos;
	float			zoom;
}					t_cam;

typedef struct		s_img
{
	void			*ptr;
	int				*image;
	int				szl;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_map
{
	void			**map;
	t_index			size;
}					t_map;

typedef struct		s_file
{
	char			*path;
	int				fd;
}					t_file;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_map			**map;
	t_img			img;
	t_cam			cam;
	t_index			win_size;
	t_file			file;
}					t_env;

/**** CORE FUNCS ****/
void				init_zgl(t_env *env, int width, int height, char *w_name);
void				render(t_env *env);
void				clear(t_env *env);

/**** DRAW FUNCS ****/
void				put_pixel(t_env *env, t_point pos, int color);
void				put_line(t_env *env, t_point src, t_point dst, int color);
void                put_rect(t_env *env, t_point pos, t_point size, t_byte fill, int color);

/**** UTILS FUNCS ****/
t_point				new_point(float x, float y, float z, int color);

#endif
