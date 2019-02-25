/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:44:51 by tlesven           #+#    #+#             */
/*   Updated: 2019/02/21 15:24:00 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_f_conv g_func[NB_TYPES][NB_LENGTH] = {
	{&c, NULL, NULL, NULL, NULL, NULL},
	{&s, NULL, NULL, NULL, NULL, NULL},
	{&p, NULL, NULL, NULL, NULL, NULL},
	{&d, &dhh, &dh, &dl, &dll, NULL},
	{&i, &ihh, &ih, &il, &ill, NULL},
	{&o, &ohh, &oh, &ol, &oll, NULL},
	{&u, &uhh, &uh, &ul, &ull, NULL},
	{&x, &xhh, &xh, &xl, &xll, NULL},
	{&maj_x, &Xhh, &Xh, &Xl, &Xll, NULL},
	{&f, NULL, NULL, NULL, NULL, &fL},
	{&modulo, &modulo, &modulo, &modulo, &modulo}
};

void	apply_width(t_list *l)
{
	int			len;
	t_format	*f;
	char		*newstr;
	char		setchar;

	f = (t_format*)l->content;
	len = ft_strlen(f->output);
	if (f->width < len || (f->options & MINUS) == MINUS)
		return ;
	if (!(newstr = ft_strnew(f->width)))
		return ;
	setchar = (f->options & ZERO) == ZERO ? '0' : ' ';
	ft_memset(newstr, setchar, f->width);
	/*if (f->options & MINUS) // A ENLEVERRRR
		ft_memcpy(newstr, f->output, len);
	else*/
	ft_memcpy(newstr + (f->width - len), f->output, len);
	ft_strdel(&f->output);
	f->output = newstr;
}

void	find_n_len(t_list *l)
{
	t_format *f;

	f = (t_format*)l->content;
	if (f->type == C)
		return ;
	//if (f->type != S)
		//f->neg = f->output[0] == '-' ? 1 : 0;
	//f->o_len = ft_strlen(f->output) - f->neg;
	f->o_len = ft_strlen(f->output);
}

void	dispatcher(t_list *l, va_list va_l)
{
	t_format *tmp_f;
	t_f_conv tmp_conv;

	while (l)
	{
		tmp_f = (t_format*)l->content;
		if (tmp_f->type >= 0 && tmp_f->type < 12)
		{
			tmp_conv = g_func[tmp_f->type][tmp_f->length];
			if (!tmp_conv)
				ft_putstr("ERROR NO FUNCTION\n");//Fonctions d'erreur;
			else
			{
				tmp_conv(l, va_l);
				find_n_len(l);
				apply_precision(l);
				apply_width(l);
				apply_options(l);
			}
		}
		else if (tmp_f->type == 12)
			ft_putstr("ERROR BAD FORMAT\n");
		l = l->next;
	}
}
