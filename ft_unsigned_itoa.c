/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 00:14:36 by tlesven           #+#    #+#             */
/*   Updated: 2013/12/22 16:36:11 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

static int		ft_check_length(unsigned int n)
{
	unsigned int	len;

	len = 1;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char		*ft_unsigned_itoa(unsigned int n)
{
	char			*str;
	unsigned int	len;
	unsigned int	neg;

	len = ft_check_length(n);
	if ((str = (char *)malloc(sizeof(*str) * (len + 1))) == NULL)
		return (NULL);
	neg = 0;
	str[len] = '\0';
	while (len > neg)
	{
		str[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (str);
}

void			ft_arg_u(va_list ap, unsigned int i[2])
{
	char	*tmp;

	tmp = ft_unsigned_itoa(va_arg(ap, unsigned int));
	ft_putstr(tmp);
	i[1] += ft_strlen(tmp);
	i[0] += 2;
}
