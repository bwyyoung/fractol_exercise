/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_decimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 11:13:39 by byoung-w          #+#    #+#             */
/*   Updated: 2015/01/31 15:44:26 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			add_prefix(t_conv *conv, char **string)
{
	char			*prefix;
	char			*new;

	if (ft_isdigit((*string)[0]))
	{
		prefix = NULL;
		if (conv->flags.positive_values_begin_blank)
			prefix = ft_strdup(" ");
		else if (conv->flags.show_sign)
			prefix = ft_strdup("+");
		if (prefix)
		{
			new = ft_strjoin(prefix, *string);
			free(prefix);
			free(*string);
			*string = new;
		}
	}
}

char				*get_string_decimal(t_conv *conv
										, va_list args)
{
	char			*string;
	intmax_t		value;
	uintmax_t		unsigned_value;

	if (conv->specifier == U_DECIMAL)
	{
		unsigned_value = get_unsigned_number_argument(conv->length
				, args);
	}
	else
	{
		value = get_number_argument(conv->length, args);
	}
	if ((conv->specifier == U_DECIMAL ? unsigned_value == 0 : value == 0)
		&& conv->precision_set && conv->precision == 0)
		string = ft_strdup("");
	else if (conv->specifier == S_DECIMAL)
		string = ft_itoa_large(value);
	else
		string = ft_itoa_ularge(unsigned_value);
	add_prefix(conv, &string);
	add_precision_padding(conv, &string);
	return (string);
}
