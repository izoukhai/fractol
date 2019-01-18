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
# define RGB(r,g,b) (r << 16) + (g << 8) + (b)

typedef unsigned char	t_byte;

typedef struct			s_point
{
	float				x;
	float				y;
	float				z;
	int					color;
}						t_point;

typedef struct			s_index
{
	int					x;
	int					y;
}						t_index;

typedef struct			s_cam
{
	t_point				pos;
	float				zoom;
}						t_cam;

typedef struct			s_img
{
	void				*ptr;
	int					*image;
	int					szl;
	int					bpp;
	int					endian;
}						t_img;

typedef struct			s_map
{
	void				**map;
	t_index				size;
}						t_map;

typedef struct			s_file
{
	char				*path;
	int					fd;
}						t_file;

typedef struct			s_complex
{
	double				r;
	double				i;
}						t_complex;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	int					fractal;
	int					iter;
	double				zoom;
	t_img				img;
	double				offset_x;
	double				offset_y;
	t_index				win_size;
	int					b_mouse;
	t_complex			c;
	t_complex			lim;
}						t_env;

enum					e_keys
{
	kVK_ANSI_A = 0x00,
	kVK_ANSI_S = 0x01,
	kVK_ANSI_D = 0x02,
	kVK_ANSI_F = 0x03,
	kVK_ANSI_H = 0x04,
	kVK_ANSI_G = 0x05,
	kVK_ANSI_Z = 0x06,
	kVK_ANSI_X = 0x07,
	kVK_ANSI_C = 0x08,
	kVK_ANSI_V = 0x09,
	kVK_ANSI_B = 0x0B,
	kVK_ANSI_Q = 0x0C,
	kVK_ANSI_W = 0x0D,
	kVK_ANSI_E = 0x0E,
	kVK_ANSI_R = 0x0F,
	kVK_ANSI_Y = 0x10,
	kVK_ANSI_T = 0x11,
	kVK_ANSI_1 = 0x12,
	kVK_ANSI_2 = 0x13,
	kVK_ANSI_3 = 0x14,
	kVK_ANSI_4 = 0x15,
	kVK_ANSI_6 = 0x16,
	kVK_ANSI_5 = 0x17,
	kVK_ANSI_Equal = 0x18,
	kVK_ANSI_9 = 0x19,
	kVK_ANSI_7 = 0x1A,
	kVK_ANSI_Minus = 0x1B,
	kVK_ANSI_8 = 0x1C,
	kVK_ANSI_0 = 0x1D,
	kVK_ANSI_RightBracket = 0x1E,
	kVK_ANSI_O = 0x1F,
	kVK_ANSI_U = 0x20,
	kVK_ANSI_LeftBracket = 0x21,
	kVK_ANSI_I = 0x22,
	kVK_ANSI_P = 0x23,
	kVK_ANSI_L = 0x25,
	kVK_ANSI_J = 0x26,
	kVK_ANSI_Quote = 0x27,
	kVK_ANSI_K = 0x28,
	kVK_ANSI_Semicolon = 0x29,
	kVK_ANSI_Backslash = 0x2A,
	kVK_ANSI_Comma = 0x2B,
	kVK_ANSI_Slash = 0x2C,
	kVK_ANSI_N = 0x2D,
	kVK_ANSI_M = 0x2E,
	kVK_ANSI_Period = 0x2F,
	kVK_ANSI_Grave = 0x32,
	kVK_ANSI_KeypadDecimal = 0x41,
	kVK_ANSI_KeypadMultiply = 0x43,
	kVK_ANSI_KeypadPlus = 0x45,
	kVK_ANSI_KeypadClear = 0x47,
	kVK_ANSI_KeypadDivide = 0x4B,
	kVK_ANSI_KeypadEnter = 0x4C,
	kVK_ANSI_KeypadMinus = 0x4E,
	kVK_ANSI_KeypadEquals = 0x51,
	kVK_ANSI_Keypad0 = 0x52,
	kVK_ANSI_Keypad1 = 0x53,
	kVK_ANSI_Keypad2 = 0x54,
	kVK_ANSI_Keypad3 = 0x55,
	kVK_ANSI_Keypad4 = 0x56,
	kVK_ANSI_Keypad5 = 0x57,
	kVK_ANSI_Keypad6 = 0x58,
	kVK_ANSI_Keypad7 = 0x59,
	kVK_ANSI_Keypad8 = 0x5B,
	kVK_ANSI_Keypad9 = 0x5C,
	kVK_Return = 0x24,
	kVK_Tab = 0x30,
	kVK_Space = 0x31,
	kVK_Delete = 0x33,
	kVK_Escape = 0x35,
	kVK_Command = 0x37,
	kVK_Shift = 0x38,
	kVK_CapsLock = 0x39,
	kVK_Option = 0x3A,
	kVK_Control = 0x3B,
	kVK_RightCommand = 0x36,
	kVK_RightShift = 0x3C,
	kVK_RightOption = 0x3D,
	kVK_RightControl = 0x3E,
	kVK_Function = 0x3F,
	kVK_F17 = 0x40,
	kVK_VolumeUp = 0x48,
	kVK_VolumeDown = 0x49,
	kVK_Mute = 0x4A,
	kVK_F18 = 0x4F,
	kVK_F19 = 0x50,
	kVK_F20 = 0x5A,
	kVK_F5 = 0x60,
	kVK_F6 = 0x61,
	kVK_LeftArrow = 0x7B,
	kVK_RightArrow = 0x7C,
	kVK_DownArrow = 0x7D,
	kVK_UpArrow = 0x7E
};

void					init_zgl(t_env *env, int width, int height,
							char *w_name);
void					render(t_env *env, void (*func)(t_env*),
							int bclear);
void					clear(t_env *env);

void					put_pixel(t_env *env, t_point pos, int color);
void					put_line(t_env *env, t_point src, t_point dst,
							int color);

t_point					new_point(float x, float y, float z, int color);
void					die(char *msg);

#endif
