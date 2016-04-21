/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <rvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:28:20 by rvan-der          #+#    #+#             */
/*   Updated: 2016/03/04 17:29:48 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*res;
	t_list		*tmpnew;
	t_list		*tmplst;

	if (lst == NULL)
		return (NULL);
	tmplst = lst->next;
	res = (f)(lst);
	if ((tmpnew = ft_lstnew(res->content, res->content_size)) == NULL)
		return (NULL);
	new = tmpnew;
	while (tmplst != NULL)
	{
		res = (f)(tmplst);
		if ((tmpnew->next = ft_lstnew(res->content, res->content_size)) ==\
				NULL)
			return (NULL);
		tmplst = tmplst->next;
		tmpnew = tmpnew->next;
	}
	return (new);
}
