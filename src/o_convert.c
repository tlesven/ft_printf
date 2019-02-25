/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 10:27:08 by tlesven           #+#    #+#             */
/*   Updated: 2019/02/24 15:50:18 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_char(unsigned long long ll)
{
	int		i;

	i = 0;
	while (ll > 0)
	{
		ll /= 8;
		i++;
	}
	return (i);
}

char			*o_convert(unsigned long long n)
{
	char	*s;
	int		len;

	len = count_char(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (!(s = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		s[len] = ((n) % 8) + 48;
		n /= 8;
	}
	return (s);
}
