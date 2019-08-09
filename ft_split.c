/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/05 13:18:31 by byoung-w          #+#    #+#             */
/*   Updated: 2013/10/05 13:24:22 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	ft_arrlen(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*r;
	unsigned int	i;

	i = 0;
	if (!s || !(r = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		r[i] = s[start + i];
		i++;
	}
	r[i] = '\0';
	return (r);
}

int		ft_isnot(int c)
{
	if (c != 10 && c != 32 && c != 9)
		return (1);
	return (0);
}

char	**ft_split(char *str)
{
	char			**tab;
	unsigned int	size;
	unsigned int	start;
	int				i;

	if (!str || !(tab = (char **)malloc(sizeof(char *) * (ft_strlen(str) + 1))))
		return (NULL);
	i = 0;
	size = 0;
	while (str[i])
	{
		if (ft_isnot(str[i]))
		{
			start = i;
			while (str[i] && ft_isnot(str[i]))
				i++;
			tab[size++] = ft_strsub(str, start, i - start);
		}
		else
			i++;
	}
	tab[size] = NULL;
	return (tab);
}
