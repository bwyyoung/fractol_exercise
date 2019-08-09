/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 15:32:52 by byoung-w          #+#    #+#             */
/*   Updated: 2015/05/01 04:44:14 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putendl_exit(char const *s)
{
	ft_putendl(s);
	exit(1);
}

int		verify_argument(char *argument)
{
	if (ft_strcmp(argument, FRACTOL_TYPE_JULIA) == 0)
		return (1);
	if (ft_strcmp(argument, FRACTOL_TYPE_MANDEL) == 0)
		return (1);
	if (ft_strcmp(argument, FRACTOL_TYPE_KOCH) == 0)
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_window	data;

	ft_printf("%s --> Julia Fractal\n", FRACTOL_TYPE_JULIA);
	ft_printf("%s --> Mandelbrot Fractal\n", FRACTOL_TYPE_MANDEL);
	ft_printf("%s --> Koch Fractal\n", FRACTOL_TYPE_KOCH);
	if (argc - 1 == 1 && verify_argument(argv[1]))
	{
		data.title = WIN_NAME;
		data.fractol_type = argv[1];
		data.def_width = 0;
		fractol(data);
	}
	else
	{
		ft_putendl("ERROR: Program must have 1 argument: Fractol Type");
	}
	return (0);
}
