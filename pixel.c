/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/05 13:18:31 by byoung-w          #+#    #+#             */
/*   Updated: 2013/10/05 13:24:22 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_window *data, int y, int x, int color)
{
	((int*)(data->img.mlx_img_data))[y * WINDOW_W + x] = color;
}

void	build_pixel(t_window *data, int x, int y)
{
	int		col;
	int		col_unused;

	col_unused = ((REF_F.iter_cur % 256) << 16)
				+ (255 << 8) + (255 * REF_F.iter_cur);
	if (REF_F.iter_cur == REF_F.maxiterations)
		col = 0x000000;
	else
		col = (REF_F.negative) ? build_color_reverse(data) : build_color(data);
	put_pixel(data, y, x, mlx_get_color_value(data->mlx_ptr, col));
}

int		render_color_line(t_window *data, t_coord s, t_coord e)
{
	int		r;
	int		g;
	int		b;

	r = sin(1 / REF_K.scale.x * .3) * 127 + 128;
	g = sin(1 / REF_K.scale.x * .3 + 2) * 127 + 128;
	b = sin(1 / REF_K.scale.x * .3 + 4) * 127 + 128;
	render_line(data, &s, &e, rgb_to_color(r, g, b));
	return (0);
}
