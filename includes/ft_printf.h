/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:41:38 by tlesven           #+#    #+#             */
/*   Updated: 2019/02/21 12:59:10 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define TYPES "cspdiouxXf%"

enum	e_options
{
	HASH = 1,
	ZERO = 2,
	MINUS = 4,
	PLUS = 8,
	SPACE = 16
};

enum	e_length
{
	BASE, HH, H, L, LL, MAJ_L, NB_LENGTH
};

enum	e_types
{
	C, S, P, D, I, O, U, X, MAJ_X, F, MODULO, NB_TYPES
};

typedef struct	s_format
{
	int			options;
	int			width;
	int			precision;
	int			length;
	int			type;
	char		*output;
	int			o_len;
	char		neg;
}				t_format;

typedef int		(*t_f_conv)(t_list*, va_list);

t_list			*parse(const char *format);
t_list			*new_formatlst(char *str);
void			print_formtlst(t_list *l); //A SUPPRIMER
void			free_formatlst(void *l, size_t size);

void			put_sign(t_format *f, char *sign);
void			apply_precision(t_list *l);
void			apply_options(t_list *l);
void			hash_options(t_format *f);
int				con(t_list *l, va_list va_l); //WUT?!
void			dispatcher(t_list *l, va_list va_l);

int				c(t_list *l, va_list va_l);

int				s(t_list *l, va_list va_l);

int				p(t_list *l, va_list va_l);

int				count_n(long long ll);
char			*d_convert(long long ll);

int				d(t_list *l, va_list va_l);
int				dhh(t_list *l, va_list va_l);
int				dh(t_list *l, va_list va_l);
int				dl(t_list *l, va_list va_l);
int				dll(t_list *l, va_list va_l);

int				i(t_list *l, va_list va_l);
int				ihh(t_list *l, va_list va_l);
int				ih(t_list *l, va_list va_l);
int				il(t_list *l, va_list va_l);
int				ill(t_list *l, va_list va_l);

char			*o_convert(unsigned long long n);

int				o(t_list *l, va_list va_l);
int				ohh(t_list *l, va_list va_l);
int				oh(t_list *l, va_list va_l);
int				ol(t_list *l, va_list va_l);
int				oll(t_list *l, va_list va_l);

char			*u_convert(unsigned long long n);

int				u(t_list *l, va_list va_l);
int				uhh(t_list *l, va_list va_l);
int				uh(t_list *l, va_list va_l);
int				ul(t_list *l, va_list va_l);
int				ull(t_list *l, va_list va_l);

char			*x_convert(unsigned long long n, int maj);

int				x(t_list *l, va_list va_l);
int				xhh(t_list *l, va_list va_l);
int				xh(t_list *l, va_list va_l);
int				xl(t_list *l, va_list va_l);
int				xll(t_list *l, va_list va_l);

int				maj_x(t_list *l, va_list va_l);
int				Xhh(t_list *l, va_list va_l);
int				Xh(t_list *l, va_list va_l);
int				Xl(t_list *l, va_list va_l);
int				Xll(t_list *l, va_list va_l);

char			*f_convert(long double n, int pre);

int				f(t_list *l, va_list va_l);
int				fL(t_list *l, va_list va_l);

int				modulo(t_list *l, va_list va_l);

#endif
