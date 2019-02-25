/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 12:34:33 by tlesven           #+#    #+#             */
/*   Updated: 2019/02/21 15:26:57 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

/*static int		print_return_len(char const *s)
{
	int		len;

	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}*/

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_list		*l;
	t_list		*start;
	int			total_len;
	t_format	*f;

	va_start(ap, format);
	total_len = 0;
	start = parse(format);
	l = start;
	dispatcher(l, ap);
	while (l)
	{
		f = (t_format*)l->content;
		if (f->output)
		{
			write(1, f->output, f->o_len);
			total_len += f->o_len;
		}
		l = l->next;
	}
	va_end(ap);
	ft_lstdel(&start, &free_formatlst);
	return (total_len);
}

#include <stdio.h> // a ENLEVER
int		main2(void)
{
	/*printf("1:%#x\n", 0); TEST RESULT
	printf("2:%#08x\n", 42);
	printf("3:%#08x\n", -42);
	printf("4:%-#6o\n", 2500);
	printf("5:%o\n", 0);
	printf("6:%0+5d\n", 42);
	printf("7:%-10.5d\n", 4242);
	printf("8:%-+10.5d\n", 4242);
	printf("9:%03.2d\n", 0);
	printf("10:%0.2d\n",1);
	
	ft_printf("1:%#x\n", 0);
	ft_printf("2:%#08x\n", 42);
	ft_printf("3:%#08x\n", -42);
	ft_printf("4:%-#6o\n", 2500);
	ft_printf("5:%o\n", 0);
	ft_printf("6:%0+5d\n", 42);
	ft_printf("7:%-10.5d\n", 4242);
	ft_printf("8:%-+10.5d\n", 4242);
	ft_printf("9:%03.2d\n", 0);
	ft_printf("10:%0.2d\n\n",1); */
/*
	ft_printf("D:%d\n", -42);
	ft_printf("F:%f\n", -42.0);
	ft_printf("O:%o\n", -42);
	ft_printf("U:%u\n", -42);
	ft_printf("X:%x\n\n", -42);
*/
	/*ft_printf("PRECISIOND:%.20d\n", -42);
	ft_printf("PRECISIONF:%.10f\n", -42.0);
	ft_printf("PRECISIONO:%.20o\n", -42);
	ft_printf("PRECISIONU:%.20u\n", -42);
	ft_printf("PRECISIONX:%.20x\n\n", -42);*/
/*
	ft_printf("WIDTHD: %10d\n", 42);
	ft_printf("WIDTH0D: %010d\n", 42);
	ft_printf("WIDTH0-D: %-010d\n", 42);
	ft_printf("PRECISIOND+WIDTH+SPACE:%010d\n", -42);
	ft_printf("PRECISIOND+WIDTH+SPACE:% 010d\n", 42);
	ft_printf("PRECISIOND+WIDTH+SPACE:%+010d\n", 42);
	ft_printf("PRECISIOND+WIDTH+SPACE:%10d\n", -42);
	ft_printf("PRECISIOND+WIDTH+SPACE:% 10d\n", 42);
	ft_printf("PRECISIOND+WIDTH+SPACE:%+10d\n", 42);
*/

	/*
	ft_printf("TEST HASH F: %.f\n", 42.0);
	ft_printf("TEST HASH F: %#.f\n", 42.0);
	ft_printf("TEST HASH F: %10.f\n", 42.0);
	ft_printf("TEST HASH F: %#10.f\n\n", 42.0);
	printf("TEST HASH F: %.f\n", 42.0);
	printf("TEST HASH F: %#.f\n", 42.0);
	printf("TEST HASH F: %10.f\n", 42.0);
	printf("TEST HASH F: %#10.f\n", 42.0);
	*/
	/*
	ft_printf("TEST HASH X: %.x\n", 42);
	ft_printf("TEST HASH X: %#.x\n", 42);
	ft_printf("TEST HASH X: %#3x\n", 42);
	ft_printf("TEST HASH X: %#03x\n", 42);
	ft_printf("TEST HASH X: %10x\n", 42);
	ft_printf("TEST HASH X: %#10x\n", 42);
	ft_printf("TEST HASH X: %010x\n", 42);
	ft_printf("TEST HASH X: %#010x\n\n", 42);

	printf("TEST HASH X: %.x\n", 42);
	printf("TEST HASH X: %#.x\n", 42);
	printf("TEST HASH X: %#3x\n", 42);
	printf("TEST HASH X: %#03x\n", 42);
	printf("TEST HASH X: %10x\n", 42);
	printf("TEST HASH X: %#10x\n", 42);
	printf("TEST HASH X: %010x\n", 42);
	printf("TEST HASH X: %#010x\n", 42);
	*/
/*
	ft_printf("TEST HASH X: %.o\n", 42);
	ft_printf("TEST HASH X: %#.o\n", 42);
	ft_printf("TEST HASH X: %#3o\n", 42);
	ft_printf("TEST HASH X: %#03o\n", 42);
	ft_printf("TEST HASH X: %10o\n", 42);
	ft_printf("TEST HASH X: %#10o\n", 42);
	ft_printf("TEST HASH X: %010o\n", 42);
	ft_printf("TEST HASH X: %#010o\n\n", 42);

	printf("TEST HASH X: %.o\n", 42);
	printf("TEST HASH X: %#.o\n", 42);
	printf("TEST HASH X: %#3o\n", 42);
	printf("TEST HASH X: %#03o\n", 42);
	printf("TEST HASH X: %10o\n", 42);
	printf("TEST HASH X: %#10o\n", 42);
	printf("TEST HASH X: %010o\n", 42);
	printf("TEST HASH X: %#010o\n", 42);
	*/
	/*
	ft_printf("TEST MINUS X: %-10d\n", 42);
	ft_printf("TEST MINUS X: % -10d\n", 42);
	ft_printf("TEST MINUS X: %+-10d\n", 42);
	ft_printf("TEST MINUS X: %-10d\n", 42);
	ft_printf("TEST MINUS X: %-#10x\n\n", 42);

	printf("TEST MINUS X: %-10d\n", 42);
	printf("TEST MINUS X: % -10d\n", 42);
	printf("TEST MINUS X: %+-10d\n", 42);
	printf("TEST MINUS X: %-10d\n", 42);
	printf("TEST MINUS X: %-#10x\n\n", 42);
	*/
	ft_printf("CHAR:%c\n", 0);
	printf("CHAR:%c\n", 0);
/*	
	printf("WIDTHD: %10d\n", 42);
	printf("WIDTH0D: %010d\n", 42);
	printf("PRECISIOND+WIDTHD: %- 10.5d\n", 42);

	printf("PRECISIOND+WIDTH+SPACE:%010d\n", -42);
	printf("PRECISIOND+WIDTH+SPACE:% 010d\n", 42);
	printf("PRECISIOND+WIDTH+SPACE:%+010d\n", 42);
	printf("PRECISIOND+WIDTH+SPACE:%10d\n", -42);
	printf("PRECISIOND+WIDTH+SPACE:% 10d\n", 42);
	printf("PRECISIOND+WIDTH+SPACE:%+10d\n", 42);
*/
	/*printf("PRECISIOND:%.20d\n", -42);
	printf("PRECISIONF:%.10f\n", -42.0);
	printf("PRECISIONO:%.20o\n", -42);
	printf("PRECISIONU:%.20u\n", -42);
	printf("PRECISIONX:%.20x\n", -42);

	printf("TEST00:%15.12d\n", 42);
	printf("TEST01:%15.12d\n", 42);
	printf("TEST02:%15.12d\n", -42);
	printf("TEST03:%-15.12d\n", -42);
	printf("TEST04:%+15d\n", 42);
	printf("TEST04:%+015d\n", 42);
	printf("TEST05:%015.1d\n", -42);
	printf("TEST06:%#015x\n", 42);
	printf("TEST06:%#015x\n", 42);
	*/
	return (0);
}
