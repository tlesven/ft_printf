/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:05:55 by tlesven           #+#    #+#             */
/*   Updated: 2015/03/31 17:19:29 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;

	if (ft_strlen(dst) >= size)
	{
		i = size + ft_strlen(src);
		return (i);
	}
	else
		i = ft_strlen(dst) + ft_strlen(src);
	if (i >= size)
	{
		ft_strncat(dst, src, (size - ft_strlen(dst) - 1));
		return (i);
	}
	else
	{
		ft_strcat(dst, src);
		return (i);
	}
	return (i);
}
