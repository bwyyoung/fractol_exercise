/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 17:37:52 by byoung-w          #+#    #+#             */
/*   Updated: 2015/01/31 16:10:45 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			width_too_long(t_conv *conv, t_format *format)
{
	if (!DEBUG_MODE)
		return (ERR);
	ft_putstr_fd("ft_printf: suspicious width given by * argument: ", 2);
	ft_putnbr_large_fd(conv->width, 2);
	ft_putstr_fd("\n", 2);
	print_format_error(format);
	return (ERR);
}

int					parse_width(t_conv *conv
								, va_list args, t_format *format)
{
	size_t			i;
	char			current;

	if (*get_current(format) == '*')
	{
		conv->width = va_arg(args, unsigned int);
		if (conv->width > LARGEST_STAR_ARGUMENT)
		{
			width_too_long(conv, format);
			conv->width = 0;
		}
		format->location++;
	}
	else
	{
		i = 0;
		while (((current = *(get_current(format) + i)))
				&& ft_isdigit(current))
		{
			ft_atoi_add_digit_u(current, &conv->width);
			i++;
		}
		format->location += i;
	}
	return (OK);
}
