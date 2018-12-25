#include "../zGL.h"

void				init_zgl(t_env *env, int width, int height, char *w_name)
{
	env->mlx = mlx_init();
	env->win_size.x = width;
	env->win_size.y = height;
	env->win = mlx_new_window(env->mlx, width, height, w_name);
	env->img.ptr = mlx_new_image(env->mlx, width, height);
	env->img.image = (int*)mlx_get_data_addr(env->img.ptr, &(env->img.bpp),
				&(env->img.szl), &(env->img.endian));
}

void				render(t_env *env, void (*func)(), int bclear)
{
	if (bclear)
		clear(env);
	func(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img.ptr, 0, 0);
}

void				clear(t_env *env)
{
	ft_bzero(env->img.image, env->win_size.x * env->win_size.y * 4);
}