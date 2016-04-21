/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <rvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 18:55:07 by rvan-der          #+#    #+#             */
/*   Updated: 2016/03/04 16:19:31 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		find_range(int n)
{
	int		range;

	range = (n <= 0 ? 1 : 0);
	n = (n < 0 ? -n : n);
	while (n != 0)
	{
		range++;
		n = n / 10;
	}
	return (range);
}

static char		*min_int(void)
{
	char	*str;

	if ((str = (char*)malloc(sizeof(char) * 12)) == NULL)
		return (NULL);
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	return (str);
}

char			*ft_itoa(int n)
{
	int		i;
	int		range;
	char	*nbr;

	if (n < -2147483647)
		return (min_int());
	range = find_range(n);
	if ((nbr = (char*)malloc(sizeof(char) * (range + 1))) == NULL)
		return (NULL);
	i = range - 1;
	if (n <= 0)
		nbr[0] = (n < 0 ? '-' : '0');
	n = (n < 0 ? -n : n);
	while (n != 0)
	{
		nbr[i--] = '0' + (n % 10);
		n = n / 10;
	}
	nbr[range] = '\0';
	return (nbr);
}
