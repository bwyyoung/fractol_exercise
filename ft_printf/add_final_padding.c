/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_final_padding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 19:09:46 by byoung-w          #+#    #+#             */
/*   Updated: 2015/01/28 18:04:19 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				get_filler_char(t_conv *conv)
{
	if (conv->flags.pad_with_zeros)
		return ('0');
	return (' ');
}

void				add_final_padding(t_conv *conv
										, char **string)
{
	char			*new;
	char			*padding;
	intmax_t		needed;

	needed = conv->width - ft_strlen(*string);
	if (needed > 0)
	{
		padding = ft_strnew(needed);
		ft_memset(padding, get_filler_char(conv), needed);
		if ((conv->flags.pad_with_zeros && conv->specifier == POINTER)
			|| conv->flags.left_justify)
			new = ft_strjoin(*string, padding);
		else
			new = ft_strjoin(padding, *string);
		free(*string);
		free(padding);
		*string = new;
	}
}

void				add_invalid_padding(t_conv *conv, t_format *fmt)
{
	char			*string;

	string = (char *)malloc(sizeof(char) * 1);
	conv->width -= 1;
	string[0] = '\0';
	if (conv->flags.left_justify && conv->specifier == INVALID_SPECIFIER)
	{
		ft_putchar(*get_current(fmt));
		fmt->location++;
		fmt->written++;
	}
	add_final_padding(conv, &string);
	ft_putstr(string);
	fmt->written += ft_strlen(string);
	free(string);
}
