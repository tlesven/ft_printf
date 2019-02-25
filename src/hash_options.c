/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:21:23 by tlesven           #+#    #+#             */
/*   Updated: 2019/02/24 16:19:39 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		hash_f(t_format *f)
{
	char	*tmp;

	if (f->width > f->o_len)
	{
		ft_memmove((f->output + (f->width - f->o_len - 1)), 
				(f->output + (f->width - f->o_len)), f->o_len);
		f->output[f->width - 1] = '.';
	}
	else
	{
		tmp = ft_strjoin(f->output, ".");
		ft_strdel(&f->output);
		f->output = tmp;
	}
	f->o_len += 1;
}

/*static void put_sign(t_format *f, char *sign)
{
	char	*newstr;
	int		size_sign;

	size_sign = ft_strlen(sign);
	if (width - o_len >= size_sign)
	{
		newstr = ft_strjoin(sign, f->output);
		ft_strdel(&f->output);
		f->output = newstr;
	}
}*/

/*
void		hash_f(t_format *f)
{
	char	*tmp;

	tmp = f->output;
	while (*tmp)
	{
		if (*tmp == '.')
			return ;
		tmp++;
	}
	tmp = ft_strjoin(f->output, ".");
	ft_strdel(&f->output);
	f->output = tmp;
}
*/
/*
static void		hash_o(t_format *f)
{
	int		len;
	char	*newstr;
	int		i;

	len = ft_strlen(f->output);
	i = len;
	while (i >= 0 && f->output[i] != ' ')
		i--;
	if (i >= 0)
	{
		f->output[i] = '0';
		return ;
	}
	newstr = ft_strjoin("0", f->output);
	ft_strdel(&f->output);
	f->output = newstr;
}
*/
/*
void		hash_maj_x(t_format *f)
{
	int		len;
	char	*newstr;
	int		i;

	len = ft_strlen(f->output);
	i = len;
	while (i >= 0 && f->output[i] != ' ')
		i--;
	if (i >= 1)
	{
		f->output[i] = 'X';
		f->output[i - 1] = '0';
		return ;
	}
	if (i >= 0)
	{
		f->output[0] = 'X';
		newstr = ft_strjoin("0", f->output);
	}
	else
		newstr = ft_strjoin("0X", f->output);
	ft_strdel(&f->output);
	f->output = newstr;
}
*/
void		hash_x(t_format *f, char *sign)
{
	char	*newstr;

	if (!ft_strcmp(f->output, "0") || !ft_strcmp(f->output, ""))
			return ;
	if (f->width - f->o_len < 1 || (f->options & MINUS) == MINUS)
	{
		newstr = ft_strjoin(sign, f->output);
		ft_strdel(&f->output);
		f->output = newstr;
	}
	else if (f->width - f->o_len == 1)
	{
		f->output[0] = sign[1];
		newstr = ft_strjoin("0", f->output);
		ft_strdel(&f->output);
		f->output = newstr;
	}
	else if ((f->options & ZERO) == ZERO)
		ft_memcpy(f->output, sign, 2);
	else
		ft_memcpy(f->output + (f->width - f->o_len - 2), sign, 2);
	f->o_len += 2;
}
/*
void		hash_maj_x(t_format *f) // A REIRERE
{
	char	*newstr;

	if (f->width - f->o_len < 1 || (f->options & MINUS) == MINUS)
	{
		newstr = ft_strjoin("0X", f->output);
		ft_strdel(&f->output);
		f->output = newstr;
	}
	else if (f->width - f->o_len == 1)
	{
		f->output[0] = 'X';
		newstr = ft_strjoin("0", f->output);
		ft_strdel(&f->output);
		f->output = newstr;
	}
	else if ((f->options & ZERO) == ZERO)
		ft_memcpy(f->output, "0X", 2);
	else
		ft_memcpy(f->output + (f->width - f->o_len - 2), "0X", 2);
	f->o_len += 2;
}
*/
/*
void		hash_x(t_format *f)
{
	int		len;
	char	*newstr;
	int		i;

	len = ft_strlen(f->output);
	i = len;
	while (i >= 0 && f->output[i] != ' ')
		i--;
	if (i >= 1)
	{
		f->output[i] = 'x';
		f->output[i - 1] = '0';
		return ;
	}
	if (i >= 0)
	{
		f->output[0] = 'x';
		newstr = ft_strjoin("0", f->output);
	}
	else
		newstr = ft_strjoin("0x", f->output);
	ft_strdel(&f->output);
	f->output = newstr;
}
*/
void		hash_options(t_format *f)
{
	if (f->type == X)
		hash_x(f, "0x");
	else if (f->type == MAJ_X)
		hash_x(f, "0X");
	else if (f->type == O)
		put_sign(f, "0");
	else if (f->type == F)
		hash_f(f);
}
