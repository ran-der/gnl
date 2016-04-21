/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <rvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 15:24:11 by rvan-der          #+#    #+#             */
/*   Updated: 2016/03/02 20:21:55 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_copytrim(char const *s, int space1, int space2)
{
	int		i;
	int		j;
	char	*new;

	if ((new = (char*)malloc(sizeof(char) * (ft_strlen(s) - space1\
		- space2 + 1))) == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < (int)(ft_strlen(s) - space2))
		if ((i >= space1 && space1 != 0) || space1 == 0)
			new[j++] = s[i];
	new[j] = '\0';
	return (new);
}

static char	*ft_zerostr(void)
{
	char	*new;

	if ((new = (char*)malloc(sizeof(char))) == NULL)
		return (NULL);
	new[0] = '\0';
	return (new);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		space1;
	int		space2;

	space1 = 0;
	space2 = 0;
	i = -1;
	while (s[++i] == ' ' || s[i] == '\n' || s[i] == '\t')
		space1++;
	if (s[i] == '\0')
		return (ft_zerostr());
	while (s[i] != '\0')
		i++;
	while (s[--i] == ' ' || s[i] == '\n' || s[i] == '\t')
		space2++;
	return (ft_copytrim(s, space1, space2));
}
