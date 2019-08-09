/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 20:12:16 by byoung-w          #+#    #+#             */
/*   Updated: 2015/01/31 15:26:13 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*get_string_hex(t_conv *conv
										, va_list args)
{
	char			*string;
	char			*final;
	uintmax_t		value;
	t_bool			is_zero_value;

	value = get_unsigned_number_argument(conv->length, args);
	if (!value && conv->precision_set)
		string = ft_strdup("");
	else
		string = ft_basetoa(value, 16);
	if (conv->specifier == HEX_LOWER)
		ft_strtolower(string);
	is_zero_value = string[0] == '0' || string[0] == '\0';
	add_precision_padding(conv, &string);
	if ((conv->flags.hashtag && !is_zero_value)
		&& !(conv->precision_set && conv->precision == 0))
	{
		final = ft_strjoin(conv->specifier == HEX_LOWER ? "0x" : "0X"
							, string);
		free(string);
	}
	else
		final = string;
	return (final);
}
