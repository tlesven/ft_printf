/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 10:51:17 by tlesven           #+#    #+#             */
/*   Updated: 2019/02/24 15:37:15 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	number_precision(t_format *f)
{
	char	*newstr;
//	int		total_len;
	int		i;

//	total_len = f->precision + f->neg;
//	newstr = ft_strnew(total_len);
	newstr = ft_strnew(f->precision);
	i = 0;
	//i = f->neg;
	//if (f->neg)
		//newstr[0] = '-';
	//while (i - f->neg < (f->precision - f->o_len))
	while (i < (f->precision - f->o_len))
	{
		newstr[i] = '0';
		i++;
	}
	//ft_memcpy(newstr + i, f->output + f->neg, f->o_len);
	ft_memcpy(newstr + i, f->output, f->o_len);
	ft_strdel(&f->output);
	f->output = newstr;
	f->o_len = f->precision;
}

void		apply_precision(t_list *l)
{
	t_format	*f;
	char		*newstr;

	f = (t_format*)l->content;
	if (f->precision == 0 && f->type != C && !ft_strcmp(f->output, "0"))
	{
		//ft_putstr("coucou");
		ft_strdel(&f->output);
		f->output = ft_strdup("");
		f->o_len = 0;
		return ;
	}
	if (f->precision == 0 || f->type == F)
		return ;
	else if (f->type == C || f->type == P)
		ft_putstr("ERROR PRECISION\n");
	else if (f->type == S && f->o_len > f->precision)
	{
		if (!(newstr = ft_strnew(f->precision)))
			return ;
		ft_memcpy(newstr, f->output, f->precision);
		ft_strdel(&f->output);
		f->output = newstr;
		f->o_len = f->precision;
	}
	else if (f->type != S && f->o_len < f->precision)
		number_precision(f);
}
