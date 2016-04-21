/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <rvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 17:46:49 by rvan-der          #+#    #+#             */
/*   Updated: 2016/03/08 20:52:39 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new;

	if ((new = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if ((new->content = (void*)malloc(content_size)) == NULL)
		return (NULL);
	new->content = (content == NULL ?\
					NULL : ft_memcpy(new->content, content, content_size));
	new->content_size = (content == NULL ? 0 : content_size);
	return (new);
}
