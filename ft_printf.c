/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:48:06 by tlesven           #+#    #+#             */
/*   Updated: 2013/12/19 05:45:40 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_count_arg(const char *s)
{
	int		arg;
	int		i;

	arg = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] != '%')
			arg++;
		i++;
	}
	return (arg);
}

static void		ft_putarg(va_list ap, const char *s, unsigned int i[2])
{
	if (s[i[0] + 1] == 's')
		ft_arg_s(ap, i);
	else if (s[i[0] + 1] == 'c')
		ft_arg_c(ap, i);
	else if (s[i[0] + 1] == 'd' || s[i[0] + 1] == 'i')
		ft_arg_di(ap, i);
	else if (s[i[0] + 1] == 'u')
		ft_arg_u(ap, i);
	else if (s[i[0] + 1] == 'o')
		ft_arg_o(ap, i);
	else if (s[i[0] + 1] == 'x')
		ft_arg_x(ap, i);
	else if (s[i[0] + 1] == 'p')
		ft_arg_p(ap, i);
	else if (s[i[0] + 1] == '\0')
		i[0]++;
	else
		ft_arg_empty(i, s, ap);
}

int				ft_printf(const char *format, ...)
{
	va_list			ap;
	unsigned int	arg;
	unsigned int	i[2] = {0, 0};

	arg = ft_count_arg(format);
	va_start(ap, format);
	while (format[i[0]] != '\0')
	{
		if (format[i[0]] == '%')
			ft_putarg(ap, format, i);
		else if (format[i[0]] != '\0')
		{
			ft_putchar(format[i[0]]);
			i[0]++;
			i[1]++;
		}
	}
	return (i[1]);
}
