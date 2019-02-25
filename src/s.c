/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:59:23 by tlesven           #+#    #+#             */
/*   Updated: 2019/02/07 12:39:06 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int			s(t_list *l, va_list va_l)
{
	char	*s;

	s = va_arg(va_l, char*);
	if (s)
		((t_format*)l->content)->output = ft_strdup(s);
	else
		((t_format*)l->content)->output = ft_strdup("(null)");
	return (0);
}
