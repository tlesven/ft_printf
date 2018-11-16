/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 16:31:54 by tlesven           #+#    #+#             */
/*   Updated: 2013/12/19 05:14:24 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

void	ft_arg_s(va_list ap, unsigned int i[2])
{
	char	*tmp;

	tmp = va_arg(ap, char *);
	if (tmp == NULL)
	{
		ft_putstr("(null)");
		i[1] += 6;
	}
	else
	{
		ft_putstr(tmp);
		i[1] += ft_strlen(tmp);
	}
	i[0] += 2;
}

void	ft_arg_c(va_list ap, unsigned int i[2])
{
	ft_putchar(va_arg(ap, int));
	i[1]++;
	i[0] += 2;
}

void	ft_arg_di(va_list ap, unsigned int i[2])
{
	char	*tmp;

	tmp = ft_itoa(va_arg(ap, int));
	ft_putstr(tmp);
	i[1] += ft_strlen(tmp);
	i[0] += 2;
}

void	ft_arg_p(va_list ap, unsigned int i[2])
{
	ft_putstr("0x");
	i[1] += 2;
	ft_arg_x(ap, i);
}
