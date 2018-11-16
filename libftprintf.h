/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:51:40 by tlesven           #+#    #+#             */
/*   Updated: 2013/12/19 00:30:27 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>

int		ft_printf(const char *format, ...);

int		ft_strlen(const char *s);
char	*ft_itoa(int n);
void	ft_putnbr(int i);
void	ft_putchar(char c);
void	ft_putstr(const char *s);

void	ft_arg_s(va_list ap, unsigned int i[2]);
void	ft_arg_di(va_list ap, unsigned int i[2]);
void	ft_arg_c(va_list ap, unsigned int i[2]);
void	ft_arg_p(va_list ap, unsigned int i[2]);

void	ft_arg_empty(unsigned int i[2], const char *s, va_list ap);

void	ft_arg_u(va_list ap, unsigned int i[2]);

void	ft_arg_o(va_list ap, unsigned int i[2]);

void	ft_arg_x(va_list ap, unsigned int i[2]);

#endif
