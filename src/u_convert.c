/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:14:11 by tlesven           #+#    #+#             */
/*   Updated: 2019/02/21 16:18:12 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_char(unsigned long long ll)
{
	int		i;

	i = 0;
	while (ll > 0)
	{
		ll /= 10;
		i++;
	}
	return (i);
}

char			*u_convert(unsigned long long n)
{
	char	*s;
	int		len;

	if (n == 0)
		return (ft_strdup("0"));
	len = count_char(n);
	if (!(s = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		s[len] = ((n) % 10) + 48;
		n /= 10;
	}
	return (s);
}
