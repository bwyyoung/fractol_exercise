/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 21:04:27 by byoung-w          #+#    #+#             */
/*   Updated: 2015/01/11 20:21:32 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_abs(int num)
{
	return (num < 0 ? -num : num);
}

void			ft_atoi_add_digit_u(const char c, unsigned int *number)
{
	if (*number)
		*number *= 10;
	*number += c - '0';
}

void			ft_atoi_add_digit_ularge(const char c, uintmax_t *number)
{
	if (*number)
		*number *= 10;
	*number += c - '0';
}

int				ft_count_digits_ularge(uintmax_t number)
{
	int	count;

	if (number == 0)
		return (1);
	count = 0;
	while (number > 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}

int				ft_count_digits(int number)
{
	int	count;

	if (number == 0)
		return (1);
	if (number == -2147483648)
		return (10);
	number = ft_abs(number);
	count = 0;
	while (number > 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}
