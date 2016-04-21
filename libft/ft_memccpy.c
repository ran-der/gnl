/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <rvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 15:24:11 by rvan-der          #+#    #+#             */
/*   Updated: 2016/03/03 15:40:48 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*tmp_src;
	unsigned char	*tmp_dest;
	size_t			i;

	tmp_src = (unsigned char*)src;
	tmp_dest = (unsigned char*)dst;
	i = 0;
	while (i < n && tmp_src[i] != (unsigned char)c)
	{
		tmp_dest[i] = tmp_src[i];
		i++;
	}
	if (tmp_src[i] == (unsigned char)c)
	{
		tmp_dest[i] = (unsigned char)c;
		return (dst + i + 1);
	}
	return (NULL);
}
