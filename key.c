/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 19:58:29 by byoung-w          #+#    #+#             */
/*   Updated: 2015/04/29 20:13:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int button, int x, int y, t_window *data)
{
	REF_F.mouse_pos.x = x;
	REF_F.mouse_pos.y = y;
	REF_F.zoom_x = (x * (REF_F.x2 - REF_F.x1) / (double)WINDOW_W + REF_F.x1);
	REF_F.zoom_y = (y * (REF_F.y2 - REF_F.y1) / (double)WINDOW_H + REF_F.y1);
	if (button == BUTTON_MOUSE_WHEELDOWN)
	{
		REF_F.x1 = (double)REF_F.zoom_x + (REF_F.x1 - REF_F.zoom_x) * 1.1;
		REF_F.x2 = (double)REF_F.zoom_x + (REF_F.x2 - REF_F.zoom_x) * 1.1;
		REF_F.y1 = (double)REF_F.zoom_y + (REF_F.y1 - REF_F.zoom_y) * 1.1;
		REF_F.y2 = (double)REF_F.zoom_y + (REF_F.y2 - REF_F.zoom_y) * 1.1;
	}
	if (button == BUTTON_MOUSE_WHEELUP)
	{
		REF_F.x1 = (double)REF_F.zoom_x + (REF_F.x1 - REF_F.zoom_x) / 1.1;
		REF_F.x2 = (double)REF_F.zoom_x + (REF_F.x2 - REF_F.zoom_x) / 1.1;
		REF_F.y1 = (double)REF_F.zoom_y + (REF_F.y1 - REF_F.zoom_y) / 1.1;
		REF_F.y2 = (double)REF_F.zoom_y + (REF_F.y2 - REF_F.zoom_y) / 1.1;
	}
	render(data);
	return (0);
}

int		ft_move_normal(t_window *data, int key)
{
	if (key == KEY_RIGHT)
	{
		REF_F.x1 += (0.03 * (REF_F.x2 - REF_F.x1));
		REF_F.x2 += (0.03 * (REF_F.x2 - REF_F.x1));
	}
	else if (key == KEY_LEFT)
	{
		REF_F.x1 -= (0.03 * (REF_F.x2 - REF_F.x1));
		REF_F.x2 -= (0.03 * (REF_F.x2 - REF_F.x1));
	}
	else if (key == KEY_DOWN)
	{
		REF_F.y1 += (0.03 * (REF_F.x2 - REF_F.x1));
		REF_F.y2 += (0.03 * (REF_F.x2 - REF_F.x1));
	}
	else if (key == KEY_UP)
	{
		REF_F.y1 -= (0.03 * (REF_F.x2 - REF_F.x1));
		REF_F.y2 -= (0.03 * (REF_F.x2 - REF_F.x1));
	}
	return (0);
}

int		ft_move(t_window *data, int key)
{
	if (ft_strcmp(data->fractol_type, FRACTOL_TYPE_KOCH))
		return (ft_move_normal(data, key));
	if (key == KEY_RIGHT)
		REF_K.s_bound.x++;
	else if (key == KEY_LEFT)
		REF_K.s_bound.x--;
	else if (key == KEY_DOWN)
		REF_K.s_bound.y++;
	else if (key == KEY_UP)
		REF_K.s_bound.y--;
	return (0);
}

int		key_hook(int keycode, t_window *data)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_J)
		init_julia(data);
	else if (keycode == KEY_M)
		init_mandelbrot(data);
	else if (keycode == KEY_K)
		init_koch(data);
	else if (keycode == KEY_MINUS)
		(REF_F.maxiterations > 1 ? REF_F.maxiterations-- : REF_F.maxiterations);
	else if (keycode == KEY_PLUS)
		REF_F.maxiterations += 1;
	else if (keycode == KEY_R)
		init_fractals(data);
	else if (keycode == KEY_SPACE)
		REF_F.freeze = !REF_F.freeze;
	else if (keycode == KEY_C)
		REF_F.crosshair = !REF_F.crosshair;
	else if (keycode == KEY_N)
		REF_F.negative = !REF_F.negative;
	ft_move(data, keycode);
	render(data);
	return (0);
}

int		mouse_move_hook(int x, int y, t_window *data)
{
	REF_F.mouse_pos.x = x;
	REF_F.mouse_pos.y = y;
	if (REF_F.freeze)
		return (0);
	if (ft_strcmp(data->fractol_type, FRACTOL_TYPE_JULIA) == 0)
	{
		REF_F.cre = 0.38 + x / (double)WINDOW_W * 0.1;
		REF_F.cim = 0.38 + y / (double)WINDOW_H * 0.1;
	}
	render(data);
	return (0);
}
