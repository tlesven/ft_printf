/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 16:38:27 by tlesven           #+#    #+#             */
/*   Updated: 2019/02/19 11:07:07 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_n(long long ll)
{
	int		i;

	i = 0;
	if (ll < 0)
		ll *= -1;
	while (ll > 0)
	{
		ll /= 10;
		i++;
	}
	return (i);
}

char	*d_convert(long long n)
{
	char	*s;
	int		len;
	char	neg;

	if (n == 0)
		return (ft_strdup("0"));
	neg = n < 0 ? 1 : 0;
	len = count_n(n);
	//if (neg)
	//	++len;
	if (!(s = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		if (neg)
			s[len] = ((n * -1) % 10) + 48;
		else
			s[len] = ((n) % 10) + 48;
		n /= 10;
	}
	//if (neg)
	//	s[0] = '-';
	return (s);
}
