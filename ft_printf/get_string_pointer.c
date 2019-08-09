/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 14:03:41 by byoung-w          #+#    #+#             */
/*   Updated: 2015/01/31 15:26:25 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*add_zero_padding(char *string, intmax_t precision)
{
	char			*new;
	char			*padding;
	intmax_t		needed;

	needed = precision;
	if (needed > 0)
	{
		padding = ft_strnew(needed);
		ft_memset(padding, '0', needed);
		new = ft_strjoin(string, padding);
		free(string);
		free(padding);
		string = new;
	}
	return (string);
}

char				*get_string_pointer(t_conv *conv
											, va_list args)
{
	char			*before;
	char			*string;
	long			value;

	value = (long)va_arg(args, void*);
	if (value == 0 && conv->precision_set)
		return (add_zero_padding(ft_strdup("0x"), conv->precision));
	else if (value == 0)
		return (ft_strdup("0x0"));
	before = ft_basetoa(value, 16);
	ft_strtolower(before);
	string = ft_strjoin(add_zero_padding(ft_strdup("0x"),
		conv->precision - ft_strlen(before)), before);
	free(before);
	(void)conv;
	(void)args;
	return (string);
}
