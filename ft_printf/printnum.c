/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 09:50:50 by byoung-w          #+#    #+#             */
/*   Updated: 2014/11/06 22:47:08 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			write_digits(char *current, uintmax_t number)
{
	while (number)
	{
		*current = number % 10 + '0';
		number /= 10;
		current--;
	}
}

void				ft_itoa_write(char *last_digit, uintmax_t number)
{
	if (number == 0)
		*last_digit = '0';
	else
		write_digits(last_digit, number);
}
