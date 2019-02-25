/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 14:38:35 by tlesven           #+#    #+#             */
/*   Updated: 2018/11/19 20:07:34 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			nb_char(int n)
{
	int		i;
	int		div;

	if (n < 0)
		n *= -1;
	i = 1;
	div = 10;
	while (div <= n && i < 10)
	{
		div *= 10;
		i++;
	}
	return (i);
}

static char			*neg(int n)
{
	char	*s;
	int		i;

	i = nb_char(n) + 1;
	s = ft_strnew(i);
	if (!s)
		return (NULL);
	n *= -1;
	s[i] = '\0';
	while (i--)
	{
		s[i] = (n % 10) + 48;
		n /= 10;
	}
	s[0] = '-';
	return (s);
}

static char			*pos(int n)
{
	char	*s;
	int		i;

	i = nb_char(n);
	s = ft_strnew(i);
	if (!s)
		return (NULL);
	s[i] = '\0';
	while (i--)
	{
		s[i] = (n % 10) + 48;
		n /= 10;
	}
	return (s);
}

char				*ft_itoa(int n)
{
	char	*min_value;

	if (n == -2147483648)
	{
		min_value = ft_strnew(ft_strlen("-2147483648"));
		ft_strcpy(min_value, "-2147483648");
		return (min_value);
	}
	if (n < 0)
		return (neg(n));
	return (pos(n));
}
