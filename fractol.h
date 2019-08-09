/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2015/05/01 03:46:36 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/includes/libft.h"
# include "ft_printf/ft_printf.h"
# include "libft/includes/get_next_line.h"
# include "minilibx_macos/mlx.h"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include <string.h>
# define WIN_NAME	"fractol - byoung-w"
# define WINDOW_W 640
# define WINDOW_H 480
# define WINDOW_LEFT 10
# define WINDOW_RIGHT 10
# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_1 18
# define KEY_2 19
# define KEY_C 8
# define KEY_J 38
# define KEY_K 40
# define KEY_M 46
# define KEY_N 45
# define KEY_R 15
# define KEY_SPACE 49
# define KEY_MINUS 78
# define KEY_PLUS 69
# define BUTTON_MOUSE_LEFT 1
# define BUTTON_MOUSE_RIGHT 2

# define BUTTON_MOUSE_WHEELUP 4
# define BUTTON_MOUSE_WHEELDOWN 5
# define FRACTOL_TYPE_JULIA "j"
# define FRACTOL_TYPE_MANDEL "m"
# define FRACTOL_TYPE_KOCH "k"
# define REF_F data->fract
# define REF_K data->koch
# define KOCH_MIN_DISTANCE 10
# define KOCH_MIN_SCALE 0.00001
# define ABS(x) (x > 0 ? x : -x)
# define MIN(x, y) (x < y ? x : y)
# define TO_HEX(i) (i <= 9 ? '0' + i : 'A' - 10 + i)

# define INSIDE  0
# define LEFT  1
# define RIGHT  2
# define BOTTOM  4
# define TOP 8

typedef int		t_code;

typedef struct		s_pixel
{
	int				h;
	int				x;
	int				y;
}					t_pixel;

typedef struct		s_coord
{
	int				h;
	double			x;
	double			y;
}					t_coord;

typedef struct		s_image
{
	void			*mlx_img;
	char			*mlx_img_data;
	int				size_line;
	int				bpp;
	int				endian;
}					t_image;

typedef struct		s_outcode
{
	t_pixel			p1;
	t_pixel			p2;
	t_code			c0;
	t_code			c1;
	t_code			output;
	t_pixel			result;
	int				clipped;
}					t_outcode;

typedef struct		s_fractal
{
	t_pixel			mouse_pos;
	double			z_delta_x;
	double			z_delta_y;
	double			cre;
	double			cim;
	double			newre;
	double			oldre;
	double			oldim;
	double			newim;
	double			zoom;
	int				maxiterations;
	int				iter_cur;
	int				color;
	int				crosshair;
	int				negative;
	int				freeze;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			zoom_x;
	double			zoom_y;
}					t_fractal;

typedef struct		s_render
{
	double			x_slope;
	double			y_slope;
	t_coord			*start;
	t_coord			*end;
	double			error;
}					t_render;

typedef struct		s_koch
{
	t_coord			s_bound;
	t_coord			e_bound;
	double			sin60;
	double			cos60;
	double			sqrt3;
	double			h;
	double			w;
	double			degree;
	double			top;
	t_coord			p1;
	t_coord			p2;
	t_coord			p3;
	t_coord			scale;
	t_coord			new_map;
	t_coord			ratio;
}					t_koch;

typedef struct		s_window
{
	void			*mlx_ptr;
	void			*mlx_win;
	t_image			img;
	t_koch			koch;
	t_fractal		fract;
	char			*title;
	char			*fractol_type;
	int				pfd;
	int				status;
	size_t			def_width;
	size_t			def_height;
}					t_window;

char				**ft_split(char *str);
int					mouse_hook(int button, int x, int y, t_window *data);
int					expose_hook(t_window *data);
int					key_hook(int keycode, t_window *data);
int					mouse_move_hook(int x, int y, t_window *data);
void				readfile(t_window *data);
void				ft_putendl_exit(char const *s);
size_t				ft_arrlen(char **array);
void				ft_list_push_back(t_list **begin_list,
					void *data, int thesize);
int					render_line(t_window *data, t_coord *start, t_coord *end,
int color);
int					rgb_to_color(int red, int green, int blue);
void				render(t_window *win);
void				fractol(t_window data);
void				init_julia(t_window *data);
void				init_mandelbrot(t_window *data);
void				init_koch(t_window *data);
void				render_julia(t_window *data);
void				render_mandelbrot(t_window *data);
void				render_koch(t_window *data);
void				build_pixel(t_window *data, int x, int y);

int					build_color_reverse(t_window *data);
int					build_color(t_window *data);

void				init_fractals(t_window *data);
double				distance(t_coord a, t_coord b);
t_outcode			cohen_suth(int x0, int y0, int x1, int y1);

void				render_crosshair(t_window *data, int size);
int					vector_determinant(double x, double y,
										t_coord start, t_coord end);
int					render_color_line(t_window *data, t_coord s, t_coord e);
#endif
