/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <rvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 18:59:00 by rvan-der          #+#    #+#             */
/*   Updated: 2016/03/03 13:50:09 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list		*tmp;

	if (lst != NULL)
	{
		tmp = lst;
		while (tmp != NULL)
		{
			(f)(tmp);
			tmp = tmp->next;
		}
	}
}
