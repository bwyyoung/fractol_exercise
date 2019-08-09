/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 16:38:36 by byoung-w          #+#    #+#             */
/*   Updated: 2015/01/31 15:37:34 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					parse_conv(t_conv *conv
										, va_list args
										, t_format *format)
{
	if (parse_flags(conv, format) == OK
		&& parse_width(conv, args, format) == OK
		&& parse_precision(conv, args, format) == OK
		&& parse_length(conv, format) == OK
		&& parse_specifier(conv, format) == OK)
		return (OK);
	return (ERR);
}
