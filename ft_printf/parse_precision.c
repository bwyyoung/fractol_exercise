/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 19:15:59 by byoung-w          #+#    #+#             */
/*   Updated: 2015/02/03 15:30:57 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			precision_too_long(t_conv *conv
											, t_format *format)
{
	if (!DEBUG_MODE)
		return (ERR);
	ft_putstr_fd("ft_printf: suspicious precision given by * argument: ", 2);
	ft_putnbr_large_fd(conv->precision, 2);
	ft_putstr_fd("\n", 2);
	print_format_error(format);
	return (ERR);
}

static size_t		from_star(t_conv *conv, va_list args)
{
	conv->precision = va_arg(args, unsigned int);
	conv->precision_set = 1;
	return (1);
}

static size_t		written_numbers(t_conv *conv, t_format *format)
{
	size_t			i;
	char			current;

	if (*get_current(format) == '-')
		i = 1;
	else
		i = 0;
	while (((current = *(get_current(format) + i)))
			&& ft_isdigit(current))
	{
		ft_atoi_add_digit_u(current, &conv->precision);
		i++;
	}
	if (*get_current(format) == '-' && conv->precision == 0)
		return (0);
	else
	{
		conv->precision_set = 1;
		return (i);
	}
}

int					parse_precision(t_conv *conv
									, va_list args, t_format *format)
{
	size_t			length;

	if (*get_current(format) == '.')
	{
		format->location++;
		if (*get_current(format) == '*')
			length = from_star(conv, args);
		else
			length = written_numbers(conv, format);
		if (conv->precision > LARGEST_STAR_ARGUMENT)
		{
			precision_too_long(conv, format);
			conv->precision = 0;
		}
		format->location += length;
	}
	return (OK);
}
