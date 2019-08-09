/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 19:58:29 by byoung-w          #+#    #+#             */
/*   Updated: 2015/04/29 20:13:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_sqrt_approx(int nb)
{
	unsigned int op;
	unsigned int res;
	unsigned int one;

	op = nb;
	res = 0;
	one = 1uL << 30;
	while (one > op)
		one >>= 2;
	while (one != 0)
	{
		if (op >= res + one)
		{
			op = op - (res + one);
			res = res + 2 * one;
		}
		res >>= 1;
		one >>= 2;
	}
	if (op > res)
		res++;
	return (res);
}

double		distance(t_coord a, t_coord b)
{
	double	x;
	double	y;
	double	square;

	x = (a.x - b.x);
	y = (a.y - b.y);
	square = ft_pow(x, 2) + ft_pow(y, 2);
	return (sqrt(ABS(square)));
}

int			vector_determinant(double x, double y, t_coord start, t_coord end)
{
	double	sign;

	sign = (end.x - start.x) * (y - start.y)
			- (end.y - start.y) * (x - start.x);
	return ((sign > 0) - (sign < 0));
}
