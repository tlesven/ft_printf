/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:49:26 by tlesven           #+#    #+#             */
/*   Updated: 2019/02/19 11:21:13 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int			f(t_list *l, va_list va_l)
{
	double		i;
	t_format	*f;

	f = (t_format*)l->content;
	i = va_arg(va_l, double);
	if (i < 0.0)
		f->neg = 1;
	f->output = f_convert((long double)i, f->precision);
	return (0);
}

int			fL(t_list *l, va_list va_l)
{
	long double		i;
	t_format		*f;

	f = (t_format*)l->content;
	i = va_arg(va_l, long double);
	if (i < 0.0)
		f->neg = 1;
	f->output = f_convert(i, f->precision);
	return (0);
}
