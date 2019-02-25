/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:02:11 by tlesven           #+#    #+#             */
/*   Updated: 2015/01/22 18:40:13 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*m;

	if (size == 0)
		return (NULL);
	else
		m = (void *)malloc(size);
	if (m == NULL)
		return (NULL);
	else
		ft_bzero(m, size);
	return (m);
}
