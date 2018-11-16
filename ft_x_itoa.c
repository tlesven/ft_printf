/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 00:14:36 by tlesven           #+#    #+#             */
/*   Updated: 2013/12/22 16:32:52 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

static int		ft_check_length(unsigned long n)
{
	unsigned long	len;

	len = 1;
	while (n > 15)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static char		ft_convert(int n)
{
	if (n <= 9)
		return (n + 48);
	if (n == 10)
		return ('a');
	if (n == 11)
		return ('b');
	if (n == 12)
		return ('c');
	if (n == 13)
		return ('d');
	if (n == 14)
		return ('e');
	if (n == 15)
		return ('f');
	return ('0');
}


static char		*ft_x_itoa(unsigned long n)
{
	char			*str;
	unsigned long	len;
	unsigned long	neg;

	len = ft_check_length(n);
	if ((str = (char *)malloc(sizeof(*str) * (len + 1))) == NULL)
		return (NULL);
	neg = 0;
	str[len] = '\0';
	while (len > neg)
	{
		str[len - 1] = ft_convert(n % 16);
		n = n / 16;
		len--;
	}
	return (str);
}

void		ft_arg_x(va_list ap, unsigned int i[2])
{
	char		*tmp;

	tmp = ft_x_itoa(va_arg(ap, unsigned long));
	ft_putstr(tmp);
	i[1] += ft_strlen(tmp);
	i[0] += 2;
}
