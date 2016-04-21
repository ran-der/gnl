/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <rvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 14:34:18 by rvan-der          #+#    #+#             */
/*   Updated: 2016/03/02 16:14:28 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_find_base(char ch, char *base)
{
	int count;

	count = 0;
	while (base[count] != '\0')
	{
		if (ch == base[count])
			return (count);
		count++;
	}
	return (-1);
}

static int		ft_check_base(char *base)
{
	int	count;

	if (*base == '\0' || *(base + 1) == '\0')
		return (0);
	while (*base != '\0')
	{
		count = 1;
		while (base[count] != '\0')
		{
			if (*base == base[count] ||
					(base[count] == '-' || base[count] == '+'))
				return (0);
			count++;
		}
		base++;
	}
	return (1);
}

int				ft_atoi_base(char *str, char *base)
{
	int number;
	int base_nbr;
	int negatif;

	negatif = 1;
	if (!ft_check_base(base))
		return (0);
	if (*str == '-' || *str == '+')
	{
		negatif = (*str == '-') ? -1 : 1;
		str++;
	}
	base_nbr = (int)ft_strlen(base);
	number = 0;
	while (*str != '\0')
	{
		number *= base_nbr;
		if (ft_find_base(*str, base) == -1)
			return (0);
		number += (ft_find_base(*str, base));
		str++;
	}
	return (number * negatif);
}
