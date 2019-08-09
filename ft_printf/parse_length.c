/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 19:23:16 by byoung-w          #+#    #+#             */
/*   Updated: 2015/01/31 15:36:45 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_length		get_length(char current, char next)
{
	if (current == 'h')
		return (next == 'h' ? HH : H);
	if (current == 'l')
		return (next == 'l' ? LL : L);
	if (current == 'j')
		return (J);
	if (current == 'z')
		return (Z);
	return (DEFAULT_LENGTH);
}

int					parse_length(t_conv *conv, t_format *format)
{
	char			current;
	char			next;

	if (!((current = *get_current(format)))
			|| !((next = *(get_current(format) + 1))))
		return (OK);
	conv->length = get_length(current, next);
	if (conv->length != DEFAULT_LENGTH)
		format->location++;
	if (conv->length == HH || conv->length == LL)
		format->location++;
	return (OK);
}
