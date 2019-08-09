/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 19:48:22 by byoung-w          #+#    #+#             */
/*   Updated: 2015/01/31 16:23:11 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			reached_end_while_parsing(t_format *format)
{
	if (!DEBUG_MODE)
		return (1);
	if (*(format->string - 1) == '%')
		ft_putstr_fd("ft_printf: spurious trailing '%' in format\n", 2);
	else
		ft_putstr_fd("ft_printf: conv lacks type at end of format\n", 2);
	print_format_error(format);
	return (1);
}

static int			invalid_specifier(char c, t_format *format)
{
	if (!DEBUG_MODE)
		return (1);
	ft_putstr_fd("ft_printf: unknown conv type character '", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("' in format\n", 2);
	print_format_error(format);
	return (1);
}

static int			mixed_masquerading_and_length(t_length length, char c
													, t_format *format)
{
	if (!DEBUG_MODE)
		return (1);
	ft_putstr_fd("ft_printf: use of '", 2);
	if (length == HH || length == LL)
		ft_putstrn_fd(get_current(format) - 2, 2, 2);
	else
		ft_putstrn_fd(get_current(format) - 1, 1, 2);
	ft_putstr_fd("' length modifier with '", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("' type character\n", 2);
	print_format_error(format);
	return (1);
}

static t_specifier	get_specifier(char c)
{
	if (c == 'd' || c == 'i' || c == 'D')
		return (S_DECIMAL);
	if (c == 'u' || c == 'U')
		return (U_DECIMAL);
	if (c == 'o' || c == 'O')
		return (OCTAL);
	if (c == 'x')
		return (HEX_LOWER);
	if (c == 'X')
		return (HEX_UPPER);
	if (c == 'c' || c == 'C')
		return (CHAR);
	if (c == 's' || c == 'S')
		return (STRING);
	if (c == 'p')
		return (POINTER);
	return (INVALID_SPECIFIER);
}

int					parse_specifier(t_conv *conv
									, t_format *format)
{
	char			current;

	if (!((current = *get_current(format))))
		return (reached_end_while_parsing(format));
	conv->specifier = get_specifier(current);
	if (conv->specifier == INVALID_SPECIFIER)
		return (invalid_specifier(current, format));
	if (current == 'D' || current == 'U' || current == 'O'
		|| current == 'C' || current == 'S')
	{
		if (conv->length != DEFAULT_LENGTH)
			mixed_masquerading_and_length(conv->length
											, current, format);
		conv->length = L;
	}
	format->location++;
	return (0);
}
