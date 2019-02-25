/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 19:28:34 by tlesven           #+#    #+#             */
/*   Updated: 2018/12/14 12:03:28 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_splitnum(char const *s, char c)
{
	unsigned int	i;
	unsigned int	split;
	unsigned int	first;

	i = 0;
	split = 0;
	first = 0;
	if (s[0] != c && *s)
		first = 1;
	while (s[i])
	{
		while (s[i] == c && s[i])
		{
			i++;
			if (s[i] != c && s[i])
				split++;
		}
		if (s[i])
			i++;
	}
	return (split + first);
}

static char const	*ft_nextsplit(char const *s, char c)
{
	while (*s == c && *s)
		s++;
	return (s);
}

static int			ft_tilnxtsplit(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char		*ft_filltab(char const *s, char *tab, char c)
{
	unsigned int	i;
	unsigned int	split;

	i = 0;
	split = ft_tilnxtsplit(s, c);
	tab = ft_strnew(split);
	while (*s != c && *s)
		tab[i++] = *(s++);
	tab[i] = '\0';
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	unsigned int	split;
	char			**tab;

	i = 0;
	if (!s)
		return (NULL);
	split = ft_splitnum(s, c);
	tab = (char **)ft_memalloc(sizeof(char *) * (split + 1));
	if (!(tab))
		return (NULL);
	if (!*s)
		tab[i] = (char *)ft_memalloc(1);
	while (split--)
	{
		s = ft_nextsplit(s, c);
		tab[i] = ft_filltab(s, tab[i], c);
		s = s + ft_tilnxtsplit(s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
