/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 19:49:28 by byoung-w          #+#    #+#             */
/*   Updated: 2015/01/31 15:44:46 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			add_precision(t_conv *conv, char **string)
{
	char			*new;

	if (ft_strlen(*string) > conv->precision && conv->precision_set)
	{
		new = ft_strnew(conv->precision);
		ft_strncpy(new, *string, conv->precision);
		free(*string);
		*string = new;
	}
}

char				*get_string_string(t_conv *conv
										, va_list args)
{
	char			*string;

	if (!(string = va_arg(args, char*)))
	{
		if (conv->precision_set)
		{
			string = (char *)malloc(sizeof(char) * 1);
			string[0] = '\0';
			conv->flags.pad_with_zeros = 1;
			add_final_padding(conv, &string);
			return (string);
		}
		return (ft_strdup("(null)"));
	}
	string = ft_strdup(string);
	add_precision(conv, &string);
	return (string);
}
