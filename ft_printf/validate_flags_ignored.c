/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_flags_ignored.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 20:54:31 by byoung-w          #+#    #+#             */
/*   Updated: 2015/01/28 21:00:59 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				begin_blank_show_sign(t_conv *conv
											, t_format *format)
{
	if (conv->flags.positive_values_begin_blank
		&& conv->flags.show_sign)
	{
		if (DEBUG_MODE)
		{
			ft_putendl_fd("flag ' ' is ignored when flag '+' is present", 2);
			print_format_error(format);
		}
		conv->flags.positive_values_begin_blank = 0;
	}
}

void				pad_zeros_general(t_conv *conv
											, t_format *format)
{
	if (conv->flags.pad_with_zeros)
	{
		if (conv->flags.left_justify)
		{
			if (DEBUG_MODE)
			{
				ft_putendl_fd("flag'0' is ignored when flag '-' is present", 2);
				print_format_error(format);
			}
			conv->flags.pad_with_zeros = 0;
		}
		else if (conv->precision_set)
		{
			if (DEBUG_MODE)
			{
				ft_putstr_fd("flag '0' is ignored with precision and %", 2);
				ft_putchar_fd(*get_current(format), 2);
				ft_putchar_fd('\n', 2);
				print_format_error(format);
			}
			conv->flags.pad_with_zeros = 0;
			if (*get_current(format) == 'S')
				conv->flags.pad_with_zeros = 1;
		}
	}
}

void				validate_flags_ignored(t_conv *conv
											, t_format *format)
{
	begin_blank_show_sign(conv, format);
	pad_zeros_general(conv, format);
}
