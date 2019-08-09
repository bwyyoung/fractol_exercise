/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_octal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 20:05:01 by byoung-w          #+#    #+#             */
/*   Updated: 2015/01/31 15:44:36 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*get_string_octal(t_conv *conv
										, va_list args)
{
	char			*string;
	char			*final;
	uintmax_t		value;

	value = get_unsigned_number_argument(conv->length, args);
	if (!value && conv->precision_set)
		string = ft_strdup("");
	else
		string = ft_basetoa(value, 8);
	add_precision_padding(conv, &string);
	if (conv->flags.hashtag && string[0] != '0')
	{
		final = ft_strjoin("0", string);
		free(string);
	}
	else
		final = string;
	return (final);
}
