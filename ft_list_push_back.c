/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 10:38:25 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/10 10:38:37 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_list	*getendoflist(t_list *thelist)
{
	if (thelist->next == NULL)
	{
		return (thelist);
	}
	return (getendoflist(thelist->next));
}

void	ft_list_push_back(t_list **begin_list, void *data, int thesize)
{
	t_list		*mlist;

	mlist = ft_lstnew(data, thesize);
	if (*begin_list == NULL)
		*begin_list = mlist;
	else
		getendoflist(*begin_list)->next = mlist;
}
