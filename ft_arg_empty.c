/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_empty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 23:47:55 by tlesven           #+#    #+#             */
/*   Updated: 2013/12/19 05:18:56 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_mod(unsigned int i[2], int j, const char *s)
{
	ft_putchar('%');
	i[0] = j;
	i[1]++;
	if (s[j + 1] != '\0')
		i[0]++;
}

static void	ft_di(unsigned int i[2], int j, va_list ap)
{
	ft_putchar(' ');
	ft_arg_di(ap, i);
	i[1]++;
	i[0] = j + 1;
}

void		ft_arg_empty(unsigned int i[2], const char *s, va_list ap)
{
	int		j;

	j = i[0] + 1;
	while (s[j] != '\0')
	{
		if (s[j] == 'd' || s[j] == 'i')
		{
			ft_di(i, j, ap);
			break ;
		}
		else if (s[j] == '%')
		{
			ft_mod(i, j, s);
			break ;
		}
		else if (s[j] != ' ')
		{
			ft_putchar(s[i[0] + 1]);
			i[0] += 2;
			i[1]++;
			break ;
		}
		j++;
	}
}
