/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 21:00:03 by byoung-w          #+#    #+#             */
/*   Updated: 2015/01/27 14:04:36 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			check_percent_percent(t_format *fmt)
{
	if (*get_current(fmt) == '%')
	{
		ft_putchar('%');
		fmt->location++;
		fmt->written++;
		return (1);
	}
	else
		return (0);
}

int					numdigits(int n)
{
	if (n < 0)
		return (numdigits((n == INT_MIN) ? INT_MAX : -n));
	if (n < 10)
		return (1);
	return (1 + numdigits(n / 10));
}

int					handle_err(t_conv *conv, t_format *fmt)
{
	if (conv->width > 0 && conv->specifier == INVALID_SPECIFIER)
		add_invalid_padding(conv, fmt);
	return (1);
}

static int			handle_conv(t_format *fmt, va_list args)
{
	t_conv	conv;

	if (check_percent_percent(fmt))
		return (1);
	ft_bzero(&conv, sizeof(conv));
	if (parse_conv(&conv, args, fmt) == OK
		&& validate_conv(&conv, fmt) == OK)
		print_conv(&conv, args, fmt);
	else if (*get_current(fmt) == '%')
	{
		if (conv.precision_set)
			handle_err(&conv, fmt);
		ft_putchar('%');
		fmt->location++;
		fmt->written++;
	}
	else
		return (handle_err(&conv, fmt));
	return (1);
}

void				handle_format(t_format *fmt, va_list args)
{
	char			current;

	while ((current = *get_current(fmt)))
	{
		if (current == '%')
		{
			fmt->location++;
			if (!handle_conv(fmt, args))
				break ;
		}
		else
		{
			ft_putchar(current);
			fmt->written++;
			fmt->location++;
		}
	}
}
