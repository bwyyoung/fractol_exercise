/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/05 13:18:31 by byoung-w          #+#    #+#             */
/*   Updated: 2013/10/05 13:24:22 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_getcolor(int r, int g, int b)
{
	return (((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF));
}

int		ft_getcol(int imax, int i)
{
	return (i / imax);
}

int		build_color(t_window *data)
{
	int		rgb[3];
	double	t;

	if (REF_F.color == 0)
	{
		rgb[0] = (REF_F.iter_cur * 255) / REF_F.maxiterations;
		rgb[1] = (REF_F.iter_cur * 255) / REF_F.maxiterations;
		rgb[2] = (REF_F.iter_cur * 255) / REF_F.maxiterations;
	}
	else
	{
		t = (double)REF_F.iter_cur / (double)REF_F.maxiterations;
		rgb[0] = (int)(9 * (1 - t) * t * t * t * 255);
		rgb[1] = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		rgb[2] = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
	return (ft_getcolor(rgb[0], rgb[1], rgb[2]));
}

int		build_color_reverse(t_window *data)
{
	int		rgb[3];
	double	t;

	if (REF_F.color == 0)
	{
		rgb[0] = 255 - (REF_F.iter_cur * 255) / REF_F.maxiterations;
		rgb[1] = 255 - (REF_F.iter_cur * 255) / REF_F.maxiterations;
		rgb[2] = 255 - (REF_F.iter_cur * 255) / REF_F.maxiterations;
	}
	else
	{
		t = (double)REF_F.iter_cur / (double)REF_F.maxiterations;
		rgb[0] = 255 - (int)(9 * (1 - t) * t * t * t * 255);
		rgb[1] = 255 - (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		rgb[2] = 255 - (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
	return (ft_getcolor(rgb[0], rgb[1], rgb[2]));
}
