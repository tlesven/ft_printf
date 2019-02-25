/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:45:48 by tlesven           #+#    #+#             */
/*   Updated: 2019/02/07 17:01:19 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // A ENLEVR
#include "ft_printf.h"
#include "libft.h"

t_list		*new_formatlst(char *str)
{
	t_format l;

	l.options = 0;
	l.width = 0;
	l.precision = -1;
	l.length = 0;
	l.type = -1;
	l.output = str;
	l.o_len = str != NULL ? ft_strlen(str) : 0;
	l.neg = 0;
	return (ft_lstnew(&l, sizeof(t_format)));
}

void		print_formtlst(t_list *l) //A SUPPRIMER
{
	t_format	*c;

	c = (t_format*)l->content;
	printf("OPTIONS: %d\n", c->options);
	printf("WIDTH: %d\n", c->width);
	printf("PRECISION: %d\n", c->precision);
	printf("LENGTH: %d\n", c->length);
	printf("TYPE: %d\n", c->type);
	printf("OUTPUP: %s\n\n", c->output);
	printf("O_LEN: %d\n\n", c->o_len);
	printf("NEG: %d\n\n", c->neg);
}

void		free_formatlst(void *l, size_t size)
{
	t_format	*f;

	f = (t_format*)l;
	if (f && f->output)
		ft_strdel(&f->output);
	ft_memdel((void**)&l);
	(void)size;
}
