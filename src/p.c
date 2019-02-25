/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:05:48 by tlesven           #+#    #+#             */
/*   Updated: 2019/02/01 17:39:06 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int			p(t_list *l, va_list va_l)
{
	unsigned long long	i;
	char				*tmp;
	int					tmplen;

	i = va_arg(va_l, unsigned long long);
	tmp = x_convert(i, 0);
	tmplen = ft_strlen(tmp);
	((t_format*)l->content)->output = ft_strnew(tmplen + 2);
	ft_memcpy(((t_format*)l->content)->output + 2, tmp, tmplen);
	ft_memcpy(((t_format*)l->content)->output, "0x", 2);
	ft_strdel(&tmp);
	return (0);
}
