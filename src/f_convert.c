/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 13:56:04 by tlesven           #+#    #+#             */
/*   Updated: 2019/02/19 11:10:42 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static unsigned long long		round_to_d(unsigned long long n, int pre)
{
	if (pre <= 0 || ((n % 10) < 5))
		return (n);
	return (n + 1);
}

static unsigned long long		power(int n, int exp)
{
	unsigned long long result;

	if (exp == 0)
		return (1);
	result = n;
	while (--exp)
		result *= n;
	return (result);
}

//void							add_symb(char **s, int neg)
void							add_symb(char **s)
{
	int		len;
	char	*newstr;

	len = ft_strlen(*s);
/*	if (neg)
		*s[0] = '-';*/
	if (*(*s + (len - 1)) == '.')
	{
		newstr = ft_strndup(*s, len - 1);
		ft_strdel(s);
		*s = newstr;
	}
}

char							*f_convert(long double n, int pre)
{
	int					len;
	char				*str;
	unsigned long long	d;
	int					neg;

	neg = n < 0 ? 1 : 0;
	n = n < 0 ? -n : n;
	pre = pre == -1 ? 6 : pre;
	d = round_to_d(n * power(10, pre), pre);
	//len = count_n(d) + neg + 1;
	len = count_n(d) + 1;
	if (!(str = ft_strnew(len)))
		return (NULL);
	pre = len - pre - 1;
	while (len--)
	{
		if (len == pre)
		{
			str[len] = '.';
			--len;
		}
		str[len] = (d % 10) + 48;
		d /= 10;
	}
	//add_symb(&str, neg);
	add_symb(&str);
	return (str);
}
