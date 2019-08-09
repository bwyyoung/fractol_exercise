/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 17:03:10 by byoung-w          #+#    #+#             */
/*   Updated: 2015/04/29 17:03:12 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			init(t_render *render, t_coord *start, t_coord *end)
{
	render->start = start;
	render->end = end;
	if ((render->start->x < 0 || render->start->x > WINDOW_W)
			|| (render->start->y < 0 || render->start->y > WINDOW_H))
	{
		render->start = end;
		render->end = start;
	}
	render->x_slope = fabs(render->end->x - render->start->x);
	render->y_slope = fabs(render->end->y - render->start->y);
	render->error = (render->x_slope > render->y_slope ?
						render->x_slope : -render->y_slope) / 2;
}

static void			x_move(t_render *render)
{
	render->error -= render->y_slope;
	render->start->x += render->start->x < render->end->x ? 1 : -1;
}

static void			y_move(t_render *render)
{
	render->error += render->x_slope;
	render->start->y += render->start->y < render->end->y ? 1 : -1;
}

int					rgb_to_color(int red, int green, int blue)
{
	return (red * 256 * 256 + green * 256 + blue);
}

int					render_line(t_window *data,
								t_coord *start, t_coord *end, int color)
{
	t_render render;

	init(&render, start, end);
	while (1)
	{
		mlx_pixel_put(data->mlx_ptr, data->mlx_win,
					(int)render.start->x, (int)render.start->y, color);
		if ((int)render.start->x == (int)render.end->x &&
				(int)render.start->y == (int)render.end->y)
			return (0);
		if (render.error > -render.x_slope)
			x_move(&render);
		if (render.error < render.y_slope)
			y_move(&render);
		if (render.start->x < 0 || render.start->x > WINDOW_W)
			return (0);
		if (render.start->y < 0 || render.start->y > WINDOW_H)
			return (0);
	}
}
