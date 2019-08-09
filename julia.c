/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 19:58:29 by byoung-w          #+#    #+#             */
/*   Updated: 2015/04/29 20:13:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_julia(t_window *data)
{
	data->fractol_type = "j";
	REF_F.cre = -0.7;
	REF_F.cim = 0.27015;
	REF_F.zoom = 1;
	REF_F.maxiterations = 70;
	REF_F.x1 = -1.4;
	REF_F.x2 = 1.4;
	REF_F.y1 = -1.05;
	REF_F.y2 = 1.05;
}

int			render_julia_iter(t_window *data)
{
	int		i;

	i = -1;
	while (i++ < REF_F.maxiterations)
	{
		REF_F.oldre = REF_F.newre;
		REF_F.oldim = REF_F.newim;
		REF_F.newre = REF_F.oldre * REF_F.oldre -
					REF_F.oldim * REF_F.oldim + REF_F.cre;
		REF_F.newim = 2 * REF_F.oldre * REF_F.oldim + REF_F.cim;
		if ((REF_F.newre * REF_F.newre + REF_F.newim * REF_F.newim) > 4)
			break ;
	}
	return (i);
}

void		render_julia(t_window *data)
{
	int x;
	int y;

	x = -1;
	while (++x < WINDOW_W)
	{
		y = -1;
		while (++y < WINDOW_H)
		{
			REF_F.newre = ((x * (REF_F.x2 - REF_F.x1)) / WINDOW_W + REF_F.x1);
			REF_F.newim = ((y * (REF_F.y2 - REF_F.y1)) / WINDOW_H + REF_F.y1);
			REF_F.iter_cur = render_julia_iter(data);
			build_pixel(data, x, y);
		}
	}
}
