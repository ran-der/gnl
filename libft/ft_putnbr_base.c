/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <rvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 01:14:36 by rvan-der          #+#    #+#             */
/*   Updated: 2016/03/02 19:12:29 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(int nbr, char *base)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= (int)ft_strlen(base))
	{
		ft_putnbr_base(nbr / (int)ft_strlen(base), base);
		ft_putnbr_base(nbr % (int)ft_strlen(base), base);
	}
	else
		ft_putchar(base[nbr]);
}
