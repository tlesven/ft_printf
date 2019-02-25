/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:50:16 by tlesven           #+#    #+#             */
/*   Updated: 2019/02/21 15:26:16 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int		c(t_list *l, va_list va_l)
{
	int		c;

	c = va_arg(va_l, int);
	((t_format*)l->content)->output = ft_strnew(1);
	ft_memcpy(((t_format*)l->content)->output, &c, 1);
	if (((t_format*)l->content)->precision == -1)
		((t_format*)l->content)->precision = 0;
	((t_format*)l->content)->o_len = 1;
	return (0);
}
