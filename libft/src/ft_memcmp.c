/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:27:06 by tlesven           #+#    #+#             */
/*   Updated: 2018/11/19 20:05:13 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	const unsigned char	*sub1;
	const unsigned char	*sub2;

	sub1 = s1;
	sub2 = s2;
	i = 0;
	while (i < n)
	{
		if (sub1[i] != sub2[i])
			return (sub1[i] - sub2[i]);
		i++;
	}
	return (0);
}
