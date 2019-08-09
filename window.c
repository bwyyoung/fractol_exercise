/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 15:37:13 by byoung-w          #+#    #+#             */
/*   Updated: 2015/04/29 20:13:08 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			set_image(t_window *data)
{
	t_image		image;

	image.mlx_img = mlx_new_image((data)->mlx_ptr, WINDOW_W, WINDOW_H);
	image.mlx_img_data = mlx_get_data_addr(image.mlx_img, &(image.bpp),
										&(image.size_line), &(image.endian));
	if (!image.mlx_img || !image.mlx_img_data)
		ft_error("Image failed to initialise.");
	(data)->img = image;
	init_fractals(data);
}

void				init_fractals(t_window *data)
{
	REF_F.freeze = 0;
	REF_F.crosshair = 1;
	REF_F.negative = 0;
	if (ft_strcmp(data->fractol_type, FRACTOL_TYPE_JULIA) == 0)
		init_julia(data);
	if (ft_strcmp(data->fractol_type, FRACTOL_TYPE_MANDEL) == 0)
		init_mandelbrot(data);
	if (ft_strcmp(data->fractol_type, FRACTOL_TYPE_KOCH) == 0)
		init_koch(data);
}

static int			setup_environment(t_window *data)
{
	if (((data)->mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if (((data)->mlx_win = mlx_new_window((data)->mlx_ptr, WINDOW_W, WINDOW_H,
										(data)->title)) == NULL)
		return (EXIT_FAILURE);
	set_image(data);
	render(data);
	return (EXIT_SUCCESS);
}

int					expose_hook(t_window *data)
{
	(void)data;
	return (0);
}

void				fractol(t_window data)
{
	setup_environment(&data);
	mlx_expose_hook((data).mlx_win, expose_hook, &data);
	mlx_key_hook((data).mlx_win, key_hook, &data);
	mlx_mouse_hook((data).mlx_win, mouse_hook, &data);
	mlx_hook((data).mlx_win, 6, 1, mouse_move_hook, &data);
	mlx_loop((data).mlx_ptr);
}
