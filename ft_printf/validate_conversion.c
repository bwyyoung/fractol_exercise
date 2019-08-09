/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 16:58:37 by byoung-w          #+#    #+#             */
/*   Updated: 2015/01/31 15:29:00 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			put_length_string(t_length length)
{
	if (length == HH)
		ft_putstr_fd("hh", 2);
	else if (length == H)
		ft_putstr_fd("hh", 2);
	else if (length == L)
		ft_putstr_fd("l", 2);
	else if (length == LL)
		ft_putstr_fd("ll", 2);
	else if (length == J)
		ft_putstr_fd("j", 2);
	else if (length == Z)
		ft_putstr_fd("z", 2);
	else
		ft_putstr_fd("default", 2);
}

static int			pointer_has_specified_size(t_conv *conv
												, t_format *format)
{
	if (conv->specifier == POINTER
		&& conv->length != DEFAULT_LENGTH)
	{
		if (!DEBUG_MODE)
			return (OK);
		ft_putstr_fd("ft_printf: length modifier '", 2);
		put_length_string(conv->length);
		ft_putstr_fd("' results in undefined behavior or no effect ", 2);
		ft_putendl_fd("with 'p' conv specifier", 2);
		print_format_error(format);
		return (OK);
	}
	return (OK);
}

static int			precision_settable(t_conv *conv
										, t_format *format)
{
	char			specifier;

	if (conv->precision_set
		&& ((conv->specifier == CHAR && conv->length >= L)
				|| conv->specifier == POINTER))
	{
		specifier = *get_current(format);
		if (DEBUG_MODE)
		{
			ft_putstr_fd("ft_printf: precision used with %", 2);
			ft_putchar_fd(specifier, 2);
			if (specifier == 'c')
			{
				ft_putstr_fd(" and length modifier '", 2);
				put_length_string(conv->length);
				ft_putstr_fd("'", 2);
			}
			ft_putchar_fd('\n', 2);
		}
		if (specifier == 'C' && !conv->precision)
			format->written++;
		print_format_error(format);
		return (OK);
	}
	return (OK);
}

static int			is_it_okay(t_conv *conv
										, t_format *format)
{
	if (pointer_has_specified_size(conv, format) == OK
		&& validate_flags(conv, format) == OK
		&& precision_settable(conv, format) == OK)
		return (OK);
	return (ERR);
}

int					validate_conv(t_conv *conv
										, t_format *format)
{
	int				returned;

	format->location--;
	returned = is_it_okay(conv, format);
	format->location++;
	return (returned);
}
