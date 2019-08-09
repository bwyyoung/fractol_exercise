/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number_argument.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 18:14:24 by byoung-w          #+#    #+#             */
/*   Updated: 2015/01/31 15:25:30 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t		get_number_argument(t_length length, va_list args)
{
	intmax_t	value;

	if (length == L)
		return (va_arg(args, long));
	if (length == LL)
		return (va_arg(args, long long));
	if (length == J)
		return (va_arg(args, intmax_t));
	if (length == Z)
		return (va_arg(args, size_t));
	value = va_arg(args, int);
	if (length == HH)
		value = (char)value;
	else if (length == H)
		value = (short)value;
	else if (length == DEFAULT_LENGTH)
		value = (int)value;
	return (value);
}
