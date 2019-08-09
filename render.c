/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 17:03:10 by byoung-w          #+#    #+#             */
/*   Updated: 2015/04/29 17:03:12 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_subtitles(t_window *data, t_pixel base)
{
	if (!REF_F.crosshair)
		mlx_string_put(data->mlx_ptr, data->mlx_win,
		base.x, base.y + 20, 0xa1a1af, "C - enable crosshair");
	else if (REF_F.crosshair)
		mlx_string_put(data->mlx_ptr, data->mlx_win,
		base.x, base.y + 20, 0xa1a1af, "C - disable crosshair");
	mlx_string_put(data->mlx_ptr, data->mlx_win,
				base.x, base.y + 60, 0xa1a1af, "R - reset camera");
	mlx_string_put(data->mlx_ptr, data->mlx_win,
				base.x, base.y + 80, 0xa1a1af, "(-) - decrease iteration");
	mlx_string_put(data->mlx_ptr, data->mlx_win,
				base.x, base.y + 100, 0xa1a1af, "(+) - increase iteration");
	mlx_string_put(data->mlx_ptr, data->mlx_win, base.x, base.y + 120, 0xa1a1af,
				ft_strjoin("iterations - ", ft_itoa(REF_F.maxiterations)));
}

void		ft_subtitles_2(t_window *data, t_pixel base)
{
	if (ft_strcmp(data->fractol_type, FRACTOL_TYPE_KOCH))
	{
		if (!REF_F.freeze)
			mlx_string_put(data->mlx_ptr, data->mlx_win,
			base.x, base.y, 0xa1a1af, "SPACE - disable mouse move");
		else if (REF_F.freeze)
			mlx_string_put(data->mlx_ptr, data->mlx_win,
			base.x, base.y, 0xa1a1af, "SPACE - enable mouse move");
		if (!REF_F.negative)
			mlx_string_put(data->mlx_ptr, data->mlx_win, base.x, base.y + 40,
						0xa1a1af, "N - enable negative colours");
		else if (REF_F.negative)
			mlx_string_put(data->mlx_ptr, data->mlx_win, base.x, base.y + 40,
						0xa1a1af, "N - disable negative colours");
	}
}

void		render_crosshair(t_window *data, int size)
{
	t_coord		left;
	t_coord		right;
	t_coord		up;
	t_coord		down;

	left.x = WINDOW_W / 2 - size;
	left.y = WINDOW_H / 2;
	right.x = WINDOW_W / 2 + size;
	right.y = WINDOW_H / 2;
	up.x = WINDOW_W / 2;
	up.y = WINDOW_H / 2 - size;
	down.x = WINDOW_W / 2;
	down.y = WINDOW_H / 2 + size;
	render_line(data, &left, &right, rgb_to_color(255, 0, 0));
	render_line(data, &up, &down, rgb_to_color(255, 0, 0));
}

void		render(t_window *data)
{
	t_pixel		base;

	base.x = WINDOW_W / 20;
	base.y = WINDOW_H / 20;
	if (ft_strcmp(data->fractol_type, FRACTOL_TYPE_JULIA) == 0)
		render_julia(data);
	else if (ft_strcmp(data->fractol_type, FRACTOL_TYPE_MANDEL) == 0)
		render_mandelbrot(data);
	mlx_put_image_to_window(
			data->mlx_ptr, data->mlx_win, data->img.mlx_img, 0, 0);
	if (ft_strcmp(data->fractol_type, FRACTOL_TYPE_KOCH) == 0)
		render_koch(data);
	if (REF_F.crosshair)
		render_crosshair(data, 20);
	ft_subtitles(data, base);
	ft_subtitles_2(data, base);
}
