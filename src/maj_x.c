/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maj_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:46:04 by tlesven           #+#    #+#             */
/*   Updated: 2019/01/28 12:26:31 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int			maj_x(t_list *l, va_list va_l)
{
	unsigned int		i;

	i = va_arg(va_l, unsigned int);
	((t_format*)l->content)->output = x_convert((unsigned long long)i, 1);
	return (0);
}

int			Xhh(t_list *l, va_list va_l)
{
	unsigned int		i;

	i = va_arg(va_l, unsigned int);
	((t_format*)l->content)->output = x_convert((unsigned long long)i, 1);
	return (0);
}

int			Xh(t_list *l, va_list va_l)
{
	unsigned int		i;

	i = va_arg(va_l, unsigned int);
	((t_format*)l->content)->output = x_convert((unsigned long long)i, 1);
	return (0);
}

int			Xl(t_list *l, va_list va_l)
{
	unsigned long		i;

	i = va_arg(va_l, unsigned long);
	((t_format*)l->content)->output = x_convert((unsigned long long)i, 1);
	return (0);
}

int			Xll(t_list *l, va_list va_l)
{
	unsigned long long		i;

	i = va_arg(va_l, unsigned long long);
	((t_format*)l->content)->output = x_convert(i, 1);
	return (0);
}
