/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 21:50:50 by byoung-w          #+#    #+#             */
/*   Updated: 2014/12/28 21:51:34 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_putcharn_fd(char c, size_t number, int file_descriptor)
{
	size_t			i;

	i = 0;
	while (i < number)
	{
		ft_putchar_fd(c, file_descriptor);
		i++;
	}
}

static void			print_literal(char c, int fd)
{
	if (c == '\n')
		ft_putstr_fd("\\n", fd);
	else if (c == '\t')
		ft_putstr_fd("\\t", fd);
	else
		ft_putchar_fd(c, fd);
}

void				ft_putstr_literal_fd(char const *source
											, int file_descriptor)
{
	while (*source)
	{
		print_literal(*source, file_descriptor);
		source++;
	}
}

void				ft_putcharn(char c, size_t number)
{
	ft_putcharn_fd(c, number, 1);
}

void				ft_putstrn_fd(char const *source, size_t max_length
								, int file_descriptor)
{
	size_t		length;

	length = ft_strlen(source);
	if (max_length < length)
		length = max_length;
	write(file_descriptor, source, length);
}
