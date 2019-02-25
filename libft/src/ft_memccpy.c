/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:48:13 by tlesven           #+#    #+#             */
/*   Updated: 2018/11/19 13:37:55 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned int		i;
	unsigned char		*sub1;
	const unsigned char	*sub2;
	unsigned char		uc;

	i = 0;
	sub1 = s1;
	sub2 = s2;
	uc = c;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		sub1[i] = sub2[i];
		if (sub2[i] == uc)
			return (s1 + i + 1);
		i++;
	}
	return (NULL);
}
