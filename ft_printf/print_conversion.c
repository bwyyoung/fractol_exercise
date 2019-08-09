/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 23:03:06 by byoung-w          #+#    #+#             */
/*   Updated: 2015/01/31 15:34:11 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			print_wide_string(t_conv *conv
										, wchar_t *string
										, size_t *written)
{
	if (string)
		print_wide_chars(conv, string, ft_strlen_wide(string), written);
	else
	{
		ft_putstr("(null)");
		*written += 6;
	}
}

static void			print_wide_char(t_conv *conv, wint_t wint
									, t_format *format)
{
	wchar_t	wchar;

	if (wint > 0x10FFFF)
	{
		ft_putstr_fd("ft_printf: invalid wide character encountered", 2);
		print_format_error(format);
	}
	else
	{
		wchar = (wchar_t)wint;
		print_wide_chars(conv, &wchar, 1, &format->written);
	}
}

void				print_conv(t_conv *conv, va_list args
										, t_format *format)
{
	if (conv->length >= L && conv->specifier == STRING)
	{
		print_wide_string(conv, va_arg(args, wchar_t*)
							, &format->written);
	}
	else if (conv->specifier == CHAR)
	{
		if (conv->precision_set)
			conv->flags.pad_with_zeros = 1;
		if (conv->length >= L)
			print_wide_char(conv, va_arg(args, wchar_t), format);
		else
			print_char(conv, (char)va_arg(args, int), format);
	}
	else
	{
		print_normal(conv, args, format);
	}
}
