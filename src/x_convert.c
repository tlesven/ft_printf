/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:27:49 by tlesven           #+#    #+#             */
/*   Updated: 2019/02/07 17:12:06 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_char(unsigned long long ll)
{
	int		i;

	i = 0;
	while (ll > 0)
	{
		ll /= 16;
		i++;
	}
	return (i);
}

static char	hex_value(int ret, int maj)
{
	if (ret == 10)
		return (maj == 1 ? 'A' : 'a');
	else if (ret == 11)
		return (maj == 1 ? 'B' : 'b');
	else if (ret == 12)
		return (maj == 1 ? 'C' : 'c');
	else if (ret == 13)
		return (maj == 1 ? 'D' : 'd');
	else if (ret == 14)
		return (maj == 1 ? 'E' : 'e');
	else
		return (maj == 1 ? 'F' : 'f');
}

char		*x_convert(unsigned long long n, int maj)
{
	char	*s;
	int		len;
	int		ret;

	if (n == 0)
		return (ft_strdup("0"));
	len = count_char(n);
	if (!(s = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		ret = ((n) % 16);
		if (ret <= 9)
			s[len] = ret + 48;
		else
			s[len] = hex_value(ret, maj);
		n /= 16;
	}
	return (s);
}
