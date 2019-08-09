/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 19:01:58 by byoung-w          #+#    #+#             */
/*   Updated: 2015/01/27 19:20:15 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			print_char_and_padding(t_conv *conv
											, char argument, char *string
											, t_format *format)
{
	if (argument)
		ft_putstr(string);
	else
	{
		if (conv->flags.left_justify)
			ft_putchar('\0');
		ft_putstr(string);
		if (!conv->flags.left_justify)
			ft_putchar('\0');
		format->written++;
	}
	format->written += ft_strlen(string);
}

void				print_char(t_conv *conv, char argument
								, t_format *format)
{
	char			*string;

	string = ft_strnew(1);
	string[0] = argument;
	if (!argument && conv->width)
		conv->width--;
	add_final_padding(conv, &string);
	print_char_and_padding(conv, argument, string, format);
}
