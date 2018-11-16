/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 00:14:36 by tlesven           #+#    #+#             */
/*   Updated: 2013/12/17 06:14:42 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

static int	ft_check_length(int n)
{
	int		len;

	len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_too_small(void)
{
	char	*tmp;

	if ((tmp = (char *)malloc(sizeof(*tmp) * 12)) == NULL)
		return (NULL);
	tmp[0] = '-';
	tmp[1] = '2';
	tmp[2] = '1';
	tmp[3] = '4';
	tmp[4] = '7';
	tmp[5] = '4';
	tmp[6] = '8';
	tmp[7] = '3';
	tmp[8] = '6';
	tmp[9] = '4';
	tmp[10] = '8';
	tmp[11] = '\0';
	return (tmp);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		neg;

	if (n == -2147483648)
		return (ft_too_small());
	len = ft_check_length(n);
	if ((str = (char *)malloc(sizeof(*str) * (len + 1))) == NULL)
		return (NULL);
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		str[0] = '-';
		n = -n;
	}
	str[len] = '\0';
	while (len > neg)
	{
		str[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (str);
}
