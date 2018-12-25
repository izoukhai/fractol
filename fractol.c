#include "fractol.h"

static inline char  *toLower(char *str)
{
    int i;

    i = -1;
    while (str[++i])
        str[i] = ft_tolower(str[i]);
    return (str);
}

static inline void  set_fractals(t_env *env)
{
    if (env->fractal.type == MANDELBROT)
    {
        env->fractal.max.r = 0.7;
        env->fractal.max.i = 1;
        env->fractal.min.r = -1.5;
        env->fractal.min.i = -1;
        env->fractal.iter = 255;
    }
    else
    {
        env->fractal.max.r = 1.8;
        env->fractal.max.i = 2.0;
        env->fractal.min.r = -1.9;
        env->fractal.min.i = -1.4;
        env->fractal.iter = 140;  
    }
}

static inline void  get_fractal(t_env *env, char *arg)
{
    if (ft_strcmp(arg, "mandelbrot") == 0)
        env->fractal.type = MANDELBROT;
    else if (ft_strcmp(arg, "julia") == 0)
        env->fractal.type = JULIA;
    else
        die("usage: ./fractol [julia | mandelbrot]\n");
    set_fractals(env);
}

void                init_fractol(t_env *env, char *arg)
{
    get_fractal(env, toLower(arg));
    init_zgl(env, 1000, 1000, "Fract'ol");
    render(env, mandelbrot, 0);
}

