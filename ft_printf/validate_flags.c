/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 18:13:50 by byoung-w          #+#    #+#             */
/*   Updated: 2015/01/31 15:28:46 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			show_positive_flags(t_conv *conv
											, t_format *format)
{
	if (conv->flags.positive_values_begin_blank
		|| conv->flags.show_sign)
	{
		if (conv->specifier != S_DECIMAL)
		{
			conv->flags.positive_values_begin_blank = 0;
			conv->flags.show_sign = 0;
			if (!DEBUG_MODE)
				return (OK);
			ft_putstr_fd("ft_printf: flag '", 2);
			ft_putchar_fd(conv->flags.show_sign ? '+' : ' ', 2);
			ft_putstr_fd("' results in undefined behavior with '", 2);
			ft_putchar_fd(*get_current(format), 2);
			ft_putendl_fd("' conv specifier", 2);
			print_format_error(format);
			return (OK);
		}
	}
	return (OK);
}

static int			zero_flag(t_conv *conv
									, t_format *format)
{
	if (conv->flags.pad_with_zeros)
	{
		if (conv->specifier == CHAR
			|| conv->specifier == STRING
			|| conv->specifier == POINTER)
		{
			if (!DEBUG_MODE)
				return (OK);
			ft_putstr_fd("ft_printf: flag '0' results in undefined ", 2);
			ft_putstr_fd("behaviour with '", 2);
			ft_putchar_fd(*get_current(format), 2);
			ft_putendl_fd("' conv specifier", 2);
			print_format_error(format);
			return (OK);
		}
	}
	return (OK);
}

static int			hashtag_flag(t_conv *conv
									, t_format *format)
{
	if (conv->flags.hashtag)
	{
		if (!(conv->specifier == HEX_LOWER
				|| conv->specifier == HEX_UPPER
				|| conv->specifier == OCTAL))
		{
			if (!DEBUG_MODE)
				return (OK);
			ft_putstr_fd("ft_printf: flag '#' results in undefined ", 2);
			ft_putstr_fd("behaviour with ' ", 2);
			ft_putchar_fd(*get_current(format), 2);
			ft_putendl_fd("' conv specifier", 2);
			print_format_error(format);
			return (OK);
		}
	}
	return (OK);
}

int					validate_flags(t_conv *conv
									, t_format *format)
{
	if (show_positive_flags(conv, format) == OK
		&& zero_flag(conv, format) == OK
		&& hashtag_flag(conv, format) == OK)
	{
		validate_flags_ignored(conv, format);
		return (OK);
	}
	return (ERR);
}
