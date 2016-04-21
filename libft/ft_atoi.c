/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <rvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/18 01:47:05 by rvan-der          #+#    #+#             */
/*   Updated: 2015/10/18 01:50:05 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		number;

	i = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')\
			|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	sign = (str[i] == 45 ? -1 : 1);
	if ((str[i] == 45) || (str[i] == 43))
		i++;
	number = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		number *= 10;
		number += ((int)str[i] - 48);
		i++;
	}
	return (number * sign);
}
