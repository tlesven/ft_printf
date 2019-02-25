/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 19:03:26 by tlesven           #+#    #+#             */
/*   Updated: 2015/03/24 20:01:18 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*l;
	t_list		*startlst;
	t_list		*newlst;

	l = lst;
	startlst = f(l);
	newlst = startlst;
	while (l)
	{
		if (l->next)
		{
			newlst->next = f(l->next);
			newlst = newlst->next;
		}
		else
			newlst->next = NULL;
		l = l->next;
	}
	return (startlst);
}
