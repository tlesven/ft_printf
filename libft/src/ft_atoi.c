/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 13:00:24 by tlesven           #+#    #+#             */
/*   Updated: 2018/11/19 20:04:20 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbr(int neg, char *str)
{
	long long	result;
	int			i;

	result = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) == 1)
	{
		if (result != 0)
			result = result * 10;
		result = (str[i] - '0') + result;
		i++;
	}
	return ((int)(neg * result));
}

int			ft_atoi(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\200' && str[i] != '\e')
	{
		if (ft_isalpha(str[i]))
			return (0);
		if ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
			i++;
		if (str[i] == '-')
			return (ft_nbr(-1, str + i));
		if (str[i] == '+' || ft_isdigit(str[i]) == 1)
			return (ft_nbr(1, str + i));
		i++;
	}
	return (0);
}
