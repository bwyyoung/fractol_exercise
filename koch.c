/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 19:58:29 by byoung-w          #+#    #+#             */
/*   Updated: 2015/04/29 20:13:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_koch_coordinates(t_window *data)
{
	REF_K.h = REF_K.e_bound.y;
	REF_K.w = REF_K.h / (REF_K.sqrt3 * 2 / 3);
	REF_K.top = REF_K.s_bound.y + (REF_K.e_bound.y - REF_K.h) * 0.5
				+ (REF_K.h * 0.25);
	REF_K.p1.x = REF_K.s_bound.x + ((REF_K.e_bound.x - REF_K.w) * 0.5);
	REF_K.p1.y = REF_K.top;
	REF_K.p2.x = REF_K.s_bound.x + ((REF_K.e_bound.x + REF_K.w) * 0.5);
	REF_K.p2.y = REF_K.top;
	REF_K.p3.x = REF_K.s_bound.x + REF_K.e_bound.x * 0.5;
	REF_K.p3.y = REF_K.s_bound.y + REF_K.e_bound.y
				+ (REF_K.h - REF_K.e_bound.y) * 0.5;
}

void		init_koch(t_window *data)
{
	size_t bzero_len;

	data->fractol_type = "k";
	bzero_len = (size_t)(WINDOW_W * WINDOW_H * (data->img.bpp / 8));
	ft_bzero(data->img.mlx_img_data, bzero_len);
	REF_F.x1 = 0;
	REF_F.x2 = WINDOW_W;
	REF_F.y1 = 0;
	REF_F.y2 = WINDOW_H;
	REF_K.s_bound.x = 0;
	REF_K.s_bound.y = 0;
	REF_K.e_bound.x = WINDOW_W;
	REF_K.e_bound.y = WINDOW_H;
	REF_K.cos60 = 0.5;
	REF_K.sin60 = sin(60 * 180.0 / M_PI);
	REF_K.sqrt3 = sqrt(3);
	REF_F.maxiterations = 1;
}

int			check_boundary(t_window *data, t_coord a, t_coord b, int degree)
{
	if ((vector_determinant(0, 0, a, b) > 0) &&
		(vector_determinant(WINDOW_W, 0, a, b) > 0 &&
		(vector_determinant(WINDOW_W, WINDOW_H, a, b) > 0) &&
		(vector_determinant(0, WINDOW_H, a, b) > 0)))
		return (0);
	if ((!cohen_suth(a.x, a.y, b.x, b.y).clipped
		&& degree >= REF_F.maxiterations / 2)
		|| (ABS(distance(a, b)) < KOCH_MIN_DISTANCE)
		|| degree >= REF_F.maxiterations)
		return (render_color_line(data, a, b));
	return (1);
}

void		draw_segment(t_window *data, t_coord a, t_coord b, int degree)
{
	t_coord pa;
	t_coord pb;
	t_coord ptip;
	t_coord distance;

	if (!check_boundary(data, a, b, degree))
		return ;
	else
	{
		distance.x = (b.x - a.x) / 3;
		distance.y = (b.y - a.y) / 3;
		pa.x = a.x + distance.x;
		pa.y = a.y + distance.y;
		pb.x = b.x - distance.x;
		pb.y = b.y - distance.y;
		ptip.x = pa.x + distance.x * REF_K.cos60 + distance.y * REF_K.sin60;
		ptip.y = pa.y + distance.y * REF_K.cos60 - distance.x * REF_K.sin60;
		draw_segment(data, a, pa, degree + 1);
		draw_segment(data, pa, ptip, degree + 1);
		draw_segment(data, ptip, pb, degree + 1);
		draw_segment(data, pb, b, degree + 1);
	}
}

void		render_koch(t_window *data)
{
	REF_K.scale.x = WINDOW_W / (REF_F.x2 - REF_F.x1);
	REF_K.scale.y = WINDOW_H / (REF_F.y2 - REF_F.y1);
	REF_K.scale.x = (REF_K.scale.x <
					KOCH_MIN_SCALE ? KOCH_MIN_SCALE : REF_K.scale.x);
	REF_K.scale.y = (REF_K.scale.y <
					KOCH_MIN_SCALE ? KOCH_MIN_SCALE : REF_K.scale.y);
	REF_K.new_map.x = WINDOW_W / (REF_K.scale.x);
	REF_K.new_map.y = WINDOW_H / (REF_K.scale.y);
	REF_K.ratio.x = (REF_F.mouse_pos.x - REF_K.s_bound.x) / REF_K.e_bound.x;
	REF_K.ratio.y = (REF_F.mouse_pos.y - REF_K.s_bound.y) / REF_K.e_bound.y;
	REF_K.s_bound.x = REF_F.mouse_pos.x - REF_K.ratio.x * REF_K.new_map.x;
	REF_K.s_bound.y = REF_F.mouse_pos.y - REF_K.ratio.y * REF_K.new_map.y;
	REF_K.e_bound.x = REF_K.new_map.x;
	REF_K.e_bound.y = REF_K.new_map.y;
	init_koch_coordinates(data);
	draw_segment(data, REF_K.p1, REF_K.p2, 0);
	draw_segment(data, REF_K.p2, REF_K.p3, 0);
	draw_segment(data, REF_K.p3, REF_K.p1, 0);
}
