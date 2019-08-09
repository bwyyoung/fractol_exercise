/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unsigned_number_argument.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 15:39:01 by byoung-w          #+#    #+#             */
/*   Updated: 2015/01/31 15:45:51 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t		get_unsigned_number_argument(t_length length
												, va_list args)
{
	uintmax_t	value;

	if (length == L)
		return (va_arg(args, unsigned long));
	if (length == LL)
		return (va_arg(args, unsigned long long));
	if (length == J)
		return (va_arg(args, uintmax_t));
	if (length == Z)
		return (va_arg(args, size_t));
	value = va_arg(args, unsigned int);
	if (length == HH)
		value = (unsigned char)value;
	else if (length == H)
		value = (unsigned short)value;
	else if (length == DEFAULT_LENGTH)
		value = (unsigned int)value;
	return (value);
}
