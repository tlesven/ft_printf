/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:50:36 by tlesven           #+#    #+#             */
/*   Updated: 2019/02/21 15:01:50 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int g_options_mask[NB_TYPES] = {
	4, 4, 4, 30, 30, 7, 6, 7, 7, 31, 31 //CHANGER
};
/*
static void		space_option(t_format *f)
{
	int		len;
	char	*str;

	if (f->neg)
		return ;
	len = ft_strlen(f->output);
	str = ft_strnew(len + 1);
	ft_memcpy(str + 1, f->output, len);
	str[0] = ' ';
	ft_strdel(&f->output);
	f->output = str;
}
*/
/*static void		zero_option(t_format *f)
{
	char	*tmp;

	tmp = f->output;
	while (*tmp)
	{
		if (*tmp == ' ' || *tmp == '-')
			*tmp = '0';
		tmp++;
	}
	if (f->neg)
		f->output[0] = '-';
}*/
/*
static void		plus_option(t_format *f)
{
	char	*newstr;
	int		i;
	int		len;

	if (f->neg)
		return ;
	i = 0;
	while (!(ft_isdigit(f->output[i])))
		i++;
	if (i)
		f->output[i - 1] = '+';
	else
	{
		len = ft_strlen(f->output);
		newstr = ft_strnew(len + 1);
		ft_memcpy(newstr + 1, f->output, len);
		newstr[0] = '+';
		ft_strdel(&f->output);
		f->output = newstr;
	}
}
*/
void		put_sign(t_format *f, char *sign)
{
	char	*newstr;

	if (f->width <= f->o_len || (f->options & MINUS) == MINUS)
	{
		newstr = ft_strjoin(sign, f->output);
		ft_strdel(&f->output);
		f->output = newstr;
	}
	else if ((f->options & ZERO) == ZERO)
		f->output[0] = sign[0];
	else
		f->output[f->width - f->o_len - 1] = sign[0];
	f->o_len += 1;
}
/*
void			apply_options(t_list *l)
{
	int			mask;
	t_format	*f;

	f = (t_format*)l->content;
	mask = g_options_mask[f->type];
//	if ((f->options & ZERO + MINUS) == ZERO + MINUS)
//		f->options ^= ZERO;
//	if ((f->options & PLUS + SPACE) == PLUS + SPACE)
//		f->options ^= SPACE;
	if ((mask | f->options) != mask)
		ft_putstr("ERROR OPTIONS2\n");
//	if (f->options & ZERO)
//		zero_option(f);
	if (f->options & PLUS)
		plus_option(f);
	if (f->options & SPACE && f->type != MODULO)
		space_option(f);
	if (f->options & HASH)
		hash_options(f);
}
*/

void		minus_option(t_format *f)
{
	char	*newstr;

	if (f->width <= f->o_len)
		return ;
	if (!(newstr = ft_strnew(f->width)))
		return ;
	ft_memset(newstr, ' ', f->width);
	ft_memcpy(newstr, f->output, f->o_len);
	ft_strdel(&f->output);
	f->output = newstr;
}

void		apply_options(t_list *l)
{
	int			mask;
	t_format	*f;
	//char		sign;

	f = (t_format*)l->content;
	mask = g_options_mask[f->type];
	if ((mask | f->options) != mask)
		ft_putstr("ERROR OPTIONS2\n");
	if (f->neg)
		put_sign(f, "-");
	else if ((f->options & SPACE) == SPACE)
		put_sign(f, " ");
	else if ((f->options & PLUS) == PLUS)
		put_sign(f, "+");
	if (f->options & HASH)
		hash_options(f);
	if (f->options & MINUS)
		minus_option(f);
	if (f->width > f->o_len)
		f->o_len = f->width;
}


