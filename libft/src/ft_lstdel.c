/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 16:42:10 by tlesven           #+#    #+#             */
/*   Updated: 2019/01/24 14:53:35 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*l;
	t_list	*lnext;

	l = *alst;
	while (l)
	{
		lnext = l->next;
		del(l->content, l->content_size);
		ft_memdel((void**)&l);
		l = lnext;
	}
	*alst = NULL;
	alst = NULL;
	return ;
}
