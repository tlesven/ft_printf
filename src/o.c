/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:09:21 by tlesven           #+#    #+#             */
/*   Updated: 2019/02/24 17:48:32 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int			o(t_list *l, va_list va_l)
{
	unsigned int		i;

	i = va_arg(va_l, unsigned int);
	((t_format*)l->content)->output = o_convert((unsigned long long)i);
	return (0);
}

int			ohh(t_list *l, va_list va_l)
{
	unsigned char		i;

	i = (unsigned char)va_arg(va_l, unsigned int);
	((t_format*)l->content)->output = o_convert((unsigned long long)i);
	return (0);
}

int			oh(t_list *l, va_list va_l)
{
	unsigned short		i;

	i = (unsigned short)va_arg(va_l, unsigned int);
	((t_format*)l->content)->output = o_convert((unsigned long long)i);
	return (0);
}

int			ol(t_list *l, va_list va_l)
{
	unsigned long		i;

	i = va_arg(va_l, unsigned long);
	((t_format*)l->content)->output = o_convert((unsigned long long)i);
	return (0);
}

int			oll(t_list *l, va_list va_l)
{
	unsigned long long		i;

	i = va_arg(va_l, unsigned long long);
	((t_format*)l->content)->output = o_convert(i);
	return (0);
}
