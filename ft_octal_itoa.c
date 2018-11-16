/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 00:14:36 by tlesven           #+#    #+#             */
/*   Updated: 2013/12/18 21:04:09 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

static int		ft_check_length(unsigned long n)
{
	unsigned long		len;

	len = 1;
	while (n > 7)
	{
		n = n / 8;
		len++;
	}
	return (len);
}

static char		*ft_octal_itoa(unsigned long n)
{
	char	*str;
	unsigned long		len;
	unsigned long		neg;

	len = ft_check_length(n);
	if ((str = (char *)malloc(sizeof(*str) * (len + 1))) == NULL)
		return (NULL);
	neg = 0;
	str[len] = '\0';
	while (len > neg)
	{
		str[len - 1] = (n % 8) + 48;
		n = n / 8;
		len--;
	}
	return (str);
}

void			ft_arg_o(va_list ap, unsigned int i[2])
{
	char	*tmp;

	tmp = ft_octal_itoa(va_arg(ap, unsigned long));
	ft_putstr(tmp);
	i[1] += ft_strlen(tmp);
	i[0] += 2;
}
