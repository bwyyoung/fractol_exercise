/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_precision_padding.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 21:11:26 by byoung-w          #+#    #+#             */
/*   Updated: 2015/01/31 14:59:37 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			precision_padding_decimal(t_conv *conv
												, char **string)
{
	intmax_t		length;
	intmax_t		needed;
	char			*new;
	int				offset;

	length = ft_strlen(*string);
	offset = ft_isdigit(**string) ? 0 : 1;
	needed = (conv->flags.pad_with_zeros ?
				conv->width : conv->precision + offset) - length;
	if (needed > 0)
	{
		new = ft_strnew(length + needed + offset);
		if (offset)
			new[0] = **string;
		ft_memset(new + offset, '0', needed);
		ft_strcpy(new + needed + offset, *string + offset);
		free(*string);
		*string = new;
	}
}

static void			precision_padding_regular(t_conv *conv
												, char **string)
{
	char			*new;
	intmax_t		needed;
	intmax_t		length;

	length = ft_strlen(*string);
	needed = (conv->flags.pad_with_zeros ?
				conv->width : conv->precision) - length;
	if (needed > 0)
	{
		new = ft_strnew(length + needed);
		ft_memset(new, '0', needed);
		ft_strcpy(new + needed, *string);
		free(*string);
		*string = new;
	}
}

void				add_precision_padding(t_conv *conv
											, char **string)
{
	if (conv->specifier == S_DECIMAL
			|| conv->specifier == U_DECIMAL)
		precision_padding_decimal(conv, string);
	else
		precision_padding_regular(conv, string);
}
