/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:49:05 by tlesven           #+#    #+#             */
/*   Updated: 2019/02/24 18:07:50 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		get_options(const char s, t_format *l)
{
	if (s == '#')
		l->options |= HASH;
	else if (s == '0')
		l->options |= ZERO;
	else if (s == '-')
		l->options |= MINUS;
	else if (s == '+')
		l->options |= PLUS;
	else if (s == ' ')
		l->options |= SPACE;
	return ((int)ft_strchr("#0-+ ", s));
}

void		get_width(const char *s, t_format *l)
{
	if (ft_isdigit(*s))
		l->width = ft_atoi((char*)s);
}

void		get_precision(const char *s, t_format *l)
{
	if (ft_isdigit(*s))
		l->precision = ft_atoi((char*)s);
}

int		get_length(const char *s, t_format *l)
{
	int		len;

	len = 0;
	while (len < 2 && (s[len] == 'l' || s[len] == 'h' || s[len] == 'L'))
		len++;
	if (!ft_strncmp("hh", s, 2))
		l->length = HH;
	else if (!ft_strncmp("ll", s, 2))
		l->length = LL;
	else if (!ft_strncmp("h", s, 1))
		l->length = H;
	else if (!ft_strncmp("l", s, 1))
		l->length = L;
	else if (!ft_strncmp("L", s, 1))
		l->length = MAJ_L;
	return (len);
}

void	get_type(const char s, t_format *l)
{
	int		i;

	i = 0;
	while (i <= NB_TYPES)
	{
		if (TYPES[i] == s)
			break ;
		i++;
	}
	l->type = i;
}

void	ignored_flag(t_format *f)
{
	if (((f->options & ZERO + MINUS) == ZERO + MINUS) 
			|| (((f->options & ZERO) == ZERO) && (f->precision > 0)))
		f->options ^= ZERO;
	if ((f->options & PLUS + SPACE) == PLUS + SPACE)
		f->options ^= SPACE;
	if (f->type == MODULO && ((f->options & SPACE) == SPACE))
		f->options ^= SPACE;
}

t_list	*format_parsing(const char *s, int *i)
{
	t_list		*new;

	new = new_formatlst(NULL);
	(*i)++;
	while (get_options(s[*i], ((t_format*)new->content)))
		(*i)++;
	get_width(&s[*i], ((t_format*)new->content));
	while (ft_isdigit(s[*i]))
		(*i)++;
	if (s[*i] == '.')
	{
		((t_format*)new->content)->precision = 0;
		(*i)++;
	}
	get_precision(&s[*i], ((t_format*)new->content));
	while (ft_isdigit(s[*i]))
		(*i)++;
	*i += get_length(&s[*i], ((t_format*)new->content));
	get_type(s[*i], ((t_format*)new->content));
	//(*i)++;
	ignored_flag((t_format*)new->content);
	return (new);
}

t_list	*parse(const char *format)
{
	t_list	*l;
	int		format_len;
	int		i;
	int		j;

	l = NULL;
	i = 0;
	j = 0;
	format_len = ft_strlen(format);
	while (i < format_len)
	{
		if (format[i] == '%')
		{
			ft_lstaddtoend(&l, new_formatlst(ft_strndup(format + j, i - j)));
			ft_lstaddtoend(&l, format_parsing(format, &i));
			j = i + 1;
		}
		i++;
	}
	ft_lstaddtoend(&l, new_formatlst(ft_strndup(format + j, i - j)));
	return (l);
}
