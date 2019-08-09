/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cohen_suth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 19:58:29 by byoung-w          #+#    #+#             */
/*   Updated: 2015/04/29 20:13:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_code		get_outcode(int x, int y)
{
	t_code		code;

	code = INSIDE;
	if (x < 0)
		code |= LEFT;
	else if (x > WINDOW_W)
		code |= RIGHT;
	if (y < 0)
		code |= BOTTOM;
	else if (y > WINDOW_H)
		code |= TOP;
	return (code);
}

void		cohen_suth_calcresult(t_outcode *p, t_pixel a, t_pixel b)
{
	if (p->output & TOP)
	{
		p->result.x = a.x + (b.x - a.x) * (WINDOW_H - a.y) / (b.y - a.y);
		p->result.y = WINDOW_H;
	}
	else if (p->output & BOTTOM)
	{
		p->result.x = a.x + (b.x - a.x) * (0 - a.y) / (b.y - a.y);
		p->result.y = 0;
	}
	else if (p->output & RIGHT)
	{
		p->result.y = a.y + (b.y - a.y) * (WINDOW_W - a.x) / (b.x - a.x);
		p->result.x = WINDOW_W;
	}
	else if (p->output & LEFT)
	{
		p->result.y = a.y + (b.y - a.y) * (0 - a.x) / (b.x - a.x);
		p->result.x = 0;
	}
}

int			cohen_suth_clip(t_outcode *param)
{
	while (1)
	{
		if (!(param->c0 | param->c1))
			return (1);
		else if (param->c0 & param->c1)
			return (0);
		else
		{
			param->output = param->c0 ? param->c0 : param->c1;
			cohen_suth_calcresult(param, param->p1, param->p2);
			if (param->output == param->c0)
			{
				param->p1.x = param->result.x;
				param->p1.y = param->result.y;
				param->c0 = get_outcode(param->p1.x, param->p1.y);
				continue;
			}
			param->p2.x = param->result.x;
			param->p2.y = param->result.y;
			param->c1 = get_outcode(param->p2.x, param->p2.y);
		}
	}
}

t_outcode	cohen_suth(int x0, int y0, int x1, int y1)
{
	t_outcode	param;

	param.p1.x = x0;
	param.p1.y = y0;
	param.p2.x = x1;
	param.p2.y = y1;
	param.c0 = get_outcode(param.p1.x, param.p1.y);
	param.c1 = get_outcode(param.p2.x, param.p2.y);
	param.clipped = cohen_suth_clip(&param);
	return (param);
}
