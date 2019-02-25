/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:09:21 by tlesven           #+#    #+#             */
/*   Updated: 2019/02/24 17:45:53 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int			i(t_list *l, va_list va_l)
{
	int		i;

	i = va_arg(va_l, int);
	if (i < 0)
		((t_format*)l->content)->neg = 1;
	((t_format*)l->content)->output = d_convert((long long)i);
	return (0);
}

int			ihh(t_list *l, va_list va_l)
{
	char	i;

	i = (char)va_arg(va_l, int);
	if (i < 0)
		((t_format*)l->content)->neg = 1;
	((t_format*)l->content)->output = d_convert((long long)i);
	return (0);
}

int			ih(t_list *l, va_list va_l)
{
	short	i;

	i = (short)va_arg(va_l, int);
	if (i < 0)
		((t_format*)l->content)->neg = 1;
	((t_format*)l->content)->output = d_convert((long long)i);
	return (0);
}

int			il(t_list *l, va_list va_l)
{
	long		i;

	i = va_arg(va_l, long);
	if (i < 0)
		((t_format*)l->content)->neg = 1;
	((t_format*)l->content)->output = d_convert((long long)i);
	return (0);
}

int			ill(t_list *l, va_list va_l)
{
	long long		i;

	i = va_arg(va_l, long long);
	if (i < 0)
		((t_format*)l->content)->neg = 1;
	((t_format*)l->content)->output = d_convert(i);
	return (0);
}
