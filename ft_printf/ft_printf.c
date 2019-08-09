/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 16:36:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/01/27 14:44:06 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf(const char *format_string, ...)
{
	va_list			args;
	t_format		format;

	if (!format_string)
	{
		ft_putendl_fd("ft_printf: format string must be valid", 2);
		exit(1);
	}
	ft_bzero(&format, sizeof(t_format));
	format.string = format_string;
	va_start(args, format_string);
	handle_format(&format, args);
	va_end(args);
	return (format.written);
}
